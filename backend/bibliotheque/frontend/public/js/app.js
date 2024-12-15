const API_URL = 'http://localhost:3000';
let token = null;

// Elements du DOM
const app = document.getElementById('app');

function renderLogin() {
    app.innerHTML = `
        <h2>Connexion</h2>
        <div class="error" id="error"></div>
        <form id="loginForm">
            <input type="email" id="email" placeholder="Email" required>
            <input type="password" id="password" placeholder="Mot de passe" required>
            <button type="submit">Se connecter</button>
        </form>
        <p>Pas encore inscrit ? <button id="showRegister">Créer un compte</button></p>
    `;

    document.getElementById('loginForm').addEventListener('submit', handleLogin);
    document.getElementById('showRegister').addEventListener('click', renderRegister);
}

function renderRegister() {
    app.innerHTML = `
        <h2>Inscription</h2>
        <div class="error" id="error"></div>
        <form id="registerForm">
            <input type="email" id="email" placeholder="Email" required>
            <input type="password" id="password" placeholder="Mot de passe" required>
            <button type="submit">S'inscrire</button>
        </form>
        <p>Déjà inscrit ? <button id="showLogin">Se connecter</button></p>
    `;

    document.getElementById('registerForm').addEventListener('submit', handleRegister);
    document.getElementById('showLogin').addEventListener('click', renderLogin);
}

function renderBooks() {
    app.innerHTML = `
        <h2>Liste des Livres</h2>
        <div class="error" id="error"></div>
        <ul id="bookList"></ul>
        <form id="addBookForm">
            <input type="text" id="title" placeholder="Titre" required>
            <input type="text" id="author" placeholder="Auteur" required>
            <button type="submit">Ajouter un Livre</button>
        </form>
        <button id="logout">Déconnexion</button>
    `;

    document.getElementById('addBookForm').addEventListener('submit', handleAddBook);
    document.getElementById('logout').addEventListener('click', handleLogout);

    fetchBooks();
}

function displayError(message) {
    const errorDiv = document.getElementById('error');
    errorDiv.textContent = message;
}

async function handleLogin(e) {
    e.preventDefault();

    const email = document.getElementById('email').value;
    const password = document.getElementById('password').value;

    try {
        const response = await fetch(`${API_URL}/auth/login`, {
            method: 'POST',
            headers: { 'Content-Type': 'application/json' },
            body: JSON.stringify({ email, password })
        });

        const data = await response.json();

        if (response.ok) {
            // token = data.token;
            // renderBooks();
            sessionStorage.setItem('token', data.token); // Enregistrer le token dans sessionStorage
    token = data.token;
    renderBooks();
        } else {
            displayError(data.error);
        }
    } catch (err) {
        displayError('Une erreur est survenue.');
    }
}

async function handleRegister(e) {
    e.preventDefault();

    const email = document.getElementById('email').value;
    const password = document.getElementById('password').value;

    try {
        const response = await fetch(`${API_URL}/auth/register`, {
            method: 'POST',
            headers: { 'Content-Type': 'application/json' },
            body: JSON.stringify({ email, password })
        });

        const data = await response.json();

        if (response.ok) {
            renderLogin();
        } else {
            displayError(data.error);
        }
    } catch (err) {
        displayError('Une erreur est survenue.');
    }
}

async function fetchBooks() {
    try {
        // Récupérer le token depuis le stockage local ou session
        const token = sessionStorage.getItem('token'); 

        // Si le token n'est pas présent, afficher une erreur
        if (!token) {
            displayError('Veuillez vous connecter pour voir les livres.');
            return renderLogin(); // Rediriger vers la page de connexion si le token n'est pas trouvé
        }
        

        // Envoyer la requête avec le token dans les headers
        const response = await fetch(`${API_URL}/books`, {
            method: 'GET',
            headers: {
                'Authorization': `${token}` // Ajouter le token d'authentification
            }
        });

        // Vérifier si la réponse est OK
        if (!response.ok) {
            throw new Error('Impossible de charger les livres');
        }

        const books = await response.json();
        const bookList = document.getElementById('bookList');
        bookList.innerHTML = books.map(book => `
            <li>
                <strong>${book.title}</strong> - ${book.author}
                <button onclick="handleDeleteBook(${book.id})">Supprimer</button>
            </li>
        `).join('');
    } catch (err) {
        displayError('Impossible de charger les livres.');
        console.error(err); // Afficher l'erreur dans la console pour le débogage
    }
}


async function handleAddBook(e) {
    e.preventDefault();

    const title = document.getElementById('title').value;
    const author = document.getElementById('author').value;

    try {
        const response = await fetch(`${API_URL}/books`, {
            method: 'POST',
            headers: {
                'Content-Type': 'application/json',
                Authorization: token
            },
            body: JSON.stringify({ title, author })
        });

        if (response.ok) {
            fetchBooks();
        } else {
            const data = await response.json();
            displayError(data.error);
        }
    } catch (err) {
        displayError('Impossible d\'ajouter le livre.');
    }
}

async function handleDeleteBook(id) {
    try {
        const response = await fetch(`${API_URL}/books/${id}`, {
            method: 'DELETE',
            headers: { Authorization: token }
        });

        if (response.ok) {
            fetchBooks();
        } else {
            const data = await response.json();
            displayError(data.error);
        }
    } catch (err) {
        displayError('Impossible de supprimer le livre.');
    }
}

function handleLogout() {
    token = null;
    renderLogin();
}

// Initialisation
renderLogin();
