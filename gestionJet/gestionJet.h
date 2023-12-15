#ifndef gestionJet_h
#define gestionJet_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CMAX 20

#define FICHIER_JET "listeJet.txt"

// Variable globale partagée
extern int prochainIndiceJet;

typedef struct SJet
{
    int index;
    char modele[CMAX]; 
    int gamme;                      // 1 = basique, 2 = business, 3 = premimum ( 3 choix de modèles par gamme)
} Jet;

void ajouter_jet(FILE *listeJet);
void modifier_jet(FILE *listeJet);
void supprimer_jet(FILE *listeJet);

//void afficher_liste_jet_ordre_alphabetique(Jet *jet);

#endif
