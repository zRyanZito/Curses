import profile from '../../../images/perfil.svg';
import bag from '../../../images/sacola.svg';
import styled from 'styled-components';

const List = styled.ul`
    display: flex;
    flex-direction: row;
    justify-content: center;
    align-items: center;
    gap: 2rem;
`

const ListItems = styled.li`
    display: flex;
    justify-content: center;
    align-items: center;
    height: 2rem;
    width: 2rem;
`

const headerIcons = [profile, bag];

function HeaderIcons(){
    return (
        <List>
            {headerIcons.map((icon) => (
                <ListItems><img src={icon} alt="icon"></img></ListItems>
            ))}
        </List>
    )
}

export default HeaderIcons