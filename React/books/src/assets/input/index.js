import styled from "styled-components";

const Input = styled.input`
    background: white;
    border: none;
    border-radius: .5rem;
    width: 18rem;
    height: 2.5rem;
    padding: .5rem;
    color: black;

    &::placeholder {
        color: black;
    }

    &:focus {
        outline: none;
    }
`;

export default Input