-- 코드를 입력하세요
# select *
SELECT A.AUTHOR_ID as AUTHOR_ID,
        A.AUTHOR_NAME as AUTHOR_NAME,
        B.CATEGORY as CATEGORY,
        sum(S.SALES * B.PRICE) as TOTAL_SALES
from BOOK B join AUTHOR A on B.AUTHOR_ID = A.AUTHOR_ID
            join (select BOOK_ID, sum(SALES) as SALES
                    from BOOK_SALES
                    where SALES_DATE like '2022-01%'
                    group by BOOK_ID
                ) S on B.BOOK_ID = S.BOOK_ID
group by AUTHOR_NAME, CATEGORY
order by AUTHOR_ID, CATEGORY desc
