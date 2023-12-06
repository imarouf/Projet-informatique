#ifndef gestionLocation_h
#define gestionLocation_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../gestionClient/gestionClient.h"
#include "../gestionJet/gestionJet.h"

#define FICHIER_LOCATION "listeLocation.txt"

void emprunterJet(FILE *listeLocation);
void rendreJet(FILE *listeLocation);
void afficherJetEmprunte(FILE *listeLocation);
void afficherListeDesEmprunts(FILE *listeLocation);

#endif