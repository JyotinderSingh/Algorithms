-- https://www.hackerrank.com/challenges/japan-population/problem
select sum(population)
from city
where countrycode = "JPN"