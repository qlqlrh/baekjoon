select e.ID, IFNULL(cnt, 0) as CHILD_COUNT
from (
    select C.ID as cID, count(*) as cnt
    from ECOLI_DATA C
        join ECOLI_DATA P on C.ID = P.PARENT_ID
    group by C.ID
) sub right join ECOLI_DATA e on sub.cID = e.ID
order by e.ID;