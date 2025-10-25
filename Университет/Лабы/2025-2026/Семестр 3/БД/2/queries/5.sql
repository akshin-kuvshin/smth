SELECT TOP 3
    Название,
    Регион,
    COUNT(Номер_протокола) AS 'Зарегистрировано в 2025'
FROM
   (ОТДЕЛЕНИЕ AS О
    LEFT JOIN СОТРУДНИК AS С ON О.Код_отделения = С.Код_отделения)
    LEFT JOIN ПРОТОКОЛ AS П ON С.Номер_сотрудника = П.Номер_сотрудника
WHERE YEAR(Дата) IS NULL
   OR YEAR(Дата) = 2025
GROUP BY
    Название,
    Регион
ORDER BY 3 DESC, 1;

