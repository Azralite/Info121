#include <iostream>
#include <cstdlib>

const int TAILLE = 20;

struct coord{
  int x;
  int y;
};

struct EnsCoord {
   coord tab[TAILLE*TAILLE];
   int taille;
};
// On recopie les fonctions du td
coord creerCoord(int x, int y);

int getX(coord a);

int getY(coord a);

bool egalCoord(coord a, coord b);

int max (int a, int b);

int min(int a, int b);

EnsCoord creeEC();

void ajouteEC(EnsCoord a, coord c);

coord randomEC();

int tailleEC(EnsCoord a);

EnsCoord trouverVoisin(coord c);
