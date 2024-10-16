#include "pendu.h"
#include <fstream>
#include <iostream>

// Sauvegarde de l'état du jeu
void sauvegarderPartie(const Joueur& joueur, const Mot& mot, const std::string& nomFichier) {
    std::ofstream fichier(nomFichier);
    if (fichier) {
        fichier << joueur.getTentativesRestantes() << std::endl; // Sauvegarde des tentatives restantes
        fichier << mot.getMot() << std::endl; // Sauvegarde du mot à deviner
        // Sauvegarde des lettres devinées
        for (char lettre : mot.getLettresDevinees()) {
            fichier << lettre << " ";
        }
        fichier << std::endl;
    } else {
        std::cerr << "Erreur lors de l'ouverture du fichier de sauvegarde." << std::endl;
    }
}

// Chargement de l'état du jeu
bool chargerPartie(Joueur& joueur, Mot& mot, const std::string& nomFichier) {
    std::ifstream fichier(nomFichier);
    if (fichier) {
        int tentatives;
        fichier >> tentatives; // Chargement des tentatives restantes
        joueur.setTentatives(tentatives); // Mettre à jour le joueur

        std::string motADeviner;
        fichier >> motADeviner; // Chargement du mot
        mot.setMot(motADeviner); // Mettre à jour le mot

        char lettre;
        while (fichier >> lettre) { // Chargement des lettres devinées
            mot.revelerLettre(lettre);
        }
        return true;
    } else {
        std::cerr << "Erreur lors de l'ouverture du fichier de chargement." << std::endl;
        return false;
    }
}
