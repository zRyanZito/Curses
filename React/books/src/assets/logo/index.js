import logo from '../../images/logo.svg';
import styled from 'styled-components';

const LogoContainer = styled.div`
    display: flex;
    flex-direction: row;
    font-size: 30px;
    gap: 10px;
`

function Logo(){
    return (
        <LogoContainer> 
            <img src={logo} alt="logo"/>
            
            <p>
                <strong>Alura</strong> Books
            </p>
        </LogoContainer>
    )
}

export default Logo