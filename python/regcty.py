# -*- coding: iso-8859-15 -*-

import re


fh_post_codes = open("post_codes_germany.txt")
PLZ = {}
for line in fh_post_codes:
    (post_code, city, rest) = line.split(",",2)
    PLZ[city.strip("\"")] =  post_code


fh_largest_cities = open("largest_cities_germany.txt")

for line in fh_largest_cities:
    re_obj = re.search(r"^[0-9]{1,2}\.\s+([\wÄÖÜäöüß\s]+\w)\s+[0-9]",line)
    city = re_obj.group(1)
    print(city, PLZ[city])
