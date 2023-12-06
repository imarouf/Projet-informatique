#include "menu.h"

void afficherMenuPrincipal(int *choix)
{
    printf("\n╔════════════════════════════════╗\n");
    printf("║          Menu Principal        ║\n");
    printf("╠════════════════════════════════╣\n");
    printf("║  1. Gestion des Clients        ║\n");
    printf("║  2. Gestion des Jets           ║\n");
    printf("║  3. Gestion des Locations      ║\n");
    printf("║  4. Quitter                    ║\n");
    printf("╚════════════════════════════════╝\n");
    printf("Entrez votre choix : ");
    scanf("%d", choix);
}

void afficherMenuGestionClient(FILE *listeClient)
{
    int choixSousMenu;
    printf("\n╔════════════════════════════════════╗\n");
    printf("║      Gestion des Clients           ║\n");
    printf("╠════════════════════════════════════╣\n");
    printf("║  1.1 Ajouter un client             ║\n");
    printf("║  1.2 Modifier un client            ║\n");
    printf("║  1.3 Supprimer un client           ║\n");
    printf("║  1.4 Retour au menu principal      ║\n");
    printf("╚════════════════════════════════════╝\n");
    printf("Faites votre choix : ");
    scanf("%d", &choixSousMenu);
    switch (choixSousMenu)
    {
    case 1:
        ajouter_client(listeClient);
        break;
    case 2:
        modifier_client(listeClient);
        break;
    case 3:
        supprimer_client(listeClient);
        break;
    case 4:
        break;
    }
}

void afficherMenuGestionJet(FILE *listeJet)
{
    int choixSousMenu2;
    printf("\n╔════════════════════════════════════╗\n");
    printf("║        Gestion des Jets            ║\n");
    printf("╠════════════════════════════════════╣\n");
    printf("║  2.1 Ajouter un jet                ║\n");
    printf("║  2.2 Modifier un jet               ║\n");
    printf("║  2.3 Supprimer un jet              ║\n");
    printf("║  2.4 Retour au menu principal      ║\n");
    printf("╚════════════════════════════════════╝\n");
    printf("Faites votre choix : ");
    scanf("%d", &choixSousMenu2);
    switch (choixSousMenu2)
    {
    case 1:
        ajouter_jet(listeJet);
        break;
    case 2:
        modifier_jet(listeJet);
        break;
    case 3:
        supprimer_jet(listeJet);
        break;
    case 4:
        break;
    }
}

void afficherMenuLocation(FILE *listeLocation)
{
    int choixSousMenu;
    printf("\n╔═══════════════════════════════════════════════════════╗\n");
    printf("║        Gestion des locations                          ║\n");
    printf("╠═══════════════════════════════════════════════════════╣\n");
    printf("║  3.1 Emprunter un jet                                 ║\n");
    printf("║  3.2 Rendre un jet                                    ║\n");
    printf("║  3.3 Afficher la liste des jets loués                 ║\n");
    printf("║  3.4 Afficher la liste des jet loués par un client    ║\n");
    printf("║  3.5 Retour au menu principal                         ║\n");
    printf("╚═══════════════════════════════════════════════════════╝\n");
    printf("Faites votre choix : ");
    scanf("%d", &choixSousMenu);

    switch (choixSousMenu)
    {
    case 1:
        emprunterJet(listeLocation);
        break;
    case 2:
        rendreJet(listeLocation);
        break;
    case 3:
        afficherJetEmprunte(listeLocation);
        break;
    case 4:
        afficherListeDesEmprunts(listeLocation);
        break;
    case 5:
        break;
    }
}
