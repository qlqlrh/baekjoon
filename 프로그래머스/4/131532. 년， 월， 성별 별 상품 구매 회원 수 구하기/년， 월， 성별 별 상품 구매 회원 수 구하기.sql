# select *
select YEAR, MONTH, GENDER, count(USERS) as USERS
from USER_INFO U join
    (
        SELECT YEAR(SALES_DATE) as YEAR, MONTH(SALES_DATE) as MONTH, USER_ID, count(USER_ID) as USERS
        from ONLINE_SALE
        group by YEAR(SALES_DATE), MONTH(SALES_DATE), USER_ID
    ) sub on U.USER_ID = sub.USER_ID
where GENDER IS NOT NULL
group by YEAR, MONTH, GENDER
order by YEAR, MONTH, GENDER