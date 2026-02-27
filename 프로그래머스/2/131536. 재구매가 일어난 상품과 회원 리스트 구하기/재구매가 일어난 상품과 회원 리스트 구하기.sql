select USER_ID, PRODUCT_ID
from ONLINE_SALE
group by USER_ID, PRODUCT_ID
having count(SALES_DATE) >= 2
order by USER_ID, PRODUCT_ID desc