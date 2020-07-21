-- https://www.hackerrank.com/challenges/weather-observation-station-2/problem
/*
Enter your query here.
*/
select round(sum(lat_n), 2), round(sum(long_w), 2)
from station