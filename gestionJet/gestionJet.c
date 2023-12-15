#include "gestionJet.h"
#include <stdio.h>

// Définition de la variable globale partagée
int prochaineIndiceJet = 1;

void ajouter_jet(FILE *listeJet)
{
    Jet jet;
    // Rembobiner le fichier au début
    rewind(listeJet);
    // Parcourir le fichier pour obtenir le dernier indice
    while (fscanf(listeJet, "%d %*s %*d", &jet.index) == 1)
    {
        if (jet.index >= prochaineIndiceJet)
        {
            prochaineIndiceJet = jet.index + 1;
        }
    }
    // Utiliser le prochain indice disponible
    jet.index = prochaineIndiceJet;

    printf("\n══════════════════════════════════════════════════\n");
    printf("Saisissez le nouveau modèle du jet :\n");
    printf("Modèle : ");
    scanf("%s", jet.modele);
    printf("Saisissez la nouvelle gamme du jet :\n");
    printf("  1. Basique\n");
    printf("  2. Premium\n");
    printf("  3. Deluxe\n");
    scanf("%d", &(jet.gamme));
    printf("══════════════════════════════════════════════════\n");

    // Incrémenter le prochain indice disponible
    prochaineIndiceJet++;

    // Aller à la fin du fichier pour ajouter le nouveau jet
    fseek(listeJet, 0, SEEK_END);
    fprintf(listeJet, "%d %s %d\n", jet.index, jet.modele, jet.gamme);

}

void modifier_jet(FILE *listeJet)
{
    FILE *tempFileJet = fopen("tempJet.txt", "w");
    rewind(listeJet); // J'ai passé 2h pour me rendre compte de l'erreur

    if (tempFileJet == NULL)
    {
        perror("Erreur lors de la création du fichier temporaire");
        return;
    }

    Jet nouveauJet;
    char modeleModifie[CMAX];
    int gammeModifie;
    printf("\n══════════════════════════════════════════════════\n");
    printf("Saisissez le modèle du jet à modifier :\n");
    printf("Modèle : ");
    scanf("%s", modeleModifie);
    printf("\n══════════════════════════════════════════════════\n");
    // Utilisation de la fonction strcmp pour comparer deux chaines de caractères
    while (fscanf(listeJet, "%d %s %d", &nouveauJet.index, nouveauJet.modele, &nouveauJet.gamme) != EOF)
    {
        if (strcmp(nouveauJet.modele, modeleModifie) == 0)
        {
            // On demande de saisir les infos à l'utilisateur
            printf("\n══════════════════════════════════════════════════\n");
            printf("Saisissez le nouveau modèle du jet :\n");
            scanf("%s", nouveauJet.modele);
            printf("Saisissez la nouvelle gamme du jet  : \n");
            scanf("%d", &(nouveauJet.gamme));
            printf("══════════════════════════════════════════════════\n");
            // On les insère dans le fichier temporaire
            fprintf(tempFileJet, "%d %s %d\n", nouveauJet.index, nouveauJet.modele, nouveauJet.gamme);

            printf("Le jet a été modifié avec succès.\n");
        }
        else
        {
            fprintf(tempFileJet, "%d %s %d\n", nouveauJet.index, nouveauJet.modele, nouveauJet.gamme);
        }
    }

    fclose(tempFileJet);
    
    if (remove(FICHIER_JET) != 0)
    {
        perror("Erreur lors de la suppression du fichier d'origine");
        return;
    }

    if (rename("tempJet.txt", FICHIER_JET) != 0)
    {
        // On demande de saisir les infos à l'utilisateur
        perror("Erreur lors du remplacement du fichier");
        return;
    }

    listeJet = fopen(FICHIER_JET, "a+");
    if (listeJet == NULL)
    {
        perror("Erreur lors de l'ouverture du fichier clients.txt après le remplacement");
        return;
    }
}

void supprimer_jet(FILE *listeJet)
{
    FILE *tempFile = fopen("tempJet.txt", "w");
    if (tempFile == NULL)
    {
        perror("Erreur lors de la création du fichier temporaire");
        return;
    }
    Jet jetASupprime;

    char modeleSupprime[CMAX];

    printf("\n══════════════════════════════════════════════════\n");
    printf("Saisissez la modèle de jet à supprimer  : \n");
    scanf("%s", modeleSupprime);
    printf("══════════════════════════════════════════════════\n");

    // Rembobiner le fichier au début
    rewind(listeJet);
    // Parcourir le fichier pour copier les clients dans le fichier temporaire
    while (fscanf(listeJet, "%d %s %d", &jetASupprime.index, jetASupprime.modele, &jetASupprime.gamme) != EOF)
    {
        if (strcmp(jetASupprime.modele, modeleSupprime) != 0)
        {
            // Copier le client dans le fMenu :ichier temporaire si ce n'est pas celui à supprimer
            fprintf(tempFile, "%d %s %d\n", jetASupprime.index, jetASupprime.modele, jetASupprime.gamme);
        }
        else
        {
            printf("Le jet %s a été supprimé avec succès.\n", modeleSupprime);
        }
    }
    fclose(tempFile);
    // Supprimer le fichier d'origine
    if (remove(FICHIER_JET) != 0)
    { // PEnser a constante ENOENT et EACCESAS
        perror("Erreur lors de la suppression du fichier d'origine");
        return;
    }
    // Renommer le fichier temporaire pour remplacer le fichier d'origine
    if (rename("tempJet.txt", FICHIER_JET) != 0)
    {
        perror("Erreur lors du remplacement du fichier");
        return;
    }

    // Ouvrir à nouveau le fichier d'origine en mode append pour permettre les opérations ultérieures
    listeJet = fopen(FICHIER_JET, "a+");
    if (listeJet == NULL)
    {
        perror("Erreur lors de l'ouverture du fichier clients.txt après le remplacement");
        return;
    }
}
