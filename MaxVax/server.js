require('dotenv').config();
const express = require('express');
const fetch = require('node-fetch');
const app = express();
const port = 3000;

const appToken = process.env.APP_TOKEN;

app.use(express.static('public'));

app.get('/getLocations', async (req, res) => {
    const zipcode = req.query.zipcode;
    const datasetUrl = 'https://data.cdc.gov/resource/5jp2-pgaw.json';

    try {
        const response = await fetch(`${datasetUrl}?$$app_token=${appToken}&loc_admin_zip=${zipcode}&in_stock=true`);
        if (!response.ok) {
            throw new Error(`Network response was not ok: ${response.statusText}`);
        }
        const allData = await response.json();
        res.json(allData);
    } catch (error) {
        console.error('Error fetching data:', error);
        res.status(500).send('Error fetching data');
    }
});

app.listen(port, () => {
    console.log(`Server running at http://localhost:${port}`);
});
