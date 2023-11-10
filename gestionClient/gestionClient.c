#include "gestionClient.h"
#include <stdio.h>

void ajouter_client(FILE *listeClient)
{
    Client client;
    client.cli_Index = ftell(listeClient) / sizeof(Client) + 1;
    printf("Saisissez le nom du client : \n");
    scanf("%s", client.cli_Nom);
    printf("Saisissez le prénom du client : \n");
    scanf("%s", client.cli_Prenom);
    fprintf(listeClient, "%d %s %s\n", client.cli_Index, client.cli_Nom, client.cli_Prenom);
}

void modifier_client(FILE *listeClient, int index)
{
    rewind(listeClient); // Retour au début du fichier

    Client client;

    // Parcourez le fichier jusqu'au client que vous souhaitez modifier
    while (fscanf(listeClient, "%d %s %s", &client.cli_Index, client.cli_Nom, client.cli_Prenom) == 3)
    {
        if (client.cli_Index == index)
        {
            // Effectuez les modifications nécessaires ici
            printf("Saisissez le nouveau nom du client : \n");
            scanf("%s", client.cli_Nom);
            printf("Saisissez le nouveau prénom du client : \n");
            scanf("%s", client.cli_Prenom);

            // Revenez à la position précédente dans le fichier et écrivez les modifications
            fseek(listeClient, -sizeof(Client), SEEK_CUR);
            fprintf(listeClient, "%d %s %s\n", client.cli_Index, client.cli_Nom, client.cli_Prenom);

            printf("Client modifié avec succès.\n");
            return;
        }
    }

    printf("Client non trouvé.\n");
}

void supprimer_client(FILE *listeClient)
{
}

void afficher_liste_client_ordre_alphabetique(FILE *listeClient)
{
}
