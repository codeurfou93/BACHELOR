const express = require('express');
const bodyParser = require('body-parser');
const authRoutes = require('./routes/authRoutes');
const bookRoutes = require('./routes/bookRoutes');
const loggerMiddleware = require('./middlewares/loggerMiddleware');
const path = require('path');
require('dotenv').config();

const app = express();

// Middlewares
app.use(bodyParser.json());
app.use(loggerMiddleware);

// Routes API
app.use('/auth', authRoutes);
app.use('/books', bookRoutes);

// Catch-all route pour les pages frontend (doit être après les routes API)
app.use(express.static(path.join(__dirname, '../frontend')));

// Pour servir le fichier index.html sur toutes les autres routes qui ne sont pas API
app.get('*', (req, res) => {
    res.sendFile(path.join(__dirname, '../frontend/index.html'));
});

// Gestion des erreurs
app.use((err, req, res, next) => {
    console.error(err.stack);
    res.status(err.status || 500).json({ error: err.message || 'Une erreur est survenue.' });
});

module.exports = app;
