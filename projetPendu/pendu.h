#ifndef PENDU_H
#define PENDU_H

#include <string>
#include <vector>

std::string initialiserMot(const std::string& nomFichier);
void afficherMot(const std::string& mot, const std::vector<bool>& lettresDevinees);
bool verifierLettre(char lettre, const std::string& mot, std::vector<bool>& lettresDevinees);
void afficherErreurs(const std::vector<char>& lettresRatees);
bool verifierVictoire(const std::vector<bool>& lettresDevinees);
std::vector<std::string> lireListeMots(const std::string& nomFichier);

#endif