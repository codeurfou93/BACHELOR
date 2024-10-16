#include <iostream>
#include <vector>
using namespace std;

int main() {
    const int jours = 7;
    const int produits = 3;
    vector<vector<double>> ventes(produits, vector<double>(jours));

    for (int i = 0; i < produits; i++) {
        cout << "Entrez les ventes pour le produit " << (i + 1) << " sur 7 jours : " << endl;
        for (int j = 0; j < jours; j++) {
            cout << "Jour " << (j + 1) << ": ";
            cin >> ventes[i][j];
        }
    }

    cout << "Total des ventes pour chaque produit : " << endl;
    for (int i = 0; i < produits; i++) {
        double total = 0;
        for (int j = 0; j < jours; j++) {
            total += ventes[i][j];
        }
        cout << "Produit " << (i + 1) << ": " << total << endl;
    }

    return 0;
}
