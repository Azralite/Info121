#include "grille.hpp"

const int gridSize = 20

int hasard(int val);
  
bool seReproduitAnimal(animal a, EnsCoord c);

void initialiseGrille(const grille &g);

void verifieGrille(const grille &g);

EnsCoord voisinsEspece(const grille &g, coord c, espece e);

ensCoord toutEspece(grille g, espece e);

void deplaceTousLapins(grille g1, grille g2);

void deplaceTousRenards(grille g1, grille g2);

void updateGrille(grille g1, grille g2);

void afficheGrille(grille g);
