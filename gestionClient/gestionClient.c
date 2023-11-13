#include "gestionClient.h"
#include <stdio.h>

void ajouter_client(FILE *listeClient)
{
    Client client;
    int nombreClients = 0;

    // Aller au début du fichier pour lire le nombre actuel de clients
    rewind(listeClient);

    // Lire le nombre actuel de clients dans le fichier
    while (fscanf(listeClient, "%*d %*s %*s\n") != EOF)
    {
        nombreClients++;
    }

    // Incrémenter l'index du nouveau client
    client.cli_Index = nombreClients + 1;

    printf("Saisissez le nom du client : \n");
    scanf("%s", client.cli_Nom);
    printf("Saisissez le prénom du client : \n");
    scanf("%s", client.cli_Prenom);

    // Aller à la fin du fichier pour ajouter le nouveau client
    fseek(listeClient, 0, SEEK_END);
    fprintf(listeClient, "%d %s %s\n", client.cli_Index, client.cli_Nom, client.cli_Prenom);
}
// Faire une fonction sauvegarder
void modifier_client(FILE *listeClient, int index) {
    FILE *tempFile = fopen("temp.txt", "w"); // Fichier temporaire pour les modifications

    if (tempFile == NULL) {
        printf("Erreur lors de la création du fichier temporaire.\n");
        return;
    }

    // Créez une nouvelle structure Client pour stocker les modifications
    Client nouveauClient;

    // Parcourez le fichier pour trouver le client avec l'index spécifié
    while (fscanf(listeClient, "%d %s %s\n", nouveauClient.cli_Index, nouveauClient.cli_Nom, nouveauClient.cli_Prenom) != EOF) {
        if (nouveauClient.cli_Index == index) {
            // Trouvé le client, permettez à l'utilisateur de saisir les modifications
            printf("Saisissez le nouveau nom du client : \n");
            scanf("%s", nouveauClient.cli_Nom);
            printf("Saisissez le nouveau prénom du client : \n");
            scanf("%s", nouveauClient.cli_Prenom);

            // Écrivez les modifications dans le fichier temporaire
            fprintf(tempFile, "%d %s %s\n", nouveauClient.cli_Index, nouveauClient.cli_Nom, nouveauClient.cli_Prenom);

            printf("Le client a été modifié avec succès.\n");
        } else {
            // Écrivez les données du client inchangé dans le fichier temporaire
            fprintf(tempFile, "%d %s %s\n", nouveauClient.cli_Index, nouveauClient.cli_Nom, nouveauClient.cli_Prenom);
        }
    }

    // Fermez le fichier temporaire et le fichier d'origine
    fclose(tempFile);
    fclose(listeClient);

    // Renommez le fichier temporaire pour remplacer le fichier d'origine
    if (rename("temp.txt", "listeClient.txt") != 0) {
        printf("Erreur lors du remplacement du fichier.\n");
    }

    // Ouvrez à nouveau le fichier d'origine en mode append pour permettre les opérations ultérieures
    listeClient = fopen("listeClient.txt", "a+");
}


void supprimer_client(FILE *listeClient)
{
}

void afficher_liste_client_ordre_alphabetique(FILE *listeClient)
{
    Client client;

    rewind(listeClient);

    int ligne = 1;

    // Aller au début du fichier pour lire le nombre actuel de clients
    rewind(listeClient);
    printf("Liste des clients par ordre numérique : \n");
    // Lire le nombre actuel de clients dans le fichier
    while (fscanf(listeClient, "%*d %*s %*s\n") != EOF)
    {
        printf("Index : %d\n", client.cli_Index);
        printf("Nom   : %s\n", client.cli_Nom);
        printf("Prénom: %s\n\n", client.cli_Prenom);
        ligne++;
    }
}
