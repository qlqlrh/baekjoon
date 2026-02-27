# select
# from (
    select PRODUCT_ID, PRODUCT_NAME, PRODUCT_CD, CATEGORY, MAX(PRICE) as PRICE
    from FOOD_PRODUCT
    group by PRODUCT_ID
    order by PRICE desc
    limit 1
# ) sub
# where 