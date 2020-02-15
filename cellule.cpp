#include "cellule.hpp"
#include <iostream>

Cellule::Cellule() {
	tab.push_back(nullptr);
 	val = 0;
}

Cellule::Cellule(int size, int valeur) {
	tab.resize(size);
 	val = valeur;
}

void Cellule::afficher() {
	std::cout << "val = " << val << " tab.size() = " << tab.size() << std::endl;
}

