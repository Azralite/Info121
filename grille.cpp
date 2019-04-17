#include "grille.hpp"
//#include "animal.hpp"

//const int gridSize = 20;
using grille = animal [gridSize][gridSize];

void grilleVide(grille g){
	for(int i = 0; i < gridSize; i++)
		for(int n = 0; n < gridSize; n++)
			g[i][n] = creerAnimal(vide, {i,n});
}

void copieGrille(grille g1, grille g2){
	g2 = g1;
}

animal getAnimal(grille g, const coord &c){
	int x = getX(c);
	int y = getY(c);
	return g[x][y];
}

void setAnimal(grille g, const animal &a){
	int x = getX(coordAnimal(a));
	int y = getY(coordAnimal(a));
	g[x][y] = a;
}
