#include "gestionClient.h"
#include <stdio.h>

// Définition de la variable globale partagée
int prochainIndice = 1;

void ajouter_client(FILE *listeClient)
{
    Client client;

    // Rembobiner le fichier au début
    rewind(listeClient);

    // Parcourir le fichier pour obtenir le dernier indice
    while (fscanf(listeClient, "%d %*s %*s", &client.index) == 1)
    {
        if (client.index >= prochainIndice)
        {
            prochainIndice = client.index + 1;
        }
    }

    // Utiliser le prochain indice disponible
    client.index = prochainIndice;

    printf("\n══════════════════════════════════════════════════\n");
    printf("Saisissez le nom du client :\n");
    printf("══════════════════════════════════════════════════\n");
    printf("Nom : ");
    scanf("%s", client.nom);
    printf("\n══════════════════════════════════════════════════\n");
    printf("Saisissez le prénom du client :\n");
    printf("══════════════════════════════════════════════════\n");
    printf("prénom : ");
    scanf("%s", client.prenom);
    // Incrémenter le prochain indice disponible
    prochainIndice++;

    // Aller à la fin du fichier pour ajouter le nouveau client
    fseek(listeClient, 0, SEEK_END);
    fprintf(listeClient, "%d %s %s\n", client.index, client.nom, client.prenom);

    fclose(listeClient);
}
// Regarder tmpnam
void modifier_client(FILE *listeClient)
{
    FILE *tempFile = fopen("tempClient.txt", "w");
    rewind(listeClient); // J'ai passé 2h pour me rendre compte de l'erreur

    if (tempFile == NULL)
    {
        perror("Erreur lors de la création du fichier temporaire");
        return;
    }

    Client nouveauClient;
    char nomModifie[CMAX], prenomModifie[CMAX];
    printf("\n══════════════════════════════════════════════════\n");
    printf("Saisissez le nom du client à modifier :\n");
    printf("══════════════════════════════════════════════════\n");
    printf("Nom : ");
    scanf("%s", nomModifie);
    printf("\n══════════════════════════════════════════════════\n");
    printf("Saisissez le prénom du client à modifier :\n");
    printf("══════════════════════════════════════════════════\n");
    printf("Nom : ");
    scanf("%s", prenomModifie);
    // Utilisation de la fonction strcmp pour comparer deux chaines de caractères
    while (fscanf(listeClient, "%d %s %s", &nouveauClient.index, nouveauClient.nom, nouveauClient.prenom) != EOF)
    {
        if (strcmp(nouveauClient.nom, nomModifie) == 0 && strcmp(nouveauClient.prenom, prenomModifie) == 0)
        {
            // On demande de saisir les infos à l'utilisateur
            printf("\n══════════════════════════════════════════════════\n");
            printf("Saisissez le nouveau nom du client :\n");
            printf("══════════════════════════════════════════════════\n");
            printf("Nouveau nom : ");
            scanf("%s", nouveauClient.nom);
            printf("Saisissez le nouveau prénom du client : \n");
            printf("\n══════════════════════════════════════════════════\n");
            printf("Saisissez le prénom du client :\n");
            printf("══════════════════════════════════════════════════\n");
            printf("Nouveua prénom : ");
            scanf("%s", nouveauClient.prenom);
            // On les insère dans le fichier temporaire
            fprintf(tempFile, "%d %s %s\n", nouveauClient.index, nouveauClient.nom, nouveauClient.prenom);

            printf("Le client a été modifié avec succès.\n");
        }
        else
        {
            fprintf(tempFile, "%d %s %s\n", nouveauClient.index, nouveauClient.nom, nouveauClient.prenom);
        }
    }

    fclose(tempFile);
    fclose(listeClient);

    if (remove(FICHIER_CLIENT) != 0)
    {
        perror("Erreur lors de la suppression du fichier d'origine");
        return;
    }

    if (rename("tempClient.txt", FICHIER_CLIENT) != 0)
    {
        perror("Erreur lors du remplacement du fichier");
        return;
    }

    listeClient = fopen(FICHIER_CLIENT, "a+");
    if (listeClient == NULL)
    {
        perror("Erreur lors de l'ouverture du fichier clients.txt après le remplacement");
        return;
    }
}

void supprimer_client(FILE *listeClient)
{
    FILE *tempFile = fopen("temp.txt", "w");
    if (tempFile == NULL)
    {
        perror("Erreur lors de la création du fichier temporaire");
        return;
    }
    Client clientASupprime;

    char nomSupprime[CMAX], prenomSupprime[CMAX];

    printf("\n══════════════════════════════════════════════════\n");
    printf("Saisissez le nom du client à supprimer :\n");
    printf("══════════════════════════════════════════════════\n");
    scanf("%s", nomSupprime);
    printf("\n══════════════════════════════════════════════════\n");
    printf("Saisissez le prénom du client à supprimer :\n");
    printf("══════════════════════════════════════════════════\n");
    scanf("%s", prenomSupprime);
    // Rembobiner le fichier au début
    rewind(listeClient);
    // Parcourir le fichier pour copier les clients dans le fichier temporaire
    while (fscanf(listeClient, "%d %s %s", &clientASupprime.index, clientASupprime.nom, clientASupprime.prenom) != EOF)
    {
        if (strcmp(clientASupprime.nom, nomSupprime) != 0 && strcmp(clientASupprime.prenom, prenomSupprime) != 0)
        {
            // Copier le client dans le fichier temporaire si ce n'est pas celui à supprimer
            fprintf(tempFile, "%d %s %s\n", clientASupprime.index, clientASupprime.nom, clientASupprime.prenom);
        }
        else
        {
            printf("Le client %s %s a été supprimé avec succès.\n", nomSupprime, prenomSupprime);
        }
    }
    fclose(tempFile);
    fclose(listeClient);
    // Supprimer le fichier d'origine
    if (remove(FICHIER_CLIENT) != 0)
    { // PEnser a constante ENOENT et EACCESAS
        perror("Erreur lors de la suppression du fichier d'origine");
        return;
    }
    // Renommer le fichier temporaire pour remplacer le fichier d'origine
    if (rename("temp.txt", FICHIER_CLIENT) != 0)
    {
        perror("Erreur lors du remplacement du fichier");
        return;
    }

    // Ouvrir à nouveau le fichier d'origine en mode append pour permettre les opérations ultérieures
    listeClient = fopen(FICHIER_CLIENT, "a+");
    if (listeClient == NULL)
    {
        perror("Erreur lors de l'ouverture du fichier clients.txt après le remplacement");
        return;
    }
}

void afficher_liste_client_ordre_alphabetique(FILE *listeClient)
{
    // listeClient = fopen(FICHIER_CLIENT)
}
