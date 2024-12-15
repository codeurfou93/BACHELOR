const pool = require('./db');

async function getAllBooks() {
    const [rows] = await pool.query('SELECT * FROM books');
    return rows;
}

async function createBook(title, author) {
    const result = await pool.query('INSERT INTO books (title, author) VALUES (?, ?)', [title, author]);
    return result[0].insertId;
}

async function deleteBook(id) {
    const result = await pool.query('DELETE FROM books WHERE id = ?', [id]);
    return result[0].affectedRows > 0;
}

module.exports = { getAllBooks, createBook, deleteBook };
