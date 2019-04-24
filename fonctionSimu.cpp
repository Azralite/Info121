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

EnsCoord toutEspece(grille g, espece e){
  EnsCoord a = creeEC();
  for(int i = 0; i < gridSize; i ++){
    for (int j= 0; j < gridSize; j++) {
      if(especeAnimal(getAnimal(g, creerCoord(i,j))) == e)
        ajouteEC(a,creerCoord(i,j));
    }
  }
  return a;
}

bool attaqueRenard(grille g, animal r){
  EnsCoord a = creeEC();
  a = trouverVoisin(g, coordAnimal(r));
  for(int i = 0; i < tailleEC(a); i++){
    if(especeAnimal(getAnimal(g, a[i])) == lapin){
      mangeAnimal(r);
      changeCoordAnimal(a[i], r);
      return true;
    }
  }
  return false;
}
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
void updateGrille(grille g1, grille g2){
  deplaceTousLapins(g1, g2);
  deplaceTousRenard(g1, g2);
}




bool attaqueRenard(grille g, animal r){
  EnsCoord a = creeEC();
  a = trouverVoisin(g, coordAnimal(r));
  for(int i = 0; i < tailleEC(a); i++){
    if(especeAnimal(getAnimal(g, a[i])) == lapin){
      mangeAnimal(r);
      changeCoordAnimal(a[i], r);
      return true;
    }
  }
  return false;
}

int nbLapin(grille g){
  int res = 0;
  for(int i = 0; i < gridSize; i ++){
    for (int j =0 ; j < gridSize; j++){
      if (especeAnimal(getAnimal(creerCoord(i,j))) == lapin) {
        res++;
      }
    }
  }
  return res;
}

int nbRenard(grille g){
  int res = 0;
  for(int i = 0; i < gridSize; i ++){
    for (int j =0 ; j < gridSize; j++){
      if (especeAnimal(getAnimal(creerCoord(i,j))) == renard) {
        res++;
      }
    }
  }
  return res;
}



void afficheGrille(grille g, int l, int r){
  std::cout << "Le nombre de Lapin: " << l << "(" << l/(gridSize*gridSize) << "%)"<< '\n';
  std::cout << "Le nombre de Renard: " << r << "(" << l/(gridSize*gridSize) << "%)" <<'\n';

  for(int i = 0; i < gridSize; i ++){
    for (int j = 0; j < gridSize; j++){
      if(especeAnimal(getAnimal(g, creerCoord(i,j))) == lapin){
        std::cout << "L";
      }
      if(especeAnimal(getAnimal(g, creerCoord(i,j))) == renard){
        std::cout << "R";
      }
      if(especeAnimal(getAnimal(g, creerCoord(i,j))) == vide){
        std::cout << " ";
      }
    }
    std::cout  << '\n';
  }
}
