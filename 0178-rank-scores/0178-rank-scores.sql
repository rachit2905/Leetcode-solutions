select score,
    dense_rank() OVER (order by score desc) as 'rank' from Scores order by score desc;