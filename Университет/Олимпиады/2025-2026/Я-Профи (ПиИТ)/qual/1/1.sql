WITH q AS (
	SELECT
    	UserId,
    	SUM(Score) AS TotalScore,
    	CASE 
	        WHEN SUM(CASE WHEN julianday('now') - julianday(Timestamp) < 7 THEN 1 ELSE 0 END) = 0 
	          OR SUM(CASE WHEN julianday('now') - julianday(Timestamp) >= 7 THEN 1 ELSE 0 END) = 0
	        THEN 0
	        ELSE AVG(CASE WHEN julianday('now') - julianday(Timestamp) < 7 THEN Score ELSE NULL END) 
	           - AVG(CASE WHEN julianday('now') - julianday(Timestamp) >= 7 THEN Score ELSE NULL END)
        END AS TrendScore
	FROM Scores
	GROUP BY UserId
),
ranked_q AS (
	SELECT
    	*,
        ROW_NUMBER() OVER (ORDER BY TotalScore DESC, UserId) AS Rank,
        (SELECT COUNT(DISTINCT UserId) FROM Scores) AS total_users
    FROM q
)
SELECT
	UserId,
    TotalScore,
    Rank,
    CASE
    	WHEN total_users = 1
        THEN 100.00
        ELSE ROUND((total_users - Rank) * 100. / (total_users - 1), 2)
    END AS Percentile,
    ROUND(TrendScore, 2) AS TrendScore
FROM ranked_q
ORDER BY TotalScore DESC, UserId
LIMIT 10;
