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
    while (fscanf(listeClient, "%d %*s %*s", &client.index) == 1) {
        if (client.index >= prochainIndice) {
            prochainIndice = client.index + 1;
        }
    }

    // Utiliser le prochain indice disponible
    client.index = prochainIndice;

    printf("Saisissez le nom du client : \n");
    scanf("%s", client.nom);
    printf("Saisissez le prénom du client : \n");
    scanf("%s", client.prenom);

    // Incrémenter le prochain indice disponible
    prochainIndice++;

    // Aller à la fin du fichier pour ajouter le nouveau client
    fseek(listeClient, 0, SEEK_END);
    fprintf(listeClient, "%d %s %s\n", client.index, client.nom, client.prenom);
}


void modifier_client(FILE *listeClient, int index)
{
    FILE *tempFile = fopen("temp.txt", "w");
    rewind(listeClient); // J'ai passé 2h pour me rendre compte de l'erreur

    if (tempFile == NULL)
    {
        perror("Erreur lors de la création du fichier temporaire");
        return;
    }

    Client nouveauClient;

    while (fscanf(listeClient, "%d %s %s", &nouveauClient.index, nouveauClient.nom, nouveauClient.prenom) != EOF)
    {
        if (nouveauClient.index == index)
        {
            // On demande de saisir les infos à l'utilisateur
            printf("Saisissez le nouveau nom du client : \n");
            scanf("%s", nouveauClient.nom);
            printf("Saisissez le nouveau prénom du client : \n");
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

    if (remove("listeClient.txt") != 0)
    {
        perror("Erreur lors de la suppression du fichier d'origine");
        return;
    }

    if (rename("temp.txt", "listeClient.txt") != 0)
    {
        perror("Erreur lors du remplacement du fichier");
        return;
    }

    listeClient = fopen("listeClient.txt", "a+");
    if (listeClient == NULL)
    {
        perror("Erreur lors de l'ouverture du fichier clients.txt après le remplacement");
        return;
    }
}

// ...

void afficher_client(FILE *listeClient, int index_recherche)
{
    Client client;

    // Rembobiner le fichier au début
    rewind(listeClient);

    // Parcourir le fichier pour trouver le client avec l'index spécifié
    while (fscanf(listeClient, "%d %s %s", &client.index, client.nom, client.prenom) != EOF)
    {
        if (client.index == index_recherche)
        {
            // Afficher les détails du client
            printf("Index : %d\n", client.index);
            printf("Nom : %s\n", client.nom);
            printf("Prénom : %s\n", client.prenom);

            return; // Sortir de la fonction dès que le client est trouvé
        }
    }

    // Si l'index n'est pas trouvé, afficher un message
    printf("Aucun client trouvé avec l'index %d.\n", index_recherche);
}

void supprimer_client(FILE *listeClient, int index_suppression)
{
    FILE *tempFile = fopen("temp.txt", "w");

    if (tempFile == NULL)
    {
        perror("Erreur lors de la création du fichier temporaire");
        return;
    }
    Client client;
    // Rembobiner le fichier au début
    rewind(listeClient);
    // Parcourir le fichier pour copier les clients dans le fichier temporaire
    while (fscanf(listeClient, "%d %s %s", &client.index, client.nom, client.prenom) != EOF)
    {
        if (client.index != index_suppression)
        {
            // Copier le client dans le fichier temporaire si ce n'est pas celui à supprimer
            fprintf(tempFile, "%d %s %s\n", client.index, client.nom, client.prenom);
        }
        else
        {
            printf("Le client avec l'index %d a été supprimé avec succès.\n", index_suppression);
        }
    }

    fclose(tempFile);
    fclose(listeClient);

    // Supprimer le fichier d'origine
    if (remove("listeClient.txt") != 0)
    {
        perror("Erreur lors de la suppression du fichier d'origine");
        return;
    }

    // Renommer le fichier temporaire pour remplacer le fichier d'origine
    if (rename("temp.txt", "listeClient.txt") != 0)
    {
        perror("Erreur lors du remplacement du fichier");
        return;
    }

    // Ouvrir à nouveau le fichier d'origine en mode append pour permettre les opérations ultérieures
    listeClient = fopen("listeClient.txt", "a+");
    if (listeClient == NULL)
    {
        perror("Erreur lors de l'ouverture du fichier clients.txt après le remplacement");
        return;
    }
}

void afficher_liste_client_ordre_alphabetique(FILE *listeClient)
{
}
