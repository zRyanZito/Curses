import styled from 'styled-components';

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
            {headerOptions.map((option) => (
                <ListItems>{option}</ListItems>
            ))}
        </List>

    )
}

export default HeaderOptions