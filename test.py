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


from pyrand_geojson import randGeojson


gjs_flname01= "/tmp/rand_corrd_01.geojson"
gjs_flname02 = "/tmp/rand_corrd_02.geojson"
gjs_flname03 = "/tmp/rand_corrd_03.geojson"
gjs_flname04 = "/tmp/rand_corrd_04.geojson"


def test01():
    print("## Start test01: create 10 features GeoJSON and print Lat/Lon outputs\n")
    randGeojson(10, 1, gjs_flname01)
    print("## Test01 successfully!\n")

def test02():
    print("## Start test02: create 1,000 features GeoJSON.\n")
    randGeojson(1000, 0, gjs_flname02)
    print("## Test02 successfully!\n")

def test03():
    print("## Start test03: create 100,000 features GeoJSON.\n")
    randGeojson(100000, 0, gjs_flname03)
    print("## Test03 successfully!\n")

def test04():
    print("## Start test04: create 1,000,000 features GeoJSON.\n")
    randGeojson(1000001, 0, gjs_flname04)
    print("## Test04 successfully!\n")


def main():
    test01()
    test02()
    test03()
    test04()

if __name__ == '__main__':
  main()
