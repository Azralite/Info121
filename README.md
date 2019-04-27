# Info121

**Bug réglé:**

* Erreur de segmentation dût à randomEC qui renvoyait un chiffre entre -1 et sizeGrid-1
* l'affichage du même tableau à chaque boucle dû à une simple inversion entre les 2 grilles passé en paramètres à copieGrille

**Bug toujours present:**

* Problème avec repro des Lapin car le nb de lapin n'augmente jamais
* Problème quand reste peu de Lapin et de Renard
    * Le renard de meurt pas
    * Le lapin même côte à côte avec le renard n'est pas mangé
      * Les déplacement se font toujours haut gauche donc quand quasi plus de lapin/renard ils sont tous tassés à gauche et ne peuvent se déplacé donc surement dût un problème avec trouverVoisin
