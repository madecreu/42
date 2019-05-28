SELECT COUNT(*)
AS `films`
FROM `member_history`
WHERE member_history.date BETWEEN DATE('2006-10-30') AND DATE('2007-07-30')
OR MONTH(member_history.date) = 12 AND DAY(member_history.date) = 24;