/*
    Mon algorithme :

Menu :
(1) Gestion des clients:
• Ajouter un client
• Modifier un client
• Supprimer un client
• Afficher la liste des clients par ordre alphabétique (Nom)

(2) Gestion des Jet:
• Ajouter un jet
• Modifier un jet
• Supprimer un jet
• Afficher la liste des jets par ordre alphabétique (Modèle)

(3) Gestion des locations:
• Emprunter un jet
• Rendre un jet
• Afficher la liste des jet loués
• Afficher la liste des jet loués par un client

(4) Quitter le programme de test.

*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "gestionJet/gestionJet.h"
#include "gestionClient/gestionClient.h"
#include "menu/menu.h"

int main()
{
    // Utilisation de "a+" pour permettre la lecture et l'écriture en fin de fichier
    FILE *fichierClient = fopen(FICHIER_CLIENT, "a+");
    FILE *fichierJet = fopen(FICHIER_JET, "a+");
    FILE *fichierLocation = fopen(FICHIER_LOCATION, "a+");
    // ajouter_jet(fichierJet);
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
            afficherMenuGestionJet(fichierJet);
            break;
        case 3:
            afficherMenuLocation(fichierLocation);
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
    fclose(fichierJet);
    fclose(fichierLocation);

    return 0; // Termine le programme avec succès
}