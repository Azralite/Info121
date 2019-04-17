#include <iostream>
#include <cstdlib>

enum espece { vide; lapin; renard; };

struct coord{
  int x;
  int y;
};

struct animal {coord c; espece b; int nour};

//Variable global pour les renards
int FoodInit = 5;
int FoodLapin = 5;
int FoodReprod = 8;
int MaxFood = 10;
float ProbBirthRenard = 0.05;
//Variable global pour les lapins
float ProbBirthLapin = 0.3;
int MinFreeBirthLapin = 4;


animal creerAnimal(espece e, coord c){
  animal res;
  res.c = creerCoord(getX(c),getY(c));
  res.b = e;
  if(e == renard){
    res.nour = FoodInit;
  }
  else{
    res.nour = -1;
  }
  return res;
}

coord coordAnimal(animal a){
  return creerCoord(getX(a.c),getY(a.c));
}

espece especeAnimal(animal a){
  return a.b;
}

int nourritureRenard(animal a){
    if(a.b == renard){
      return a.nour;
    }
    else{
      return 0; // Faut voir si on return O ou autre chose;
      //On peut aussi fait un exit() mais je sais pas bien comment ca marche
    }
}

bool estVide(animal a){
  if (a.b == vide){
    return true;
  }
  else{
    return false;
  }
}

void changeCoordAnimal(cood c, animal &a){
  a.c = c;
}

void mangeAnimal(animal &a){
  if(a.b == renard){
    a.nour = a.nour + FoodLapin;
    if(a.nour > MaxFood){
      a.nour = MaxFood;
    }
  }
}

void faimRenard(animal &a){
  if(a.b == renard){
    a.nour --;
    /*
    *if(a.nour < 0){
        a.b = vide;
        Je sais pas si on "tue" l'animal à ce moment
    }
    */
  }
}

bool mortRenard(animal a){
  if( a.b == renard){
    if(a.nour <=0){
      return true;
    }
  }
  return false;
}
