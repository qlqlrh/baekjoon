-- item A -> B, C -> D
-- A가 b의 parent
--       A
--     /   \
--    B     C
-- tree 구조로 생각하면 편할 듯
select I.ITEM_ID, ITEM_NAME, RARITY
from ITEM_INFO I
    join ITEM_TREE T on I.ITEM_ID = T.ITEM_ID
where T.PARENT_ITEM_ID in (
    select ITEM_ID
    from ITEM_INFO
    where RARITY = 'RARE'
)
order by I.ITEM_ID desc