# Bibliothèque - Gestion d'une bibliothèque en ligne

## Description

Ce projet permet de gérer une bibliothèque en ligne avec un système de gestion des utilisateurs et des livres. Les utilisateurs peuvent s'inscrire, se connecter, ajouter des livres, les consulter et les supprimer via une interface web. L'application utilise un backend construit avec **Node.js** et **Express.js**, ainsi qu'une base de données **MySQL** pour stocker les informations des utilisateurs et des livres.

## Fonctionnalités

- **Inscription et Connexion** : Un utilisateur peut s'inscrire, se connecter et récupérer un token JWT pour accéder aux fonctionnalités protégées.
- **Gestion des Livres** : Ajouter, afficher et supprimer des livres via des API sécurisées.
- **Protection par Authentification** : L'accès aux livres est protégé par un système d'authentification (utilisation du token JWT).

## Architecture

- **Backend** :
  - Framework : **Express.js** (Node.js)
  - Base de données : **MySQL** (via phpMyAdmin ou autre outil)
  - Authentification : **JWT (JSON Web Token)**
  - Gestion des routes : Express Router

- **Frontend** :
  - Technologie : **HTML**, **CSS**, **JavaScript**
  - Interaction avec le backend via des appels API (Fetch)

## Prérequis

Avant de commencer, assurez-vous d'avoir installé les éléments suivants :

- **Node.js** (version >= 14)
- **MySQL** (ou une base de données relationnelle compatible)
- **phpMyAdmin** (optionnel pour gérer la base de données)
- **Postman** (ou un autre outil pour tester les API)

## Installation

### 1. Cloner le dépôt

Clonez ce projet sur votre machine locale :

```bash
https://github.com/codeurfou93/BACHELOR/tree/main/backend/bibliotheque
```

### 2. Installer les dépendances
Dans le répertoire du projet, installez les dépendances nécessaires avec npm :

```
npm install
```

### 3. Configurer la base de données
- Créez une base de données bibliotheque dans MySQL.

- Utilisez phpMyAdmin ou un autre outil pour gérer votre base de données.

- Assurez-vous que la base de données contient une table users pour les utilisateurs et une table books pour les livres.

Voici la structure SQL pour la table users :

```
CREATE TABLE users (
    id INT AUTO_INCREMENT PRIMARY KEY,
    email VARCHAR(255) UNIQUE NOT NULL,
    password VARCHAR(255) NOT NULL
);
```
Et pour la table books :

```
CREATE TABLE books (
    id INT AUTO_INCREMENT PRIMARY KEY,
    title VARCHAR(255) NOT NULL,
    author VARCHAR(255) NOT NULL
);
```

### 4. Variables d'environnement
Créez un fichier .env à la racine du projet et configurez les variables suivantes :

```
DB_HOST=localhost
DB_USER=root
DB_PASSWORD=
DB_NAME=bibliotheque
JWT_SECRET=supersecretkey
```

### 5. Lancer le serveur
Une fois les dépendances installées et la base de données configurée, vous pouvez lancer le serveur avec :

```
npm run dev
```

Le serveur sera accessible sur http://localhost:3000.

## Utilisation

### 1. Inscription
Envoyez une requête POST à /auth/register pour inscrire un nouvel utilisateur. Le corps de la requête doit inclure l'email et le mot de passe :

```
{
  "email": "utilisateur@example.com",
  "password": "motdepasse"
}
```

### 2. Connexion
Envoyez une requête POST à /auth/login avec l'email et le mot de passe pour obtenir un token JWT. Le corps de la requête doit être :

```
{
  "email": "utilisateur@example.com",
  "password": "motdepasse"
}
```

La réponse contiendra un token JWT :

```
{
  "token": "token_jwt"
}
```

### 3. Gestion des Livres
Une fois connecté, vous pouvez interagir avec les livres :

- Afficher tous les livres :

    - Requête GET : /books
    - Le token JWT doit être inclus dans les en-têtes de la requête (Authorization: ton_token_jwt).
- Ajouter un livre :

    - Requête POST : /books
    - Corps de la requête :

```
{
  "title": "Titre du livre",
  "author": "Auteur du livre"
}
```

- Supprimer un livre :

    - Requête DELETE : /books/{id}
    - Remplacez {id} par l'ID du livre à supprimer.

## Technologies Utilisées
- Node.js : Serveur backend
- Express.js : Framework pour les API RESTful
- MySQL : Base de données relationnelle
- JWT : JSON Web Token pour l'authentification
- bcrypt : Hashing des mots de passe
- Postman : Utilisé pour tester les API

## Structure du projet

```
bibliotheque/
├── backend/
│   ├── controllers/
│   │   ├── authController.js
│   │   ├── bookController.js
│   ├── middlewares/
│   │   ├── authMiddleware.js
│   │   ├── loggerMiddleware.js
│   ├── models/
│   │   ├── db.js
│   │   ├── userModel.js
│   │   ├── bookModel.js
│   ├── routes/
│   │   ├── authRoutes.js
│   │   ├── bookRoutes.js
│   ├── app.js
│   ├── server.js
├── frontend/
│   ├── public/
│   │   ├── css/
│   │   │   └── styles.css
│   │   └── js/
│   │       └── app.js
│   ├── index.html
├── logs/
│   └── requests.log
├── .env
├── package.json
├── README.md

```



