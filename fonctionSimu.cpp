#include "fonctionSimu.hpp"

//Variable global pour les renards

int FoodReprod = 8;
float ProbBirthRenard = 0.05;
//Variable global pour les lapins
float ProbBirthLapin = 0.3;
int MinFreeBirthLapin = 4;

int hasard(int val){
		return rand()%val+1;
}

/**utiliser type abstrait**/
bool seReproduitAnimal(animal a, EnsCoord c){
  float ran = hasard(99)/100.;
	int taille = tailleEC(c);
	espece esp = especeAnimal(a);
	int nourriture = nourritureRenard(a);
  if (esp == lapin && taille >= MinFreeBirthLapin){ //On doit faire un .val avec le EC pour connaitre le nb de cases au tour vide
    if(ran > ProbBirthLapin){
      return false;
    }
    else{
      return true;
    }
  }
  else if(esp == renard && nourriture >= FoodReprod){
    if(ran > ProbBirthRenard){
      return false;
    }
    else{
      return true;
    }
  }
  return false;
}

bool seReproduitAnimalSexe(animal a, EnsCoord c, grille g){
	if (especeAnimal(a) == renard) {
		int nourriture = nourritureRenard(a);
		if(nourriture >= FoodReprod){
			for (int i = 0; i < tailleEC(c); i++) {
				int x = getX(coordEC(c,i));
				int y = getY(coordEC(c,i));
				animal test = getAnimal(g,creerCoord(x,y));
				if (especeAnimal(test) == especeAnimal(a)) {
					if(sexeAnimal(test) != sexeAnimal(a)){
						return (hasard(99)/100. <= ProbBirthRenard);
					}
				}
			}
		}
		return false;
	}
	if (especeAnimal(a) == lapin) {
		for (int i = 0; i < tailleEC(c); i++) {
			int x = getX(coordEC(c,i));
			int y = getY(coordEC(c,i));
			animal test = getAnimal(g,creerCoord(x,y));
			if (especeAnimal(test) == especeAnimal(a)) {
				if(sexeAnimal(test) != sexeAnimal(a)){
					return true;
				}
			}
		}
		return false;
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

/**revoir usage type abstrait EnsCoord**/
EnsCoord voisinsEspece(const grille g, coord c, espece e){
	EnsCoord EC = trouverVoisin(c);
	EnsCoord Res;
	Res = creeEC();
	for(int i = 0; i < tailleEC(EC); i++){
		int x = getX(coordEC(EC,i));
		int y = getY(coordEC(EC,i));
		if(especeAnimal(g[x][y]) == e)
			ajouteEC(Res,coordAnimal(g[x][y]));
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


void deplaceTousLapins(grille g1, grille newG){
	EnsCoord coordLapin = toutEspece(g1, lapin);
	int sauv = tailleEC(coordLapin);
	for(int i = 0; i < sauv; i++){
		coord c = randomEC(coordLapin);
		supprimeCoord(coordLapin, c);
		EnsCoord caseVide = voisinsEspece(g1, c, vide);
		animal a = getAnimal(g1,c);
		//updateAgeAnimal(a);
		if(tailleEC(caseVide) != 0 && !mortLapin(a)){
			coord newCoord = randomEC(caseVide);
			if(seReproduitAnimal(a, caseVide)){
				animal newLapin = creerAnimal(especeAnimal(a), coordAnimal(a));
				setAnimal(newG, newLapin);
			}
			changeCoordAnimal(newCoord, a);
			setAnimal(newG, a);
		}
		else if(!mortLapin(a)){
			setAnimal(newG,a);
		}
	}
}


bool attaqueRenard(grille g, animal &r){
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

/*bool attaqueRenard(grille g, animal &r){
	EnsCoord a = voisinsEspece(g, coordAnimal(r), lapin);
	if(tailleEC(a) != 0){
		mangeAnimal(r);
		changeCoordAnimal(randomEC(a), r);
		return true;
	}

	return false;
}*/

void deplaceTousRenards(grille g1, grille g2){
	EnsCoord coordRenard = toutEspece(g1, renard);
	int sauv = tailleEC(coordRenard);
	for(int i = 0; i < sauv; i++){
		coord c = randomEC(coordRenard);
		supprimeCoord(coordRenard, c);
		animal r = getAnimal(g1, c);
		//updateAgeAnimal(r);
		faimRenard(r);
		EnsCoord caseVide = voisinsEspece(g2, c, vide);

		if((!mortRenard(r)) && attaqueRenard(g2, r)){
			setAnimal(g2, r);
			if(seReproduitAnimal(r, caseVide)){
				animal oldR = getAnimal(g1, c);
				faimRenard(oldR);
				animal newRenard = creerAnimal(especeAnimal(oldR), coordAnimal(oldR));
				setAnimal(g2, newRenard);
			}
		}else if(!mortRenard(r)){
			if(seReproduitAnimal(r, caseVide)){
				animal newRenard = creerAnimal(especeAnimal(r), coordAnimal(r));
				setAnimal(g2, newRenard);
			}
			if(tailleEC(caseVide) != 0)
				changeCoordAnimal(randomEC(caseVide), r);
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
  std::cout << "Le nombre de Lapin: " << l << "(" << float(l)*100/(gridSize*gridSize) << "%)"<< '\n';
  std::cout << "Le nombre de Renard: " << r << "(" << float(r)*100/(gridSize*gridSize) << "%)" <<'\n';

  for(int i = 0; i < gridSize; i ++){
    for (int j = 0; j < gridSize; j++){
      if(especeAnimal(getAnimal(g, creerCoord(i,j))) == lapin){
        std::cout << "L" << " ";
      }
      if(especeAnimal(getAnimal(g, creerCoord(i,j))) == renard){
        std::cout << "R" << " ";
      }
      if(especeAnimal(getAnimal(g, creerCoord(i,j))) == vide){
        std::cout << "  ";
      }

    }
    std::cout  << '\n';
  }
	std::cout  << '\n';
	std::cout  << '\n';
	std::cout  << '\n';
}
