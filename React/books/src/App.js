import Header from './assets/header/index.js';
import Search from './assets/search/index.js';
import Releases from './assets/releases/index.js';
import styled from 'styled-components';

const AppContainer = styled.div`
  display: flex;
  flex-direction: column;
  justify-content: space-between;
  gap: 2rem;
  height: 100vh;
  background-image: linear-gradient(90deg, #002F52 35%, #326589);
`

function App() {
  return (

    <AppContainer>
      <Header/>
      <Search/>
      <Releases/>
    </AppContainer>

  );
}

export default App;
