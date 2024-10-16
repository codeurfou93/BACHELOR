#include <iostream>
#include <vector>
#include <string>
using namespace std;

int longueurTotale(vector<string> const& chaines) {
    int total = 0;
    for (const string& chaine : chaines) {
        total += chaine.size();
    }
    return total;
}

int main() {
    vector<string> noms = {"Alice", "Bob", "Charlie", "David"};
    int totalLongueur = longueurTotale(noms);
    
    cout << "La longueur totale des chaînes est : " << totalLongueur << endl;

    return 0;
}
