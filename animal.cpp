#include <iostream>
#include <cstdlib>

enum espece { vide; lapin; renard; };

struct animal {coord a; espece b; int nour};

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
  res.a.x = c.x;
  res.a.y = c.y;
  res.b = e;
  if(e == renard){
    res.nour = FoodInit;
  }
  else{
    res.nour = -1;
    //Faut voir a combien on met la bouffe des lapins et du vide
    //Sinon on doit se demerder pour que il n'y ait que les renards qui aient un compteur de bouffe
  }
  return res;
}

coord coordAnimal(animal a){
  coord res;
  res.x = a.a.x;
  res.y = a.a.y;
  return res;
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
  a.a.x = c.x;
  a.a.y = c.y;
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

bool seReproduitAnimal(animal a, EnsCoord c){
  float ran = rand();
  if (a.b == lapin && c.val >= MinFreeBirthLapin){ //On doit faire un .val avec le EC pour connaitre le nb de cases au tour vide
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

int main(int argc, char const *argv[]) {
  srand(time(NULL));
  return 0;
}
