-- 코드를 입력하세요
SELECT BOOK_ID, date_format(PUBLISHED_DATE, '%Y-%m-%d')
from BOOK
where CATEGORY = '인문' and PUBLISHED_DATE <= '2021-12-31' and PUBLISHED_DATE >= '2021-01-01'
order by PUBLISHED_DATE asc