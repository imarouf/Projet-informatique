#ifndef menu_h
#define menu_h

#include <stdio.h>
#include <stdlib.h>

#include "../gestionClient/gestionClient.h"
#include "../gestionJet/gestionJet.h"
#include "../gestionLocation/gestionLocation.h"

void afficherMenuPrincipal(int *choix);
void afficherMenuGestionClient(FILE *listeClient);
void afficherMenuGestionJet(FILE *listeJet);
void afficherMenuLocation(FILE *listeLocation);

#endif
