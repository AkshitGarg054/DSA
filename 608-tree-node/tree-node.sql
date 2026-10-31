# root has no parent
# the nodes which does not exist in p_id column are the leaf nodes

SELECT id,
    CASE
        WHEN p_id is NULL THEN 'Root' 
        WHEN id NOT IN (SELECT p_id FROM Tree WHERE p_id is NOT NULL) THEN 'Leaf' # p_id NULL can create an issue while using with NOT IN
        ELSE 'Inner'
    END as type
FROM Tree
