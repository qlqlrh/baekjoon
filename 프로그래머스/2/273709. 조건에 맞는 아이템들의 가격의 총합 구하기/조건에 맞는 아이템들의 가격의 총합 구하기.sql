select sub.sum as TOTAL_PRICE
from (
    select RARITY, sum(PRICE) as sum
    from ITEM_INFO
    group by RARITY
) sub
where sub.RARITY = 'LEGEND'