#include "skipList.hpp"

#include <iostream>


int main() {

	std::srand(std::time(nullptr));
	SkipList s;
	// s.inserer(2);
	s.inserer(13);
	// s.afficher();
	s.inserer(22);
	
	// s.afficher();
	s.inserer(7);
	s.inserer(4);
	// s.afficher();
	s.inserer(88);
	// s.afficher();
	// s.inserer(5);
	// s.inserer(8);
	// s.afficher();
	// // s.inserer(11);
	// s.inserer(54);
	// // s.inserer(1);

	s.afficher();

	// if(s.search(7)) {
	// 	std::cout << "7 est dans la SkipList" << std::endl;
	// } else {
	// 	std::cout << "FALSE 1" << std::endl;
	// }

	// if(s.search(15)) {
	// 	std::cout << "FALSE 2" << std::endl;
	// } else {
	// 	std::cout << "15 n'est pas dans la SkipList" << std::endl;
	// }

	// if(s.search(88)) {
	// 	std::cout << "88 est dans la SkipList" << std::endl;
	// } else {
	// 	std::cout << "FALSE 3" << std::endl;
	// }

	// if(s.search(222)) {
	// 	std::cout << "FALSE 4" << std::endl;
	// } else {
	// 	std::cout << "222 n'est pas dans la SkipList" << std::endl;
	// }

	// if(s.search(13)) {
	// 	std::cout << "13 est dans la SkipList" << std::endl;
	// } else {
	// 	std::cout << "FALSE 5" << std::endl;
	// }

	// if(s.search(41)) {
	// 	std::cout << "FALSE 6" << std::endl;
	// } else {
	// 	std::cout << "41 n'est pas dans la SkipList" << std::endl;
	// }

	return 0;
}

