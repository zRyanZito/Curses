import Input from "../input/index.js";
import styled from "styled-components";
import { useState } from "react";
import { books } from "./data.js";

const SearchContainer = styled.div`
    display: flex;
    flex-direction: column;
    align-items: center;
    gap: 1.5rem;
    color: white;
    text-align: center;
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

const SearchResultContainer = styled.div`
    display: flex;
    flex-direction: row;
    justify-content: center;
    align-items: center;
    gap: 1rem;
`

const SearchResult = styled.div`
    display: flex;
    flex-direction: column;
    align-items: center;
    gap: 0.5rem;
`

function Search(){
    const [booksFiltered,setBooksFiltered] = useState([]);

    return(
        <SearchContainer>
            <Title>Já sabe por onde começar?</Title>

            <Subtitle>Encontre seu livro em nossa estante.</Subtitle>

            <Input placeholder="Escreva sua próxima leitura..." type="text" onBlur={evento => {
            
                var search = evento.target.value;
                const booksFiltered = books.filter(book => book.name.includes(search));
                setBooksFiltered(booksFiltered);
                }}
            />

            <SearchResultContainer>
                
                {booksFiltered.map(book => {
                    return (
                        <SearchResult>
                            <p>{book.name}</p>
                            <img src={book.src} alt={book.name}></img>
                        </SearchResult>
                    )
                })}
            </SearchResultContainer>

        </SearchContainer>
    )
}

export default Search