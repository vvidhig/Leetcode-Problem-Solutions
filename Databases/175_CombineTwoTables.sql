SELECT firstName, lastName, city, state FROM Person s1
LEFT JOIN Address s2 
ON s2.personId = s1.personId;
