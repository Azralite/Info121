#include <iostream>
#include <cstdlib>
#include "grille.hpp"

const int gridSize = 20

bool seReproduitAnimal(animal a, EnsCoord c){
  float ran = rand();
  if (a.b == lapin && c.taille >= MinFreeBirthLapin){ //On doit faire un .val avec le EC pour connaitre le nb de cases au tour vide
    if(ran > ProbBirthLapin){
      return false;
    }
    else{
      return true;
    }
  }
  else if(a.b == renard && a.nour >= FoodReprod){
    if(ran > ProbBirthRenard){
      return false;
    }
    else{
      return true;
    }
  }
  return false;
}

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
		for(int n = 0; n < gridSize; n++)
			if( not egalCoord( coordAnimal(g[i][n]), creerCoord(i,n) ) ){
				cout << "Erreur dans la grille à la position " << i << ":" << n << endl;
				exit(1);
			}
}

/*Non Fonctionnel actuellement en attente des fonctions portant sur EnsCoord*/
EnsCoord voisinsVides(const coord &c, const grille &g){
	EnsCoord EC = trouverVoisins(c);
	EnsCoord Res;
	creeEC(Res);
	for(int i = 0; i < EC.taille; i++)
		if(estVide(g[i][n]))
			ajouteEC(Res, coordAnimal(g[i][n]));
	return Res;
}

EnsCoord voisinsEspece(const grille &g, coord c, espece e){
	EnsCoord EC = trouverVoisins(c);
	EnsCoord Res;
	Res = creeEC();
	for(int i = 0; i < EC.taille; i++)
		if(g[i][n])
			ajouteEC(Res, coordAnimal(g[i][n]));
	return Res;
}
