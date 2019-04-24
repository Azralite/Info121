#include "fonctionSimu.hpp"

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
  while(nbLapin(g) > 0 && nbRenard(g) > 0){
    grilleVide(sauv);
    updateGrille(g, sauv);
    copieGrille(g, sauv);
    afficheGrille(g,nbLapin(g),nbRenard(g));
  }
}
