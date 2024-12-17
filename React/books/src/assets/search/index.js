import Input from "../input/index.js";
import styled from "styled-components";
import { useEffect, useState } from "react";
import { getAllBooks } from "../../services/books.js";
import { postFavoriteBook } from "../../services/favorites.js";

const SearchContainer = styled.div`
    display: flex;
    flex-direction: column;
    align-items: center;
    gap: 1.5rem;
    color: white;
    text-align: center;
    margin: 2rem;
`

const Title = styled.h2`
    color: #FFF;
    font-size: 36px;
    text-align: center;
`

const Subtitle = styled.h3`
    font-size: 16px;
    font-weight: 500;
`

const SearchResult = styled.div`
    display: flex;
    flex-direction: column;
    width: 20rem;
    align-items: center;
    padding: 0.5rem;
    border: 1px solid #FFF;
    border-radius: 1rem;
    gap: 0.5rem;
    transition: all 0.7s;

    &:hover {
        cursor: pointer;
        background-color: #FFF;
        color: black;
    }
`

function Search(){
    const [booksFiltered,setBooksFiltered] = useState([]);
    const [books, setBooks] = useState([]);

    async function fetchBooks(){
        const booksAPI = await getAllBooks()
        setBooks(booksAPI);
    }

    useEffect(() => {
        fetchBooks();
    }, [])

    async function insertFavorite(bookId){
        await postFavoriteBook(bookId);
        alert("Livro adicionado aos favoritos!");
    }

    return(
        <SearchContainer>
            <Title>Já sabe por onde começar?</Title>

            <Subtitle>Encontre seu livro em nossa estante.</Subtitle>

            <Input placeholder="Escreva sua próxima leitura..." type="text" onBlur={evento => {
            
                var search = evento.target.value;
                const booksFill = books.filter(book => book.name.includes(search));
                setBooksFiltered(booksFill);
                }}
            />
                {booksFiltered.map(book => {
                    return (
                        <SearchResult onClick={() => insertFavorite(book.id)}>
                            <p>{book.name}</p>
                        </SearchResult>
                    )
                })}

        </SearchContainer>
    )
}

export default Search