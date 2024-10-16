#include <iostream>
#include <vector>
using namespace std;

void afficherPlaces(const vector<int>& places) {
    cout << "État des places : ";
    for (int i = 0; i < places.size(); i++) {
        cout << (places[i] == 1 ? "Disponible" : "Occupée") << " ";
    }
    cout << endl;
}

void reserverPlace(vector<int>& places, int numero) {
    if (numero >= 0 && numero < places.size()) {
        if (places[numero] == 1) {
            places[numero] = 0;
            cout << "Place " << numero + 1 << " réservée." << endl;
        } else {
            cout << "Place " << numero + 1 << " est déjà occupée." << endl;
        }
    } else {
        cout << "Numéro de place invalide." << endl;
    }
}

void annulerReservation(vector<int>& places, int numero) {
    if (numero >= 0 && numero < places.size()) {
        if (places[numero] == 0) {
            places[numero] = 1;
            cout << "Réservation de la place " << numero + 1 << " annulée." << endl;
        } else {
            cout << "Place " << numero + 1 << " est déjà disponible." << endl;
        }
    } else {
        cout << "Numéro de place invalide." << endl;
    }
}

int main() {
    int nombrePlaces = 10;
    vector<int> places(nombrePlaces, 1);

    afficherPlaces(places);

    int choix, numero;
    while (true) {
        cout << "1. Réserver une place\n2. Annuler une réservation\n3. Quitter\nChoix : ";
        cin >> choix;

        if (choix == 1) {
            cout << "Entrez le numéro de la place à réserver (1 à " << nombrePlaces << ") : ";
            cin >> numero;
            reserverPlace(places, numero - 1);
        } else if (choix == 2) {
            cout << "Entrez le numéro de la place à annuler (1 à " << nombrePlaces << ") : ";
            cin >> numero;
            annulerReservation(places, numero - 1);
        } else if (choix == 3) {
            break;
        } else {
            cout << "Choix invalide." << endl;
        }

        afficherPlaces(places);
    }

    return 0;
}
