#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<string> prenoms;

    prenoms.push_back("Alice");
    prenoms.push_back("Bob");
    prenoms.push_back("Charlie");

    cout << "Prénoms après ajout : " << endl;
    for (const string& prenom : prenoms) {
        cout << prenom << " ";
    }
    cout << endl;

    prenoms.pop_back();

    cout << "Prénoms après suppression : " << endl;
    for (const string& prenom : prenoms) {
        cout << prenom << " ";
    }
    cout << endl;

    prenoms.push_back("David");

    cout << "Prénoms après modification : " << endl;
    for (const string& prenom : prenoms) {
        cout << prenom << " ";
    }
    cout << endl;

    return 0;
}
