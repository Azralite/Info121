#include <iostream>
#include <cstdlib>

const int gridSize = 20
using grille = animal [gridSize][gridSize]

void grilleVide(grille &g);

void copieGrille(const grille &g1, grille &g2);

animal getAnimal(const grille &g, const coord &c);

animal setAnimal(grille &g, const animal &p);

void initialiseGrille(const grille &g);

void verifieGrille(const grille &g);

EnsCoord voisinsVides(const coord &c, const grille &g);
