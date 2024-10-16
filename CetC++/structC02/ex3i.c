#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Déclaration de la structure Contact
struct Contact {
    char *nom;    // Pointeur vers une chaîne de caractères pour le nom
    char *numero; // Pointeur vers une chaîne de caractères pour le numéro
};

// Déclaration de la structure Annuaire
struct Annuaire {
    struct Contact *contacts; // Pointeur vers un tableau de Contact
    int nombre_contacts;      // Nombre de contacts
};

// Fonction pour afficher tous les contacts
void afficherAnnuaire(struct Annuaire *annuaire) {
    printf("\n--- Annuaire Téléphonique ---\n");
    for (int i = 0; i < annuaire->nombre_contacts; i++) {
        printf("Contact %d:\n", i + 1);
        printf("Nom: %s\n", annuaire->contacts[i].nom);
        printf("Numéro: %s\n", annuaire->contacts[i].numero);
    }
}

// Fonction principale
int main() {
    struct Annuaire annuaire;
    
    // Demander à l'utilisateur le nombre de contacts
    printf("Combien de contacts souhaitez-vous ajouter ? ");
    scanf("%d", &annuaire.nombre_contacts);
    
    // Allouer de la mémoire pour le tableau de contacts
    annuaire.contacts = (struct Contact *)malloc(annuaire.nombre_contacts * sizeof(struct Contact));
    if (annuaire.contacts == NULL) {
        fprintf(stderr, "Erreur d'allocation mémoire.\n");
        return 1; // Retourner 1 en cas d'erreur
    }

    // Pour chaque contact, allouer de la mémoire pour le nom et le numéro
    for (int i = 0; i < annuaire.nombre_contacts; i++) {
        char buffer[100]; // Utilisé pour lire les entrées de l'utilisateur

        printf("\nSaisissez les détails du contact %d:\n", i + 1);

        printf("Nom: ");
        getchar(); // Pour consommer le caractère de nouvelle ligne précédent
        fgets(buffer, sizeof(buffer), stdin);
        buffer[strcspn(buffer, "\n")] = '\0'; // Enlever le saut de ligne

        // Allouer de la mémoire pour le nom et copier la chaîne
        annuaire.contacts[i].nom = (char *)malloc((strlen(buffer) + 1) * sizeof(char));
        if (annuaire.contacts[i].nom == NULL) {
            fprintf(stderr, "Erreur d'allocation mémoire pour le nom.\n");
            return 1; // Retourner 1 en cas d'erreur
        }
        strcpy(annuaire.contacts[i].nom, buffer);

        printf("Numéro: ");
        fgets(buffer, sizeof(buffer), stdin);
        buffer[strcspn(buffer, "\n")] = '\0'; // Enlever le saut de ligne

        // Allouer de la mémoire pour le numéro et copier la chaîne
        annuaire.contacts[i].numero = (char *)malloc((strlen(buffer) + 1) * sizeof(char));
        if (annuaire.contacts[i].numero == NULL) {
            fprintf(stderr, "Erreur d'allocation mémoire pour le numéro.\n");
            return 1; // Retourner 1 en cas d'erreur
        }
        strcpy(annuaire.contacts[i].numero, buffer);
    }

    // Afficher tous les contacts de l'annuaire
    afficherAnnuaire(&annuaire);

    // Libérer toute la mémoire allouée
    for (int i = 0; i < annuaire.nombre_contacts; i++) {
        free(annuaire.contacts[i].nom);
        free(annuaire.contacts[i].numero);
    }
    free(annuaire.contacts); // Libérer le tableau de contacts

    return 0;
}
