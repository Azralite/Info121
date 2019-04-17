#include <iostream>
#include <cstdlib>

const TAILLE = 20;

struct coord{
  int x;
  int y;
};

struct EnsCoord {
   coord tab[TAILLE*TAILLE];
   int taille;
};

// On recopie les fonctions du td
coord creerCoord(int x, int y){
  coord res;
  res.x = x;
  res.y = y;
  return res;
}

int getX(coord a){
  return a.x;
}


int getY(coord a){
  return a.y;
}

bool egalCoord(coord a, coord b){
  if(a.x != b.x)
    return false;
  if(a.y != b.y)
    return false;
  else
    return true;
}

int max (int a, int b){
  if (a>b){
    return a;
  }
  else{
     return b;
   }
}

int min(int a, int b){
  if (a>b){
    return b;
  }
  else{
     return a;
   }
}

EnsCoord creeEC(){
  EnsCoord res;
  res.taille = 0;
  return res;
}


coord randomEC(EnsCoord c){
  int ran = rand()%c.taille - 1;
  return c.tab[ran];
}



EnsCoord trouverVoisin(coord c){
  int xmin, xmax, ymin, ymax;
  EnsCoord e;
  creeEC(e);
  xmin = max(getX(c)-1,0);
  xmax = min(getX(c)+1,TAILLE-1);
  ymin = max(getY(c)-1,0);
  ymax = min(getY(c)+1,TAILLE-1);
  for (int i = 0; i < xmax; i++) {
    for (int i = 0; i < ymax; i++) {
      if(i!=getX(c) || j!=getY(c)){
        ajouteEC(e,creerCoord(i,j));
      }
    }
  }
}

int main() {
  srand(time(NULL));
  return 0;
}
