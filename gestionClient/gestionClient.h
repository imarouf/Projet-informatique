#ifndef gestionClient_h
#define gestionClient_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CMAX 20

// client#include "menu.h"
typedef struct SClient
{
    int cli_Index;         // numéro client (unique)
    char cli_Nom[CMAX];    // Nom du client
    char cli_Prenom[CMAX]; // Prénom du client
} Client;

void ajouter_client(FILE *listeClient);
void modifier_client(FILE *listeClient, int index);
void supprimer_client(FILE *listeClient);
void afficher_liste_client_ordre_alphabetique(FILE *listeClient);

#endif
