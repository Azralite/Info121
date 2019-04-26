#include "coord.hpp"

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


void ajouteEC(EnsCoord &a, coord c){
  a.tab[a.taille] = c;
  a.taille ++;
}

coord randomEC(EnsCoord c){
  int ran;
  if(tailleEC(c) != 0){
    ran = rand()%c.taille - 1;
    return c.tab[ran];
  }
  std::cerr << "ERREUR DE TAILLE" << '\n';
  return c.tab[0];
}

int tailleEC(EnsCoord a){
  return a.taille;
}

coord coordEC(EnsCoord e, int a){
    return e.tab[a];
}
void supprimeCoord(EnsCoord &ec, coord c){
  int x = getX(c);
  int y = getY(c);
  int sauv = ec.taille;
  for(int i = 0; i < sauv; i++)
    if(getX(ec.tab[i]) == x && getY(ec.tab[i]) == y){
      ec.tab[i] = ec.tab[ec.taille-1];
      ec.taille--;
    }
}

EnsCoord trouverVoisin(coord c){
  int xmin, xmax, ymin, ymax;
  EnsCoord e;
  e = creeEC();
  xmin = max(getX(c)-1,0);
  xmax = min(getX(c)+1,TAILLE-1);
  ymin = max(getY(c)-1,0);
  ymax = min(getY(c)+1,TAILLE-1);
  for (int i = xmin; i < xmax; i++) {
    for (int j = ymin; j < ymax; j++) {
      if(i!=getX(c) || j!=getY(c)){
        ajouteEC(e,creerCoord(i,j));
      }
    }
  }
  return e;
}
