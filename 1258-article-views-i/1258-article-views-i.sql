# Write your MySQL query statement below

-- ALTER TABLE views 
-- ADD COLUMN id INT;
-- SELECT id 
-- FROM views 
-- WHERE author_id = viewer_id;
-- SELECT id 
-- FROM views 
-- ORDER BY id ASC;

SELECT DISTINCT author_id AS id
FROM views
WHERE author_id = viewer_id
ORDER BY author_id ASC;
