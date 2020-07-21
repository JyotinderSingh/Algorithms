-- https://www.hackerrank.com/challenges/asian-population/problem
select sum(city.population)
from city join country on city.countrycode = country.code
where country.continent = "Asia"