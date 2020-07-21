-- https://www.hackerrank.com/challenges/average-population-of-each-continent/problem
select continent, floor(avg(city.population))
from city join country on city.countrycode = country.code
group by continent