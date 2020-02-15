#include "skipList.hpp"

#include <iostream>


int main() {

	SkipList s;
	s.inserer(2);
	// s.afficher();
	s.inserer(4);
	s.inserer(7);
	s.inserer(13);
	s.inserer(22);
	s.afficher();

	if(s.search(7)) {
		std::cout << "7 est dans la SkipList" << std::endl;
	} else {
		std::cout << "7 n'est pas dans la SkipList" << std::endl;
	}

	if(s.search(15)) {
		std::cout << "15 est dans la SkipList" << std::endl;
	} else {
		std::cout << "15 n'est pas dans la SkipList" << std::endl;
	}

	return 0;
}

