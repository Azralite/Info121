#include <iostream>
#include <cstdlib>

const int gridSize = 20
using grille = animal [gridSize][gridSize]

void grilleVide(grille &g){
	for(int i = 0; i < gridSize; i++)
		for(int n = 0; n < gridSize; n++)
			g[i][n] = creerAnimal(vide, {i,n});
}

void copieGrille(const grille &g1, grille &g2){
	g2 = g1; /*A mon avis cette fonction est inutile, pour le deplacement il vaudrait mieux faire
une fonction grille updateGrille(grille g) comme sa la grille g est passé par copie et on déclare une
nouvelle grille à l'intérieur de la fonction dans laqsuel on déplacera nos lapin puis nos renard sans donc
modifier g */
}

animal getAnimal(const grille &g, const coord &c){
	return g[c.x][c.y];
}

animal setAnimal(grille &g, const animal &p){
	g[p.a.x][p.a.y] = p;
}

void initialiseGrille(const grille &g){
	for(int i = 0; i < gridSize; i++)
		for(int n = 0; n < gridSize; n++)
			h = hasard();
			if(h < probRenard)
				g[i][n] = creerAnimal(renard, {i,n}); //j'aurais peut être du utiliser setAnimal mais j'en vois pas trop l'utilité ici
			else if (h < probRenard + probLapin)
				g[i][n] = creerAnimal(lapin, {i,n});

//j'ai pas mis le cas ou la case est vide puisque normal on part d'une grille vide initialisé avec grilleVide

}

void verifieGrille(const grille &g){
	for(int i = 0; i < gridSize; i++)
		for(int n = 0; n < gridSize; n++){
			if(egalCoord(g[i][n].a, {i,n}){
				cout << "Erreur dans la grille" << endl;
				exit(1);
			}
}

EnsCoord voisinsVides(const coord &c, const grille &g){
	EnsCoord EC = trouverVoisins(c);
	EnsCoord Res;
	creeEC(Res);
	for(int i = 0; i < EC.taille; i++)
		if(estVide(g[i][n]))
			ajouteEC(Res, coordAnimal(g[i][n]));
	return Res;
}
