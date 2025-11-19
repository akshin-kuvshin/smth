DELETE FROM ВЛАДЕЛЕЦ
WHERE Код_владельца IN (
    SELECT ВЛ.Код_владельца
    FROM
        ВЛАДЕЛЕЦ AS ВЛ
        LEFT JOIN ТС ON ВЛ.Код_владельца = ТС.Код_владельца
    WHERE ТС.Государственный_номер IS NULL
);
