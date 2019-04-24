#include "fonctionSimu.hpp"

const int gridSize = 20


int hasard(int val){
		return ran = rand()%val+1;
}

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
			int h = hasard();
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



EnsCoord voisinsEspece(const grille &g, coord c, espece e){
	EnsCoord EC = trouverVoisins(c);
	EnsCoord Res;
	Res = creeEC();
	for(int i = 0; i < tailleEC(EC); i++)
		if(especeAnimal(g[i][n]) == e)
			ajouteEC(Res, coordAnimal(g[i][n]));
	return Res;
}

EnsCoord toutEspece(grille g, espece e);

bool attaqueRenard(grille g, animal r);

//deplaceTousLapins et deplaceTousRenards ou alors deplaceTousEspeces doivent utiliser toutEspece

//g1 = ancienne grille et g2 = nouvelle grille
void deplaceTousLapins(grille g1, grille newG){
	EnsCoord coordLapin = tousEspece(g1, lapin);
	int sauv = tailleEC(coordLapin);
	for(int i = 0; i < sauv; i++){
		coord c = randomEC(coordLapin);
		supprimeCoord(coordLapin, c);
		EnsCoord caseVide = voisinsEspece(g1, c, vide);
		coord newCoord = randomEC(caseVide);
		changeCoordAnimal(newCoord, getAnimal(g1, c));
		setAnimal(newG, getAnimal(g1, c));
	}
}

void deplaceTousRenards(grille g1, grille g2){
	EnsCoord coordRenard = tousEspece(g1, renard);
	int sauv = tailleEC(coordRenard);
	for(int i = 0; i < sauv; i++){
		coord c = randomEC(coordRenard);
		supprimeCoord(coordRenard, c);
		animal r = getAnimal(g1, c);
		if( not mortRenard(r) )
			if(attaqueRenard(g2, r))
				setAnimal(g2, r);
			else{
				EnsCoord caseVide = voisinsEspece(g2, c, vide);
				coord newCoord = randomEC(caseVide);
				changeCoordAnimal(newCoord, r);
				setAnimal(newG, r);
			}
	}
}
//Upadte grille doit utiliser deplaceTousLapins et deplaceTousRenards
void updateGrille(grille g1, grille g2);

void afficheGrille(grille g);
