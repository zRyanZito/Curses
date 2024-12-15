const express = require('express');
const bookRouter = require('./routes/book');
const app = express();
app.use(express.json());

const port = 8000;

app.use('/livros', bookRouter);

app.listen(port, () => {
    console.log(`Server is running on port ${port}`);
})