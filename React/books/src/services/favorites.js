import axios from "axios";

const favoritesAPI = axios.create({
    baseURL: "http://localhost:8000/favoritos",
});

async function getFavorites() {
    const response = await favoritesAPI.get("/");

    return response.data;
}

async function  postFavoriteBook(bookId) {
    await favoritesAPI.post(`/${bookId}`);
}

async function deleteFavoriteBook(bookId) {
    await favoritesAPI.delete(`/${bookId}`);
}

export { getFavorites, postFavoriteBook, deleteFavoriteBook };