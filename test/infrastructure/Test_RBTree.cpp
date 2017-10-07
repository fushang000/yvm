#include <iostream>
#include <ctime>
#include <map>
#include <unordered_map>
#include <set>
#include "../../infrastructure/Supersonic.h"


int main() {
	clock_t startTime, endTime;


	std::cout << "#######################Insert 50000000#######################" << std::endl;
	startTime = clock();
	std::map<unsigned int, unsigned int> m;
	for (size_t i = 0; i < 5000000; i++) {
		m.insert(std::make_pair(i, i));
	}
	endTime = clock();
	std::cout << "std::map:" << static_cast<double>(endTime - startTime) / CLOCKS_PER_SEC * 1000 << "ms" << std::endl;

	startTime = clock();
	ssvm::map<unsigned int, unsigned int> tree;
	for (size_t i = 0; i < 5000000; i++) {
		tree.put(i, i);
	}
	endTime = clock();
	std::cout << "ssvm::RBTree:" << static_cast<double>(endTime - startTime) / CLOCKS_PER_SEC * 1000 << "ms" << std::endl;

	startTime = clock();
	std::unordered_map<unsigned int, unsigned int> um;
	for (size_t i = 0; i < 5000000; i++) {
		um.insert(std::make_pair(i, i));
	}
	endTime = clock();
	std::cout << "std::unordered_map:" << static_cast<double>(endTime - startTime) / CLOCKS_PER_SEC * 1000 << "ms" << std::endl;

	startTime = clock();
	std::set<unsigned int> st;
	for (size_t i = 0; i < 5000000; i++) {
		st.insert(i);
	}
	endTime = clock();
	std::cout << "std::set:" << static_cast<double>(endTime - startTime) / CLOCKS_PER_SEC * 1000 << "ms" << std::endl;

	std::cout << "############################################################" << std::endl;


	std::cout << "#######################Delete 50000000#######################" << std::endl;
	startTime = clock();
	for (size_t i = 0; i < 5000000; i++) {
		st.erase(st.find(i));
	}
	endTime = clock();
	std::cout << "std::set:" << static_cast<double>(endTime - startTime) / CLOCKS_PER_SEC * 1000 << "ms" << std::endl;

	startTime = clock();
	for (size_t i = 0; i < 5000000; i++) {
		tree.remove(i);
	}
	endTime = clock();
	std::cout << "ssvm::RBTree:" << static_cast<double>(endTime - startTime) / CLOCKS_PER_SEC * 1000 << "ms" << std::endl;

	startTime = clock();
	for (size_t i = 0; i < 5000000; i++) {
		m.erase(m.find(i));
	}
	endTime = clock();
	std::cout << "std::map:" << static_cast<double>(endTime - startTime) / CLOCKS_PER_SEC * 1000 << "ms" << std::endl;

	startTime = clock();
	for (size_t i = 0; i < 5000000; i++) {
		um.erase(um.find(i));
	}
	endTime = clock();
	std::cout << "std::unordered_map:" << static_cast<double>(endTime - startTime) / CLOCKS_PER_SEC * 1000 <<"ms"<< std::endl;
	std::cout << "############################################################" << std::endl;
	return 0;
}