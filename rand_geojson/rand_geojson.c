/*
 * Fast random geographic coordinates (Lat/Lon) generator.
 * Store output in GeoJSON format.
 *
 * Cayetano Benavent, 2015.
 * cayetano.Benavent@geographica.gs
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 *
 */



#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <json/json.h>
#include "rand_geojson.h"


#define MAX_FEAT_SIZE 1000000

FILE *fgeojsn;


//------------------------------------------------------------------------------
// Counting time of execution
//------------------------------------------------------------------------------
void printExecTime ( clock_t start, clock_t stop ) {

    double elapsed = (double)(stop - start) / CLOCKS_PER_SEC;

    printf("Time elapsed: %f s\n\n", elapsed);

}

//------------------------------------------------------------------------------
// GeoJSON feature builder
//------------------------------------------------------------------------------
void geoJsonFeatBuilder( float lat, float lon, int id, char notlast_feat ) {

    json_object *jgeom = json_object_new_object();
    json_object *jpointobj = json_object_new_object();
    json_object *jprops = json_object_new_object();

    json_object *jpttype = json_object_new_string( "Point" );
    json_object *jfttype = json_object_new_string( "Feature" );
    json_object *jcoords = json_object_new_array();
    json_object *jlat = json_object_new_double( lat );
    json_object *jlon = json_object_new_double( lon );
    json_object *jid = json_object_new_int( id );

    json_object_array_add( jcoords, jlon );
    json_object_array_add( jcoords, jlat);

    json_object_object_add( jpointobj,"coordinates", jcoords );
    json_object_object_add( jpointobj,"type", jpttype );
    json_object_object_add( jgeom,"type", jfttype );
    json_object_object_add( jgeom,"properties", jprops );
    json_object_object_add( jgeom,"geometry", jpointobj );
    json_object_object_add( jprops,"id", jid );

    fprintf(fgeojsn, "%s%c\n", json_object_to_json_string( jgeom ), notlast_feat);

}

//------------------------------------------------------------------------------
// Pseudo-random geographic coordinates (latitude/longitude) generator.
//
// This algorithm are developed using DRAND48 C function.
// DRAND48 function generate pseudo-random numbers (uniformly distributed)
// using the linear congruential algorithm and 48-bit integer arithmetic.
//
// I have choosen a linear congruential algorithm for this function because
// is fast and require minimal memory. For a better pseudo-randomness should
// be used other algorithms.
//
//------------------------------------------------------------------------------
void randCoordinates ( int arr_size, int prnt_rslts, int llon, int llat, int ulon, int ulat ) {

    clock_t start = clock();

    srand48( (unsigned int)time(NULL) );

    int i;
    int id;
    float lat = 0.0;
    float lon = 0.0;
    char notlast_feat = ',';

    for ( i=0; i<(arr_size); i++ ){

        id = i + 1;
        lat = drand48() * ( ulat - (llat) ) + (llat);
        lon = drand48() * ( ulon - (llon) ) + (llon);

        if ( i == arr_size ) {
            notlast_feat = ' ';
        }

        geoJsonFeatBuilder( lat, lon,  id, notlast_feat );

        if ( prnt_rslts == 1 ) {
            printf("%d : %f, %f\n", id, lat, lon);
        }

    }

    clock_t stop01 = clock();

    printf("Geojson data creation - ");
    printExecTime(start, stop01);

}

//------------------------------------------------------------------------------
// GeoJSON main builder function
//------------------------------------------------------------------------------
int geoJsonMainBuilder( int max_feat_size, int prnt_rslts , const char *gjs_flname ) {

    if ( max_feat_size > MAX_FEAT_SIZE ) {
        printf("Are you crazy? This file will be too big... Exiting\n\n");
        printf("Limited number of GeoJSON features to 1,000,000\n\n");
        exit(0);
    }

    fgeojsn = fopen(gjs_flname, "w");

    fprintf(fgeojsn, "{\"type\":\"FeatureCollection\", \"features\":[\n");

    int llon = -180;
    int llat = -90;
    int ulon = 180;
    int ulat = 90;

    if ( max_feat_size > 0 && prnt_rslts == 0 ) {

        randCoordinates( max_feat_size, prnt_rslts, llon, llat, ulon, ulat);
    }
    else if ( max_feat_size > 0 && prnt_rslts == 1 ) {

        printf("id: lat, lon\n");
        randCoordinates( max_feat_size, prnt_rslts , llon, llat, ulon, ulat);
    }
    else{
        printf("Not enough features to build a geojson...\n");
    }

    fprintf(fgeojsn, "]}");

    fclose(fgeojsn);

    return 0;
}
