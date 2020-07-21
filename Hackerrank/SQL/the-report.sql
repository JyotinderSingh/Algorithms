-- https://www.hackerrank.com/challenges/the-report/problem
/*
Enter your query here.
*/
SELECT Name, Grade, Marks
FROM Students, Grades
WHERE Marks BETWEEN Min_Mark AND Max_Mark and Grade>=8
ORDER BY Grade desc,Name;

SELECT null, Grade, Marks
FROM Students, Grades
WHERE Marks BETWEEN Min_Mark AND Max_Mark and Grade<8
ORDER BY Grade desc,Name,Marks;