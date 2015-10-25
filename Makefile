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
SUBDIR=rand_geojson
CYTHONFILE=pyrand_geojson.pyx
CSRCFILE=pyrand_geojson.c
OBJFILE=pyrand_geojson.o
SHAREDFILES=pyrand_geojson.so rand_geojson/rand_geojson.o pyrand_geojson.o
LDFLAGS=-l json

all:
	$(MAKE) -C $(SUBDIR)
	cython $(CYTHONFILE)
	$(CC) -Wall -g -O2 -fpic -c $(CSRCFILE) -o $(OBJFILE) `python-config --cflags`
	$(CC) -Wall -shared -o $(SHAREDFILES) `python-config --libs` $(LDFLAGS)

clean:
	rm $(SHAREDFILES) $(CSRCFILE)
