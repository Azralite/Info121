#include "animal.hpp"

const int gridSize = 20;

using grille = animal [gridSize][gridSize];

void grilleVide(grille g);

void copieGrille(grille g1, grille g2);

animal getAnimal(grille g, coord c);

void setAnimal(grille g,  animal a);
