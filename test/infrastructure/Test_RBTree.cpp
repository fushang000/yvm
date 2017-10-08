#include <iostream>
#include <map>
#include <unordered_map>
#include <set>
#include "../../infrastructure/Supersonic.h"
#include "../Tester.h"

class EmptyClass {};

int main() {
	ssvm::test::TimeTester t;

	std::map<unsigned int, unsigned int> m;
	ssvm::map<unsigned int, unsigned int> tree;
	std::unordered_map<unsigned int, unsigned int> um;
	std::set<unsigned int> st;

	static const int TEST_TIMES = 5000;

	t.setHeader("Correctness Verify")
		.setTask("ssvm::map", [&tree](void)->void {
		//the following data were retrieved from <Introduction to Algorithm Trd Edition>
		tree.add(26, 0);

		tree.add(17, 0);
		tree.add(41, 0);

		tree.add(14, 0);
		tree.add(21, 0);
		tree.add(30, 0);
		tree.add(47, 0);

		tree.add(10, 0);
		tree.add(16, 0);
		tree.add(19, 0);
		tree.add(23, 0);
		tree.add(28, 0);
		tree.add(38, 0);

		tree.add(7, 0);
		tree.add(12, 0);
		tree.add(15, 0);
		tree.add(20, 0);
		tree.add(35, 0);
		tree.add(39, 0);

		tree.add(3, 0);
		tree.del(17);
		tree.del(23);
		tree.del(19);
		tree.del(1024);
	})();

	t.setHeader("Test For inserting 5000000 elements")
		.setTask("std::map",[&m](void)->void {
			for (size_t i = 0; i < TEST_TIMES; i++) {
				m.insert(std::make_pair(i, i));
			}
		})
		.setTask("ssvm::map",[&tree](void)->void{
			for (size_t i = 0; i < TEST_TIMES; i++) {
				tree.add(i, i);
			}
		})
		.setTask("std::unordered_map", [&um](void)->void {
			for (size_t i = 0; i < TEST_TIMES; i++) {
				um.insert(std::make_pair(i, i));
			}
		})
		.setTask("std::set", [&st](void)->void {
			for (size_t i = 0; i < TEST_TIMES; i++) {
				st.insert(i);
			}
		})();


	t.setHeader("Test For deleting 5000000 elements")
		.setTask("std::map", [&m](void)->void {
			for (size_t i = 0; i < TEST_TIMES; i++) {
				m.erase(m.find(i));
			}
		})
		.setTask("std::unordered_map", [&um](void)->void {
			for (size_t i = 0; i < TEST_TIMES; i++) {
				um.erase(um.find(i));
			}
		})
		.setTask("ssvm::map", [&tree](void)->void {
			for (size_t i = 0; i < TEST_TIMES; i++) {
				tree.del(i);
			}
		})
		.setTask("std::set", [&st](void)->void {
			for (size_t i = 0; i < TEST_TIMES; i++) {
				st.erase(st.find(i));
			}
		})();


	t.setHeader("Test For random inserting and deleting")
		.setTask("ssvm::map", [&tree](void)->void {
			for (size_t i = 0; i < TEST_TIMES; i++) {
				int x, y, z;
				x = std::rand();
				y = std::rand();
				z = std::rand();
				tree.add(x,y);
				tree.del(z);
			}
		})();

	tree.clear();
	m.clear();
	um.clear();
	st.clear();

	if (tree.empty()) {
		std::cout << "Empty." << std::endl;
	}
	tree.add(1, 1024);
	tree.add(2, 1024);
	tree.add(3, 1024);

	if (tree.exist(6)) {
		tree.del(6);
		std::cout << "Delete:6" << std::endl;
	}
	else if (tree.exist(7)) {
		std::cout << "Find:7" << std::endl;
	}
	else if (tree.exist(3)) {
		std::cout << "Find:3" << std::endl;
	}

	ssvm::map<int, EmptyClass> classMap;
	EmptyClass ec;
	classMap.add(1,ec);

	return 0;
}