const express = require('express');
const bookRouter = require('./routes/book');
const favoritesBooksRouter = require('./routes/favorites');
const app = express();
const cors = require('cors');

app.use(express.json());
app.use(cors({origin: '*'}));

const port = 8000;

app.use('/livros', bookRouter);
app.use('/favoritos', favoritesBooksRouter);

app.listen(port, () => {
    console.log(`Server is running on port ${port}`);
})