select e.ID as ID,
# select *
case
        when pr <= 0.25 then 'CRITICAL'
        when pr <= 0.50 then 'HIGH'
        when pr <= 0.75 then 'MEDIUM'
        else 'LOW'
    end as COLONY_NAME
from (select ID,
        PERCENT_RANK() over (order by SIZE_OF_COLONY desc) as pr
    from ECOLI_DATA
) sub left join ECOLI_DATA e on sub.ID = e.ID
order by e.ID