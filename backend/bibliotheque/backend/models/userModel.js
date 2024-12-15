const pool = require('./db');

async function findUserByEmail(email) {
    const [rows] = await pool.query('SELECT * FROM users WHERE email = ?', [email]);
    return rows[0];
}

async function createUser(email, hashedPassword) {
    const result = await pool.query('INSERT INTO users (email, password) VALUES (?, ?)', [email, hashedPassword]);
    return result[0].insertId;
}

module.exports = { findUserByEmail, createUser };
