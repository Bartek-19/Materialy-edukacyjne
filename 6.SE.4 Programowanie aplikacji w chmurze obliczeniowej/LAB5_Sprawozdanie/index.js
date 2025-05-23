const express = require("express");
const { exec } = require("child_process");

const app = express();
const port = 8080;

app.get("/", (req, res) => {
    exec('echo Zadanie 1 && cat alpine_version && ip -4 a | grep inet && hostname', (error, stdout, stderr) => {
        if (error) {
            return res.status(500).send(`Błąd: ${error.message}`);
        }
        if (stderr) {
            return res.status(500).send(`Błąd: ${stderr}`);
        }
        res.send(`<pre>${stdout}</pre>`);
    });
});

app.listen(port, () => {
    console.log(`Serwer działa na porcie ${port}`);
});