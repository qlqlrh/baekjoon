-- 코드를 입력하세요

with recursive cte as (
    select 0 as HOUR
    union all
    select HOUR + 1 from cte where HOUR < 23
)
select cte.HOUR as HOUR,
    count(A.DATETIME) as COUNT
from  cte left join ANIMAL_OUTS A
    on cte.HOUR = HOUR(A.DATETIME)
group by cte.HOUR