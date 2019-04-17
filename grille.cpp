#include <iostream>
#include <cstdlib>
#include "animal.hpp"

const int gridSize = 20;
using grille = animal [gridSize][gridSize];

void grilleVide(grille &g){
	for(int i = 0; i < gridSize; i++)
		for(int n = 0; n < gridSize; n++)
			g[i][n] = creerAnimal(vide, {i,n});
}

void copieGrille(const grille &g1, grille &g2){
	g2 = g1;
}

animal getAnimal(const grille &g, const coord &c){
	int x = getX(c);
	int y = getY(c);
	return g[x][y];
}

void setAnimal(grille &g, const animal &a){
	int x = coordAnimal(a);
	int y = coordAnimal(a);
	g[x][y] = a;
}
