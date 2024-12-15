const { getAllBooks, createBook, deleteBook } = require('../models/bookModel');

async function getBooks(req, res) {
    const books = await getAllBooks();
    res.json(books);
}

async function addBook(req, res) {
    const { title, author } = req.body;

    if (!title || !author) {
        return res.status(400).json({ error: 'Title and author are required' });
    }

    const id = await createBook(title, author);
    res.status(201).json({ id, message: 'Book added successfully' });
}

async function removeBook(req, res) {
    const { id } = req.params;

    const success = await deleteBook(id);
    if (!success) {
        return res.status(404).json({ error: 'Book not found' });
    }

    res.json({ message: 'Book deleted successfully' });
}

module.exports = { getBooks, addBook, removeBook };
