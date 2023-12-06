#include "gestionLocation.h"

void emprunterJet(FILE *fichierLocation)
{
    Client emprunteur;
    Jet jetEmprunte;
    printf("Dites nous qui vous êtes :\nNom : ");
    scanf("&s", emprunteur.nom);
    printf("Prénom : ");
    scanf("&s", emprunteur.prenom);

    printf("Quel jet voulez vous emprunter ? ");
    scanf("s", jetEmprunte.modele);

}