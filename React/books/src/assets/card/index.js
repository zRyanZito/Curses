import Title from "../title/index.js";
import styled from "styled-components";

const CardContainer = styled.div`
    display: flex;
    max-width: 50rem;
    flex-direction: row;
    justify-content: center;
    align-items: center;
    background-color: #FFF;
    box-shadow: 0px 4px 4px rgba(0, 0, 0, 0.25);
    border-radius: 1rem;
    padding: 2rem;
    gap: 2rem;
`

const CardTexts = styled.div`
    display: flex;
    flex-direction: column;
    gap: 2.5rem;
`

const CardSubTexts = styled.div`
    display: flex;
    flex-direction: column;
    gap: .5rem;
`

const CardSubtitle = styled.h4`
    color: #002F52;
    font-size: 18px;
    font-weight: bold;
`

const CardDescription = styled.p`
    max-width: 300px;
`

const CardButton = styled.button`
    background-color: #EB9B00;
    color: #FFF;
    padding: 10px 0px;
    font-size: 16px;
    border: none;
    font-weight: 900;
    display: block;
    text-align: center;
    width: 150px;

    &:hover {
        cursor: pointer;
    }
`

const CardImg = styled.img`
    width: 150px;
`

function Card({title, subtitle, description, img, alt}){
    return(

        <CardContainer>
            <CardTexts>
            <Title fontSize="20px" color="#EB9B00" align="left">{title}</Title>  

                <CardSubTexts>
                    <CardSubtitle>{subtitle}</CardSubtitle>

                    <CardDescription>{description}</CardDescription>
                </CardSubTexts>
            </CardTexts>

            <div>
                <CardImg src={img} alt={alt}/>

                <CardButton>Saiba mais</CardButton>
            </div>
        </CardContainer>
    )
}

export default Card