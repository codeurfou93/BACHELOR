const express = require('express');
const { getBooks, addBook, removeBook } = require('../controllers/bookController');
const authMiddleware = require('../middlewares/authMiddleware');
const router = express.Router();

router.get('/', authMiddleware, getBooks);
router.post('/', authMiddleware, addBook);
router.delete('/:id', authMiddleware, removeBook);

module.exports = router;



