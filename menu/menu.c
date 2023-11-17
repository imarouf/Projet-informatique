#include "menu.h"
#include "../gestionClient/gestionClient.h"

void afficherMenuPrincipal(int *choix)
{
    printf("==== Menu Principal ====\n");
    printf("1. Gestion des Clients\n");
    printf("2. Gestion des Jets\n");
    printf("3. Gestion des locations\n");
    printf("4. Quitter\n");
    printf("Entrez votre choix : ");
    scanf("%d", choix);
}

void afficherMenuGestionClient(FILE *listeClient)
{
    int choixSousMenu;
    printf("\n==== Gestion des clients ====\n");
    printf("1.1 Ajouter un client\n");
    printf("1.2 Modifier un produit\n");
    printf("1.3 Supprimer un produit\n");
    printf("1.4 Retour au menu principal\n");
    printf("Faites votre choix : ");
    scanf("%d", &choixSousMenu);
    switch (choixSousMenu)
    {
    case 1:
        ajouter_client(listeClient);
    case 2:
        // modifier_client();
        break;
    case 3:
        // supprimer_client(fichierClient);
        break;
    case 4:
        break;
    }
}

void afficherMenuGestionJet(FILE *listeClient)
{
    int choixSousMenu;
    printf("\n==== Gestion des Jets ====\n");
    printf("2.1 Ajouter un jet\n");
    printf("2.2 Modifier un jet\n");
    printf("2.3 Supprimer un jet\n");
    printf("2.4 Retour au menu principal\n");
    printf("Faites votre choix : ");
    scanf("%d", &choixSousMenu);
    switch (choixSousMenu)
    {
    case 1:
        ajouter_client(listeClient);
        break;
    case 2:
        // modifier_client();
        break;
    case 3:
        // supprimer_client(fichierClient);
        break;
    case 4:
        break;
    }
}

void afficherMenuLocation(FILE *listeClient)
{
    int choixSousMenu;
    printf("Gestion des emprunts de jet\n");
    printf("3.1 Ajouter un emprunt de jet\n");
    printf("3.2 Modifier emprunt de jet\n");
    printf("3.3 Supprimer un emprunt \n");
    printf("3.4 Retour au menu principal\n");
    printf("Faites votre choix : ");
    scanf("%d", &choixSousMenu);

    switch (choixSousMenu)
    {
    case 1:
        ajouter_client(listeClient);
        break;
    case 2:
        // modifier_client();
        break;
    case 3:
        // supprimer_client(fichierClient);
        break;
    case 4:
        break;
    }
}