#ifndef gestionJet_h
#define gestionJet_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CMAX 20
// Jet privé
typedef struct SJet
{
    int jet_Index;
    char jet_Modele[CMAX]; 
    int jet_Gamme; // 1 = basique, 2 = business, 3 = premimum ( 3 choix de modèles par gamme)
} Jet;

void ajouter_jet(Jet *listeJet);
void modifier_jet(Jet *listeJet);
void supprimer_jet(Jet *listeJet);

void afficher_liste_jet_ordre_alphabetique(Jet *jet);

#endif
