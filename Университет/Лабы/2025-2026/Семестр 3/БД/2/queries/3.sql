SELECT
    Фамилия,
    Имя,
    Отчество,
    Дата_рождения,
    DATEDIFF('yyyy', MIN(ВУ.Дата_выдачи), DATE()) AS Стаж
FROM
    ВОДИТЕЛЬ AS ВД
    INNER JOIN ВУ ON ВД.СНИЛС = ВУ.СНИЛС
WHERE DATEDIFF('yyyy', Дата_рождения, DATE()) < 30
GROUP BY
    ВД.СНИЛС,
    Фамилия,
    Имя,
    Отчество,
    Дата_рождения
HAVING DATEDIFF('yyyy', MIN(ВУ.Дата_выдачи), DATE()) >= 7;

