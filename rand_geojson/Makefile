# -*- coding: utf-8 -*-
#
#  Author: Cayetano Benavent, 2015.
#  cayetano.Benavent@geographica.gs
#
#  This program is free software; you can redistribute it and/or modify
#  it under the terms of the GNU General Public License as published by
#  the Free Software Foundation; either version 2 of the License, or
#  (at your option) any later version.
#
#  This program is distributed in the hope that it will be useful,
#  but WITHOUT ANY WARRANTY; without even the implied warranty of
#  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#  GNU General Public License for more details.
#
#  You should have received a copy of the GNU General Public License
#  along with this program; if not, write to the Free Software
#  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
#  MA 02110-1301, USA.
#



CC=gcc
CFLAGS=-g -O2 -fpic -c -Wall
LDFLAGS=-l json
SOURCES=rand_geojson.c
OBJECTS=rand_geojson.o
INCLUDES=
# VERBOSE=-v

build: $(OBFILESJECTS)
	$(CC) $(CFLAGS) $(SOURCES) -o $(OBJECTS) $(INCLUDES) $(LDFLAGS) $(VERBOSE)
