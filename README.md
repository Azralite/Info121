# Info121

**Bug réglé:**

* Erreur de segmentation dût à randomEC qui renvoyait un chiffre entre -1 et sizeGrid-1
* l'affichage du même tableau à chaque boucle dû à une simple inversion entre les 2 grilles passé en paramètres à copieGrille
* Les animaux ne se déplaçaient que en haut et vers la gauche dût à la fonction trouverVoisin
* Réglage du problème de reproduction dût à un oublie d'utilisation de la fonction Reproduction dans les fonctions deplaçant les animaux + remplacement de rand() par hasard() dans la fonction seReproduitAnimal car rand ne renvoyait pas des valeurs correct.

**Bug toujours present:**

* RAS à ce jour
