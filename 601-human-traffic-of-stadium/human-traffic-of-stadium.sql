## As we need >= 3 consecutive, therefore, self join three times, and extract id from all the three tables
# one by one and then do UNION

select s1.id, s1.visit_date, s1.people 
from Stadium s1 
join Stadium s2 on s2.id=s1.id+1 
join Stadium s3 on  s3.id=s1.id+2
where s1.people>=100 and s2.people>=100 and s3.people>=100

union

select s2.id, s2.visit_date, s2.people
from Stadium s1
join Stadium s2 on s2.id = s1.id + 1 
join Stadium s3 on s3.id = s1.id + 2
where s1.people >= 100 and s2.people >= 100 and s3.people >= 100

union

select s3.id, s3.visit_date, s3.people
from Stadium s1
join Stadium s2 on s2.id = s1.id + 1 
join Stadium s3 on s3.id = s1.id + 2
where s1.people >= 100 and s2.people >= 100 and s3.people >= 100

order by id; 