# Random GeoJSON builder
Fast random geographic coordinates (Lat/Lon) generator (Output stored in GeoJSON format).

Software library developed with C but Python accessible through Cython.

This library is for testing purposes.

Remarks:
This algorithm (Pseudo-random geographic latitude/longitude generator)
is developed using DRAND48 C function. DRAND48 function generates pseudo-random
numbers (uniformly distributed) using the linear congruential algorithm and
48-bit integer arithmetic. I have choosen a linear congruential algorithm for
this function because is fast and require minimal memory. For a better
pseudo-randomness should be used other algorithms.


## Usage
After compiling library...
```bash
$ make
```
...you can run generator from Python:
```python
from pyrand_geojson import randGeojson

def test(nfeats, gjs_flname):
    randGeojson(nfeats, 0, gjs_flname)

def main():
    gjs_flname= "/tmp/rand_corrd.geojson"
    nfeats = 100000
    test(nfeats, gjs_flname)

if __name__ == '__main__':
  main()
```

## Testing
You can test generator from Python with
```bash
$ python test.py
```

## About author
Developed by Cayetano Benavent.
GIS Analyst at Geographica.

http://www.geographica.gs

## License
This program is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 2 of the License, or
(at your option) any later version.
