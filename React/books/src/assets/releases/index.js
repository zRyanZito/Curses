import { Book } from "./data.js";
import Title from "../title/index.js";
import RecommendCard from "../card/index.js";
import book2 from "../../images/livro2.png";
import styled from 'styled-components';

const ReleasesContainer = styled.section`
    background-color: #EBECEE;
    display: flex;
    flex-direction: column;
`

const ReleasesBooks = styled.div`
    display: flex;
    flex-direction: row;
    justify-content: center;
    align-items: center;
    padding: 2rem;
    gap: 2rem;
`

const ReleasesBook = styled.div`
    display: flex;
    flex-direction: column;
    justify-content: center;
    align-items: center;
    gap: 1rem;
    font-weight: bold;
`

const RecommendCardContainer = styled.section`
    display: flex;
    flex-direction: column;
    justify-content: center;
    align-items: center;
    margin: 2rem;
`

function Releases(){
    return(
        <ReleasesContainer>
            <Title fontSize="36px" color="#EB9B00" padding="1.5rem">
                Ultimos Lançamentos
            </Title>


            <ReleasesBooks>
                {Book.map(Book => {
                    return(
                        <ReleasesBook>
                            <p>{Book.name}</p>
                            <img src={Book.src} alt={Book.name}></img>
                        </ReleasesBook>
                    )
                })}
            </ReleasesBooks>

            <RecommendCardContainer>
                <RecommendCard
                    title="Talvez você se interesse por..."
                    subtitle="Angular 11"
                    description="Construindo uma aplicação integrada com a plataforma Google."
                    img={book2}
                    alt="card-image"
                />
            </RecommendCardContainer>

        </ReleasesContainer>
    )   
}

export default Releases