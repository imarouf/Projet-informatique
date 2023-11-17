#ifndef gestionClient_h
#define gestionClient_h

#define FICHIER_CLIENT "listeClient.txt"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CMAX 20

// client#include "menu.h"
typedef struct SClient
{
    int index;         // numéro client (unique)
    char nom[CMAX];    // Nom du client
    char prenom[CMAX]; // Prénom du client
} Client;

// Déclaration de la variable globale partagée
extern int prochainIndice;

void ajouter_client(FILE *listeClient); // numero de la ligne où ajouter le client
void modifier_client(FILE *listeClient, int index);
void supprimer_client(FILE *listeClient,int index_suppression);
//void afficher_liste_client_ordre_alphabetique(FILE *listeClient);

#endif
