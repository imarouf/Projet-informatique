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

int main()
{
    // Utilisation de "a+" pour permettre la lecture et l'écriture en fin de fichier
    FILE *fichierClient = fopen(FICHIER_CLIENT, "a+");

    int choixMenu;
    while (1)
    {
        afficherMenuPrincipal(&choixMenu);
        switch (choixMenu)
        {
        case 1:
            afficherMenuGestionClient(fichierClient);
            break;
        case 2:
            afficherMenuGestionJet(fichierClient);
            break;
        case 3:
            afficherMenuLocation(fichierClient);
            break;
        case 4:
            printf("Fin du programme.\n");
            return 0;
        default:
            printf("Choix invalide, veuillez réessayer.\n");
        }
    }
    
    // Fermez le fichier
    fclose(fichierClient);
    return 0; // Termine le programme avec succès
}