#include "Mot.h"
#include "Joueur.h"
#include "pendu.h"
#include <iostream>

// Codes de couleur
const std::string RED = "\033[31m";    // Rouge pour les erreurs
const std::string GREEN = "\033[32m";  // Vert pour les lettres trouvées
const std::string RESET = "\033[0m";    // Reset couleur

int main() {
    std::string nomFichier = "mots.txt"; // Nom du fichier contenant la liste de mots
    std::string motADeviner = initialiserMot(nomFichier);
    if (motADeviner.empty()) {
        std::cerr << "Aucun mot disponible à deviner." << std::endl;
        return 1; // Quitte si aucun mot n'est disponible
    }

    Joueur* joueur = new Joueur(6); // Crée un joueur avec 6 tentatives
    Mot* mot = new Mot(motADeviner); // Crée un objet Mot avec le mot à deviner

    std::cout << "Bienvenue dans le jeu du pendu !" << std::endl;
    std::cout << "L'ordinateur a choisi un mot à deviner." << std::endl;

    // Ajout des statistiques
    int coups = 0;
    int motsDevinés = 0;

    while (joueur->getTentativesRestantes() > 0) {
        std::cout << "\nMot à deviner : ";
        mot->afficherMot();

        std::cout << "Tentatives restantes : " << joueur->getTentativesRestantes() << std::endl;
        joueur->afficherErreurs();

        std::cout << "Proposez une lettre : ";
        char lettre;
        std::cin >> lettre;

        coups++; // Incrémenter le compteur de coups

        if (!joueur->aDejaEssayé(lettre)) {
            joueur->proposerLettre(lettre);
            if (mot->getMot().find(lettre) == std::string::npos) {
                joueur->decrementerTentatives();
                std::cout << RED << "La lettre " << lettre << " n'est pas dans le mot." << RESET << std::endl;
            } else {
                mot->revelerLettre(lettre);
                std::cout << GREEN << "Bonne lettre !" << RESET << std::endl; // Indication que la lettre est correcte
            }
        } else {
            std::cout << "Vous avez déjà essayé la lettre " << lettre << "." << std::endl;
        }

        if (mot->verifierVictoire()) {
            std::cout << "\nFélicitations ! Vous avez deviné le mot : " << mot->getMot() << std::endl;
            motsDevinés++; // Incrémenter les mots devinés
            break;
        }
    }

    if (joueur->getTentativesRestantes() == 0) {
        std::cout << "\nDommage, vous avez perdu ! Le mot était : " << mot->getMot() << std::endl;
    }

    // Affichage des statistiques
    std::cout << "Nombre de coups : " << coups << std::endl;
    std::cout << "Nombre de mots devinés avec succès : " << motsDevinés << std::endl;

    // Sauvegarder la partie
    sauvegarderPartie(*joueur, *mot, "sauvegarde.txt");

    // Libération de la mémoire
    delete joueur;
    delete mot;

    return 0;
}
