-- https://www.hackerrank.com/challenges/what-type-of-triangle/problem
SELECT (CASE
       WHEN NOT(A + B > C AND A + C > B AND B + C > A) THEN "Not A Triangle"
        WHEN A = B AND B = C THEN "Equilateral"
        WHEN A = B OR B = C OR A = C THEN "Isosceles"
        ELSE "Scalene"
        END
       )
FROM TRIANGLEs;