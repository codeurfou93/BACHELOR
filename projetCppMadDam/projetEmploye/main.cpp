#include "Employe.h"
#include <iostream>
#include <vector>

int main() {
    Employe emp1("Alice Dupont", 101, 45000.0, "Informatique");
    Employe emp2("Jean Martin", 102, 50000.0, "Marketing");
    Employe emp3("Lucie Bernard", 103, 55000.0, "Ressources Humaines");

    std::vector<Employe> employes = {emp1, emp2, emp3};

    for (const auto& emp : employes) {
        emp.afficherInfo();
        std::cout << "------------------" << std::endl;
    }

    double salaireTotal = 0.0;
    for (const auto& emp : employes) {
        salaireTotal += emp.getSalaireBase();
    }

    std::cout << "Salaire total des employés: " << salaireTotal << std::endl;

    std::string departementRecherche = "Marketing";
    std::cout << "\nRecherche des employés dans le département " << departementRecherche << ":\n";

    for (const auto& emp : employes) {
        if (emp.getDepartement() == departementRecherche) {
            emp.afficherInfo();
        }
    }

    return 0;
}
