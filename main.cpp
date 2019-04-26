#include "fonctionSimu.hpp"


void afficheCoord(coord a){
  int x = getX(a);
  int y = getY(a);
  std::cout << x << " " << y << '\n';
}
/*
declarer 2 lignes
utiliser grille vide ou initialise grille (1)
boucle while
  afficher grille
  deplacer tous lapins de l'ancienne grille a la nouvelle
idem renards
ancienne <- nouvelle
nouvelle <- vide
*/
int main(){
  srand (time(NULL));
  grille g, sauv;
  initialiseGrille(g);
  //while(nbLapin(g) > 0 && nbRenard(g) > 0){
    grilleVide(sauv);
    updateGrille(g, sauv);
    afficheGrille(sauv,0,0);
    copieGrille(g, sauv);
    afficheGrille(g,nbLapin(g),nbRenard(g));
//  }
  grille test;
  initialiseGrille(test);
  afficheGrille(test,1000,1000);
  EnsCoord a = creeEC();
  a = toutEspece(test, lapin);
  int lon = tailleEC(a);
  std::cout << lon << '\n';
  coord b;
  for(int i = 0; i < lon; i++){
    b = coordEC(a,i);

  }
}
