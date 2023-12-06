#ifndef gestionClient_h
#define gestionClient_h


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FICHIER_CLIENT "listeClient.txt"

#define CMAX 20

// Déclaration de la variable globale partagée
extern int prochainIndice;

// client#include "menu.h"
typedef struct SClient
{
    int index;         // numéro client (unique)
    char nom[CMAX];    // Nom du client
    char prenom[CMAX]; // Prénom du client
} Client;


void ajouter_client(FILE *listeClient); // numero de la ligne où ajouter le client
void modifier_client(FILE *listeClient);
void supprimer_client(FILE *listeClient);
//void afficher_liste_client_ordre_alphabetique(FILE *listeClient);

#endif
