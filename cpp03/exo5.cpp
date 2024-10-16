#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    vector<string> inventaire;
    string article;
    char choix;

    do {
        cout << "Entrez un article à ajouter à l'inventaire : ";
        cin >> article;
        inventaire.push_back(article);
        
        cout << "Inventaire actuel : " << endl;
        for (const string& item : inventaire) {
            cout << item << " ";
        }
        cout << endl;

        cout << "Voulez-vous ajouter un autre article ? (o/n) : ";
        cin >> choix;
    } while (choix == 'o' || choix == 'O');

    cout << "Entrez un article à retirer de l'inventaire : ";
    cin >> article;

    auto it = find(inventaire.begin(), inventaire.end(), article);
    if (it != inventaire.end()) {
        inventaire.erase(it);
        cout << "Article retiré." << endl;
    } else {
        cout << "Article non trouvé dans l'inventaire." << endl;
    }

    cout << "Inventaire final : " << endl;
    for (const string& item : inventaire) {
        cout << item << " ";
    }
    cout << endl;

    return 0;
}
