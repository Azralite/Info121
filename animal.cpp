#include "animal.hpp"

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

void changeCoordAnimal(coord c, animal &a){
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
  }
  else
    exit(0);
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
