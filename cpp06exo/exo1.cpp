#include <iostream>
#include <string>
using namespace std;

class Animal {
private:
    string nom;
    int age;

public:
    Animal(string n, int a) : nom(n), age(a) {}

    void afficher() const {
        cout << "Nom : " << nom << ", Âge : " << age << " ans" << endl;
    }
};

int main() {
    Animal animal1("Chien", 5);
    Animal animal2("Chat", 3);

    cout << "Informations sur les animaux :" << endl;
    animal1.afficher();
    animal2.afficher();

    return 0;
}
