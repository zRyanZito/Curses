const { Router } = require('express');
const { getFavorites, postFavoriteBook, deleteFavoriteBook } = require('../controllers/favorites');

const router = Router();

router.get('/', getFavorites);

router.post('/:id', postFavoriteBook);

router.delete('/:id', deleteFavoriteBook);

module.exports = router;