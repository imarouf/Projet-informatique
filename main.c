/*
    Mon algorithme :

(1) Gestion des clients:
• Ajouter, modifier, supprimer un client
• Afficher la liste des clients par ordre alphabétique

(2) Gestion des Jet:
• Ajouter, modifier, supprimer un jet
• Afficher la liste des jets par ordre alphabétique (titre)

(3) Gestion des emprunts:
Projet d’Algorithmique et Programmation en C 2023-24 Page 5 sur 6
• Emprunter, rendre un jet
• Afficher la liste des jet empruntés
• Afficher la liste des jet empruntés par un client

(4) Quitter le programme de test.



*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "gestionClient/gestionClient.h"
#include "gestionJet/gestionJet.h"
#include "gestionLocation/gestionLocation.h"
#include "menu/menu.h"

#define CMAX 20

int main()
{
    int choix;
    FILE *listeClient = fopen("gestionClient/listeClient.txt", "r+");
    // ajouter_client(listeClient);
    // modifier_client(listeClient,1);
    
    afficherMenuPrincipal();
    printf("\nChoisissez une option (1-4) : ");
    scanf("%d", &choix);

    do
    {
        {
            switch ((choix))
            {
            case 1:
                afficherMenuGestionClient();
                break;
            case 2:
                afficherMenuGestionJets();
                break;
            case 3:
                // afficherMenuLocations();
                break;

            case 4:
                return 0;
            }
        }
    } while (choix != 4);

    fclose(listeClient); // Youpi on perd pas 1 point
}