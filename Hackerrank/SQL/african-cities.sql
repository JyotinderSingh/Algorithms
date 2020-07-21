-- https://www.hackerrank.com/challenges/african-cities/problem
select city.name
from city, country
where city.countrycode = country.code and country.continent = "Africa"

-- -------------------

select city.name
from city join country on city.countrycode = country.code and country.continent = "Africa"

-- -------------------

select city.name
from city join country on city.countrycode = country.code
where country.continent = "Africa"