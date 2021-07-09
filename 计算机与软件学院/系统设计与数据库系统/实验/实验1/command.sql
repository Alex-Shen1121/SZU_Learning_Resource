CREATE TABLE EMP (
	EMPNO INT ( 4 ) PRIMARY KEY NOT NULL,
	ENAME VARCHAR ( 10 ) NOT NULL,
	JOB VARCHAR ( 9 ) NOT NULL,
	MGR INT ( 4 ) REFERENCES EMP ( EMPNO ),
	HIREDATE DATE NOT NULL,
	SAL NUMERIC ( 7, 2 ) NOT NULL,
	COMM NUMERIC ( 7, 2 ),
	DEPTNO INT ( 2 ) DEFAULT 10 
);

CREATE TABLE DEPT (
 DEPTNO INT ( 2 )  PRIMARY KEY NOT NULL, 
 DNAME VARCHAR ( 10 ) NOT NULL, 
 LOC VARCHAR ( 10 ) NOT NULL
 );
 
INSERT INTO `exp1`.`emp` ( `EMPNO`, `ENAME`, `JOB`, `MGR`, `HIREDATE`, `SAL`, `COMM`, `DEPTNO` )
VALUES
	( 7369, 'SMITH', 'CLERK', 7902, '1990-12-17', 13750.00, NULL, 20 );
	
INSERT INTO `exp1`.`dept` ( `DEPTNO`, `DNAME`, `LOC` )
VALUES
	( 10, 'ACCOUNTING', 'LONDON' );

--question1
SELECT
	* 
FROM
	emp;
	
--question2
SELECT
	* 
FROM
	dept
	
--question3
SELECT
	ENAME,
	EMPNO,
	SAL,
	DEPTNO
FROM
	emp;
	
-- question4
SELECT
	* 
FROM
	emp 
WHERE
	`DEPTNO` = 10 
	OR `DEPTNO` = 30;
	
	
-- question5
SELECT DISTINCT
	JOB 
FROM
	emp

-- question6
SELECT
	emp.ENAME 
FROM
	emp 
WHERE
	emp.SAL < 20000
	
-- question7
SELECT
 emp.ENAME, emp.JOB, emp.EMPNO 
FROM
 emp
WHERE
 emp.DEPTNO = 20
 AND emp.SAL > 25000;

-- question8
SELECT
	* 
FROM
	emp 
WHERE
	emp.JOB = 'CLERK' 
	OR emp.JOB = 'SALESMAN';

-- question9
SELECT
	* 
FROM
	emp 
WHERE
	emp.JOB = 'CLERK' 
	AND emp.DEPTNO != 10;

-- question10
SELECT
	* 
FROM
	emp 
WHERE
	emp.JOB = 'SALESMAN' 
	OR ( emp.JOB = 'ANALYST' AND emp.DEPTNO = 20 );
	
-- question11
SELECT
	emp.ENAME,
	emp.DEPTNO,
	emp.SAL 
FROM
	emp 
WHERE
	emp.SAL BETWEEN 15000 
	AND 20000;

-- question12
SELECT
	emp.ENAME 
FROM
	emp 
WHERE
	emp.JOB = 'PRESIDENT';

-- question13
SELECT
	* 
FROM
	emp 
WHERE
	emp.ENAME LIKE '%S';

-- question14
SELECT
	* 
FROM
	emp 
WHERE
	emp.ENAME LIKE '%TH%' 
	OR emp.ENAME LIKE '%LL%';

-- question15
SELECT
	* 
FROM
	emp 
WHERE
	emp.COMM IS NOT NULL 
	AND emp.COMM != 0;

-- question16
SELECT
	emp.ENAME,
	emp.JOB,
	emp.SAL,
	emp.HIREDATE,
	emp.DEPTNO 
FROM
	emp 
ORDER BY
	emp.ENAME ASC;

-- question17
SELECT
	emp.ENAME,
	emp.JOB,
	emp.SAL,
	emp.HIREDATE,
	emp.DEPTNO 
FROM
	emp 
ORDER BY
	emp.SAL ASC;

-- question18
SELECT
	* 
FROM
	emp 
WHERE
	emp.JOB = 'SALESMAN' 
ORDER BY
	emp.COMM / emp.SAL DESC;
	
-- question19
SELECT
	* 
FROM
	emp 
WHERE
	emp.DEPTNO = 30 
	AND emp.COMM IS NOT NULL 
	AND emp.COMM != 0 
ORDER BY
	emp.COMM ASC;

-- question20
SELECT
	emp.ENAME,
	emp.JOB,
	emp.SAL,
	emp.COMM 
FROM
	emp 
WHERE
	emp.MGR NOT IN ( SELECT emp.EMPNO FROM emp WHERE emp.JOB = 'MANAGER' );

-- question20
SELECT
	e1.ENAME,
	e1.JOB,
	e1.SAL,
	e1.COMM
FROM
	emp as e1,emp as e2
WHERE
	e1.MGR=e2.EMPNO and e2.JOB!='MANAGER';

-- question21
SELECT
	* 
FROM
	emp 
WHERE
	emp.DEPTNO = 30 
	AND emp.SAL >= 18000;

-- question22
SELECT
	* 
FROM
	emp 
WHERE
	emp.HIREDATE < '1998-1-1' 
	AND ( emp.SAL > 5000 OR emp.SAL < 1000 );
	
-- question23
ALTER TABLE emp ADD PRIMARY KEY ( EMPNO );

-- question24
ALTER TABLE emp ADD family_name VARCHAR ( 10 );

-- question25
ALTER TABLE emp DROP PRIMARY KEY ;

-- question26
RENAME TABLE emp TO EMPLOYEE;

-- question27
RENAME TABLE EMPLOYEE TO emp;

-- question28
ALTER TABLE emp DROP emp.family_name;

-- question29
CREATE TABLE employee AS SELECT * FROM emp;

-- question30
DROP TABLE employee;

-- question31
SELECT
	* 
FROM
	emp 
WHERE
	emp.ENAME LIKE '%用户输入字符串%';

-- question32
SELECT
	* 
FROM
	emp
WHERE
	emp.COMM IS NULL;