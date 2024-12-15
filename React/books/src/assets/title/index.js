import styled from "styled-components";

const Title = styled.h2`
    padding: ${props => props.padding || '0'};
    background-color: #FFF;
    color: ${props => props.color || 'black'};
    font-size: ${props => props.fontSize || '36px'};
    text-align: ${props => props.align || 'center'};
    margin: 0;
`

export default Title