#include "gestionLocation.h"

void emprunterJet(FILE *listeLocation)
{
    Client emprunteur;
    Jet jetEmprunte;

    rewind(listeLocation);

    printf("\n══════════════════════════════════════════════════\n");
    printf("Dites nous qui vous êtes :\nNom : ");
    scanf("%s", emprunteur.nom);
    printf("Prénom : ");
    scanf("%s", emprunteur.prenom);
    printf("Quel jet voulez vous emprunter ? ");
    scanf("%s", jetEmprunte.modele);
    printf("\n══════════════════════════════════════════════════\n");

    // Aller à la fin du fichier pour ajouter le nouvel emprunteur
    fseek(listeLocation, 0, SEEK_END);
    fprintf(listeLocation, "%s %s %s\n", emprunteur.nom, emprunteur.prenom, jetEmprunte.modele);

    fclose(listeLocation);
}

void rendreJet(FILE *listeLocation)
{
    FILE *tempFile = fopen("tempLocation.txt", "w");
    if (tempFile == NULL)
    {
        perror("Erreur lors de la création du fichier temporaire");
        return;
    }
    Client emprunteurASupprime;
    Jet jetEmprunteASupprime;

    char nomSupprime[CMAX], prenomSupprime[CMAX], jetSupprime[CMAX];

    printf("\n══════════════════════════════════════════════════\n");
    printf("Dites nous qui vous êtes :\nNom : ");
    scanf("%s", nomSupprime);
    printf("Prénom : ");
    scanf("%s", prenomSupprime);
    printf("Quel jet vous voulez rendre  ? ");
    scanf("%s", jetSupprime);
    printf("\n══════════════════════════════════════════════════\n");
    // Rembobiner le fichier au début
    rewind(listeLocation);

    // Parcourir le fichier pour copier les clients dans le fichier temporaire
    while (fscanf(listeLocation, "%s %s %s", emprunteurASupprime.nom, emprunteurASupprime.prenom, jetEmprunteASupprime.modele) != EOF)
    {
        if (strcmp(emprunteurASupprime.nom, nomSupprime) != 0 && strcmp(emprunteurASupprime.prenom, prenomSupprime) != 0 && strcmp(jetEmprunteASupprime.modele, jetSupprime) != 0)
        {
            // Copier le client dans le fichier temporaire si ce n'est pas celui à supprimer
            fprintf(tempFile, "%d %s %s\n", emprunteurASupprime.index, emprunteurASupprime.nom, emprunteurASupprime.prenom);
        }
        else
        {
            printf("L'emprunt du jet %s par %s %s à bien été supprimé ! \n", jetSupprime, nomSupprime, prenomSupprime);
        }
    }
    fclose(tempFile);
    fclose(listeLocation);
    // Supprimer le fichier d'origine
    if (remove(FICHIER_LOCATION) != 0)
    { // PEnser a constante ENOENT et EACCESAS
        perror("Erreur lors de la suppression du fichier d'origine");
        return;
    }
    // Renommer le fichier temporaire pour remplacer le fichier d'origine
    if (rename("tempLocation.txt", FICHIER_LOCATION) != 0)
    {
        perror("Erreur lors du remplacement du fichier");
        return;
    }

    // Ouvrir à nouveau le fichier d'origine en mode append pour permettre les opérations ultérieures
    listeLocation = fopen(FICHIER_LOCATION, "a+");
    if (listeLocation == NULL)
    {
        perror("Erreur lors de l'ouverture du fichier clients.txt après le remplacement");
        return;
    }
}

void afficherJetEmprunte(FILE *listeLocation)
{
    Client emprunteur;
    Jet jet;

    rewind(listeLocation);
    printf("══════════════════════════════════════════════════\n");
    printf("Liste des jets empruntés : \n");
    while (fscanf(listeLocation, "%s %s %s", emprunteur.nom, emprunteur.prenom, jet.modele) != EOF)
    {
        printf("- %s\n", jet.modele);
    }
    printf("══════════════════════════════════════════════════\n");
}
void afficherListeDesEmprunts(FILE *listeLocation)
{
    Client emprunteur;
    Jet jet;

    char nomEmprunteurCherche[CMAX];
    char prenomEmprunteurCherche[CMAX];

    printf("\n══════════════════════════════════════════════════\n");
    printf("Dites nous qui vous êtes :\nNom : ");
    scanf("%s", nomEmprunteurCherche);
    printf("Prénom : ");
    scanf("%s", prenomEmprunteurCherche);
    printf("\n══════════════════════════════════════════════════\n");

    rewind(listeLocation);
    printf("Liste des jets empruntés par le client: \n");
    while (fscanf(listeLocation, "%s %s %s", emprunteur.nom, emprunteur.prenom, jet.modele) != EOF)
    {
        if (strcmp(emprunteur.nom, nomEmprunteurCherche) == 0 && strcmp(emprunteur.prenom, prenomEmprunteurCherche) == 0)
        {
            // Le client n'a rien loué
            printf("- %s\n", jet.modele);
        }
    }
    printf("══════════════════════════════════════════════════\n");
}