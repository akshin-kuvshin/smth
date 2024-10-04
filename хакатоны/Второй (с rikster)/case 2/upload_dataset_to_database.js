urls = [
    'https://www.thesportsdb.com/api/v1/json/3/eventsseason.php?id=4328&s=2023-2024',
    'https://www.thesportsdb.com/api/v1/json/3/eventsseason.php?id=4355&s=2023-2024',
    'https://www.thesportsdb.com/api/v1/json/3/eventsseason.php?id=4380&s=2023-2024',
    'https://www.thesportsdb.com/api/v1/json/3/eventsseason.php?id=4387&s=2023-2024',
    'https://www.thesportsdb.com/api/v1/json/3/eventsseason.php?id=4414&s=2023-2024',
    'https://www.thesportsdb.com/api/v1/json/3/eventsseason.php?id=4476&s=2023-2024'
]

const mysql = require('mysql2');
const connection = mysql.createConnection({
    host: 'localhost',
    user: 'root',
    password: 'jobjob123',
    database: 'hackathon'
});

urls.map(function(url) {
    fetch(url).
    then(res => {return res.json()}).
    then(data => {
        data.map(function(event) {
            const name = event.strEvent;
            const date = event.dateEventLocal + event.strTimeLocal
            const country = event.strCountry
            const stadium = event.strVenue
            const tag_name = event.strSport
            const image = event.strThumb

            connection.query(`INSERT INTO events(name, date, country, stadium, tag_name, image) VALUES (\"${name}\", \"${date}\", \"${country}\", \"${stadium}\", \"${tag_name}\", \"${image}\");`);
        });
    });
});
