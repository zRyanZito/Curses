import styled from 'styled-components';
import { Link } from 'react-router-dom';

const List = styled.ul`
    display: flex;
    flex-direction: row;
`

const ListItems = styled.li`
    display: flex;
    justify-content: center;
    align-items: center;
    font-size: 16px;
    height: 100%;
    min-width: 120px;
    cursor: pointer;
`

const headerOptions = ["CATEGORIAS", "FAVORITOS", "ESTANTE"];

function HeaderOptions() {
    return (

        <List>
            {headerOptions.map((text) => (
                <Link to={`/${text.toLowerCase()}`}>
                    <ListItems>{text}</ListItems>
                </Link>
            ))}
        </List>

    )
}

export default HeaderOptions