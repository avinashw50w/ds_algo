/*Table: Person

+-------------+---------+
| Column Name | Type    |
+-------------+---------+
| id          | int     |
| email       | varchar |
+-------------+---------+
id is the primary key (column with unique values) for this table.
Each row of this table contains an email. The emails will not contain uppercase letters.
 

Write a solution to report all the duplicate emails. Note that it's guaranteed that the email field is not NULL.

Return the result table in any order.

The result format is in the following example.

*/
# Please upvote, if you like my solution
# 1
SELECT email from Person
group by email
having count(email) > 1;

# 2.
SELECT DISTINCT(p1.email) from Person p1, Person p2
where p1.id <> p2.id AND p1.email = p2.email;

#3. 
SELECT DISTINCT(p1.email) from 
Person p1 JOIN Person p2 ON
p1.email = p2.email AND p1.id <> p2.id;
# feel free to ask anything, if have any doubts