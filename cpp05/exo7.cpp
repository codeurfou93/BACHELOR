#include <iostream>
#include <string>
using namespace std;

class Personne {
public:
    string nom;
    int age;

    Personne(string n, int a) : nom(n), age(a) {}
};

void modifierAge(Personne& p, int nouvelAge) {
    p.age = nouvelAge;
}

int main() {
    Personne personne("Alice", 30);
    
    cout << "Avant modification : " << personne.nom << ", Age : " << personne.age << endl;
    
    modifierAge(personne, 35);
    
    cout << "Après modification : " << personne.nom << ", Age : " << personne.age << endl;
    
    return 0;
}
