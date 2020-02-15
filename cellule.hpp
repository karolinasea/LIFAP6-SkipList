#ifndef CELLULE_HPP
#define CELLULE_HPP

#include <vector>
#include <iostream>

class Cellule {
public:
  int val;
  std::vector<Cellule *> tab;

  Cellule();
  Cellule(int size, int valeur);
  void afficher();
} ;

#endif

