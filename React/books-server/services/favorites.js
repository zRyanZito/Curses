const fs = require('fs')

function getAllFavoritesBooks() {
    return JSON.parse(fs.readFileSync("favorites-books.json"))
}

function insertFavoriteBook(id) {
    const books = JSON.parse(fs.readFileSync("books.json"))
    const favoritesBooks = getAllFavoritesBooks()

    const insertBook = books.find(book => book.id === id)
    const newFavoritesBooksList = [...favoritesBooks, insertBook]

    fs.writeFileSync("favorites-books.json", JSON.stringify(newFavoritesBooksList))
}

function delFavoriteBook(id) {
    let favoritesBooks = getAllFavoritesBooks()

    const filterBooks = favoritesBooks.filter(book => book.id !== id)

    fs.writeFileSync("favorites-books.json", JSON.stringify(filterBooks))
}

module.exports = { getAllFavoritesBooks, delFavoriteBook, insertFavoriteBook }