const fs = require('fs')

function getAllBooks() {
    return JSON.parse(fs.readFileSync("books.json"))
}

function getBookForId(id) {
    const books = getAllBooks()

    const filterbook = books.filter(book => book.id == id)[0]

    return filterbook
}

function insertBook(newbook) {
    const books = getAllBooks()

    const newListBooks = [...books, newbook]

    fs.writeFileSync("books.json", JSON.stringify(newListBooks))
}

function modifyBook(modifys, id){
    let books = getAllBooks()

    const bookIndex = books.findIndex(book => book.id === id)

    const modifyContent = {...books[bookIndex], ...modifys}

    books[bookIndex] = modifyContent

    fs.writeFileSync("books.json", JSON.stringify(books))
}

function delBook(id) {
    let books = getAllBooks()

    const filterBooks = books.filter(book => book.id !== id)

    fs.writeFileSync("books.json", JSON.stringify(filterBooks))
}

module.exports = { getAllBooks, getBookForId, insertBook, modifyBook, delBook }