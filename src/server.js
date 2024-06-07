const express = require('express');
const bodyParser = require('body-parser');
const { exec } = require('child_process');
const fs = require('fs');
const cors = require('cors');
const path = require('path');

const app = express();
const port = 3001;

app.use(cors());
app.use(bodyParser.json());

app.post('/solve-simplex', (req, res) => {
    const { constraints, objective } = req.body;

    // Créer un fichier d'entrée pour le programme C
    const inputFile = path.resolve(__dirname, 'input.txt');
    let inputContent = `${constraints.length}\n${objective.length - 1}\n`; // Envoyer le nombre correct de variables

    constraints.forEach(row => {
        inputContent += row.join(' ') + '\n';
    });
    inputContent += objective.join(' ') + '\n';

    console.log('Input content to be written:\n', inputContent);

    fs.writeFileSync(inputFile, inputContent);

    console.log('Input file written successfully:', inputFile);

    // Chemin absolu vers l'exécutable simplex
    const simplexPath = path.resolve(__dirname, 'C:\\Users\\azang\\CLionProjects\\Simplex\\simplex');

    // Appeler le programme C
    exec(`${simplexPath} < ${inputFile}`, (error, stdout, stderr) => {
        if (error) {
            console.error(`Erreur : ${error.message}`);
            return res.status(500).send('Erreur du serveur');
        }
        if (stderr) {
            console.error(`Erreur : ${stderr}`);
            return res.status(500).send('Erreur du serveur');
        }
        console.log('Output from simplex program:\n', stdout);
        res.send(stdout);
    });
});

app.listen(port, () => {
    console.log(`Serveur en cours d'exécution sur http://localhost:${port}`);
});