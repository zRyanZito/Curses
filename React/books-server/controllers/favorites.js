const { getAllFavoritesBooks, delFavoriteBook, insertFavoriteBook } = require('../services/favorites');

function getFavorites(req, res) {
    try {
        const books = getAllFavoritesBooks();
        res.send(books);
    } catch (error) {
        res.status(500)
        res.send(error.message)
    }
}

function postFavoriteBook(req, res) {
    try {
        const id = req.params.id

        insertFavoriteBook(id);
        res.status(201)
        res.send("Livro favoritado com sucesso!");

    } catch (error) {
        res.status(500)
        res.send(error.message)
    }
}

function deleteFavoriteBook(req, res) {
    try {
        const id = req.params.id

        if(id && Number(id)){
            delFavoriteBook(id)
            res.status(200)
            res.send("Livro favorito deletado com sucesso!")
        }else{
            res.status(422)
            res.send("ID invalido")
        }
    } catch (error) {
        res.status(500)
        res.send(error.message)
    }
}


module.exports = { getFavorites, postFavoriteBook, deleteFavoriteBook }