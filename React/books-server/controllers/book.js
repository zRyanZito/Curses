const { getAllBooks, getBookId, insertBook, modifyBook, delBook } = require('../services/book');

function getBooks(req, res) {
    try {
        const books = getAllBooks();
        res.send(books);
    } catch (error) {
        res.status(500)
        res.send(error.message)
    }
}

function getBook(req, res) {
    try {
        const id = req.params.id
        
        if(id && Number(id)){
            const book = getBookId(id);
            res.send(book);
        } else{
            res.status(422)
            res.send("id invalido")
        }

    } catch (error) {
        res.status(500)
        res.send(error.message)
    }
}

function postBook(req, res) {
    try {
        const newbook = req.body;

        if(req.body.name){
            insertBook(newbook);
            res.status(201)
            res.send("Livro cadastrado com sucesso!");
        }else{
            res.status(422)
            res.send("'name' é obrigatório")
        }


    } catch (error) {
        res.status(500)
        res.send(error.message)
    }
}

function patchBook(req, res) {
    try {
        const id = req.params.id
        const body = req.body

        if(id && Number(id)){
            modifyBook(body, id)
            res.status(200)
            res.send("Livro modificado com sucesso!")
        }else{
            res.status(422)
            res.send("id invalido")
        }

    } catch (error) {
        res.status(500)
        res.send(error.message)
    }
}

function deleteBook(req, res) {
    try {
        const id = req.params.id

        if(id && Number(id)){
            delBook(id)
            res.status(200)
            res.send("Livro deletado com sucesso!")
        }else{
            res.status(422)
            res.send("id invalido")
        }
    } catch (error) {
        res.status(500)
        res.send(error.message)
    }
}

module.exports = { getBooks, getBook, postBook, patchBook, deleteBook }