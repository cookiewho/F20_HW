----------------------------------------------------------------------------
-- Homework 5 part 2
-- CST 363, Intro to Databases
--
-- Instructions:
-- o Enter your SQL between -- YOUR CODE HERE: and -- YOUR CODE ENDS
-- o Do not delete or modify any other lines in the file.
----------------------------------------------------------------------------
---
--- The following problems use courses-ddl.sql and courses-large.sql.
---
runscript from  'courses-ddl.sql';
runscript from  'courses-large.sql';

-- 6. Write SQL that will 1) create a table named �grade_points�, with
-- attributes �grade� and �points�, and 2) add rows to the table for
-- grades A+,A,A-,B+,B,B-,C+,C,C-, and F, with corresponding points
-- 4.2, 4.0, 3.7, 3.33, 3.0, 2.7, 2.3, 2.0, 1.7, 0.0.  The domain
-- of the grade attribute should be varchar(2), and the domain of
-- the points attribute should be numeric(1,2).

-- YOUR CREATE TABLE AND INSERT CODE HERE:

create table GRADE_POINTS (grade varchar(2),points double(2));

insert into GRADE_POINTS values('A+', 4.2);
insert into GRADE_POINTS values('A', 4.0);
insert into GRADE_POINTS values('A-', 3.7);
insert into GRADE_POINTS values('B+', 3.3);
insert into GRADE_POINTS values('B', 3.0);
insert into GRADE_POINTS values('B-', 2.7);
insert into GRADE_POINTS values('C+', 2.3);
insert into GRADE_POINTS values('C', 2.0);
insert into GRADE_POINTS values('C-', 1.7);
insert into GRADE_POINTS values('F', 0.0);

 
-- YOUR CODE ENDS

select * from grade_points order by points desc;
--> A+ 4.2
--> A 4.0
--> A- 3.7
--> B+ 3.3
--> B 3.0
--> B- 2.7
--> C+ 2.3
--> C 2.0
--> C- 1.7
--> F 0.0
;

-- 7. Write a view named 'student_gpa' that gives, for each student ID, the
-- student�s grade point average.  The attributes of the view should
-- be 'ID' and 'gpa'.  

-- YOUR CREATE VIEW HERE:
create view student_gpa as select id, round(avg(points),2) as gpa from grade_points, takes where takes.grade = grade_points.grade group by id;
 
-- YOUR CODE ENDS

-- 8. Using the student_gpa view, write a query that for 
--    each student gives the ID, name, dept_name and gpa.
--    Round the gpa value to 2 digits after decimal point. 
select s.id, name, dept_name, CAST(gpa AS DECIMAL(10,2)) from student as s natural join student_gpa as gpa order by s.id limit 10;
--> 1000 Manber Civil Eng. 2.82
--> 10033 Zelty Mech. Eng. 2.56
--> 10076 Duan Civil Eng. 3.42
--> 1018 Colin Civil Eng. 3.14
--> 10204 Mediratta Geology 3.20
--> 10267 Rzecz Comp. Sci. 3.15
--> 10269 Hilberg Psychology 2.91
--> 10454 Ugarte Pol. Sci. 3.05
--> 10481 Grosch Astronomy 3.67
--> 10527 Kieras Physics 3.09
;
 
-- 9. Write a query that gives, for each instructor ID, the number of students 
--    the instructor advises. Include all instructors, even if they do not appear 
--    in the 'advisor' table.  Order the output by number of advised students
--    in descending order, then by instructor id ascending.
select i_id, count(distinct s_id) as s from advisor group by i_id order by s desc;
--> 35579 54
--> 77346 54
--> 37687 50
--> 97302 50
--> 48570 49
--> 16807 48
--> 52647 48
--> 72553 48
--> 6569 46
--> 73623 46
--> 79653 46
--> 4034 45
--> 57180 45
--> 28400 44
--> 4233 44
--> 80759 43
--> 36897 42
--> 41930 41
--> 42782 41
--> 63287 41
--> 95030 41
--> 95709 41
--> 22591 40
--> 58558 40
--> 79081 40
--> 81991 40
--> 14365 39
--> 50330 39
--> 74426 39
--> 90376 39
--> 15347 38
--> 25946 38
--> 3199 38
--> 65931 38
--> 96895 38
--> 28097 37
--> 48507 36
--> 64871 36
--> 31955 35
--> 43779 34
--> 19368 33
--> 34175 33
--> 78699 33
--> 99052 33
--> 3335 32
--> 59795 31
--> 63395 31
--> 74420 31
--> 50885 28
--> 90643 24
;