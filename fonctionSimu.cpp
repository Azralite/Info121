#include "fonctionSimu.hpp"

// const int gridSize = 20
//Variable global pour les renards

int FoodReprod = 8;
float ProbBirthRenard = 0.05;
//Variable global pour les lapins
float ProbBirthLapin = 0.3;
int MinFreeBirthLapin = 4;

int hasard(int val){
		return rand()%val+1;
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

void initialiseGrille(grille g){
	for(int i = 0; i < gridSize; i++){
		for(int n = 0; n < gridSize; n++){
			float h = hasard(100);
			if(h < 7)
				g[i][n] = creerAnimal(renard, creerCoord(i,n));
			else if (h < 27)
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
				std::cout << "Erreur dans la grille à la position " << i << ":" << n << std::endl;
				exit(1);
			}
}



EnsCoord voisinsEspece(const grille g, coord c, espece e){
	EnsCoord EC = trouverVoisin(c);
	EnsCoord Res;
	Res = creeEC();
	for(int i = 0; i < tailleEC(EC); i++){
	int x = getX(coordEC(EC,i));
	int y = getY(coordEC(EC,i));
	if(especeAnimal(g[x][y]) == e)
		ajouteEC(Res, coordAnimal(g[x][y]));
	}
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
  a = trouverVoisin(coordAnimal(r));
  for(int i = 0; i < tailleEC(a); i++){
    if(especeAnimal(getAnimal(g, coordEC(a,i))) == lapin){
      mangeAnimal(r);
      changeCoordAnimal(coordEC(a,i), r);
      return true;
    }
  }
  return false;
}
//deplaceTousLapins et deplaceTousRenards ou alors deplaceTousEspeces doivent utiliser toutEspece

//g1 = ancienne grille et g2 = nouvelle grille
void deplaceTousLapins(grille g1, grille newG){
	EnsCoord coordLapin = toutEspece(g1, lapin);
	int sauv = tailleEC(coordLapin);
	for(int i = 0; i < sauv; i++){
		coord c = randomEC(coordLapin);
		supprimeCoord(coordLapin, c);
		EnsCoord caseVide = voisinsEspece(g1, c, vide);
		coord newCoord = randomEC(caseVide);
		animal a = getAnimal(g1,c);
		changeCoordAnimal(newCoord, a);
		setAnimal(newG, getAnimal(g1, c));
	}
}

void deplaceTousRenards(grille g1, grille g2){
	EnsCoord coordRenard = toutEspece(g1, renard);
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
				setAnimal(g2, r);
			}
	}
}
//Upadte grille doit utiliser deplaceTousLapins et deplaceTousRenards
void updateGrille(grille g1, grille g2){
  deplaceTousLapins(g1, g2);
  deplaceTousRenards(g1, g2);
}



int nbLapin(grille g){
  int res = 0;
  for(int i = 0; i < gridSize; i ++){
    for (int j =0 ; j < gridSize; j++){
      if (especeAnimal(getAnimal(g,creerCoord(i,j))) == lapin) {
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
      if (especeAnimal(getAnimal(g,creerCoord(i,j))) == renard) {
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
