#include <iostream>
#include <cstdlib>
#include "grille.hpp"

const int gridSize = 20

void initialiseGrille(const grille &g){
	for(int i = 0; i < gridSize; i++){
		for(int n = 0; n < gridSize; n++){
			h = hasard();
			if(h < probRenard)
				g[i][n] = creerAnimal(renard, creerCoord(i,n));
			else if (h < probRenard + probLapin)
				g[i][n] = creerAnimal(lapin, creerCoord(i,n));
			else
				g[i][n] = creerAnimal(vide, creerCoord(i,n));
		}
	}
}

void verifieGrille(const grille &g){
	for(int i = 0; i < gridSize; i++)
		for(int n = 0; n < gridSize; n++){
			if( not egalCoord( coordAnimal(g[i][n]), creerCoord(i,n) ) ){
				cout << "Erreur dans la grille à la position " << i << ":" << n << endl;
				exit(1);
			}
}

EnsCoord voisinsVides(const coord &c, const grille &g){
	EnsCoord EC = trouverVoisins(c);
	EnsCoord Res;
	creeEC(Res);
	for(int i = 0; i < EC.taille; i++)
		if(estVide(g[i][n]))
			ajouteEC(Res, coordAnimal(g[i][n]));
	return Res;
}
