import Logo from '../logo/index.js';
import HeaderOptions from './header-options/index.js';
import HeaderIcons from './header-icons/index.js';
import styled from 'styled-components';
import { Link } from 'react-router-dom';

const HeaderContainer = styled.header`
    display: flex;
    flex-direction: row;
    justify-content: center;
    align-items: center;
    background-color: white;
    padding: 1.5rem;
    gap: 1rem;
`


function Header(){
    return (
        <HeaderContainer>
            <Link to="/">
                <Logo/>
            </Link>
            <HeaderOptions/>
            <HeaderIcons/>
        </HeaderContainer>
    )
}

export default Header