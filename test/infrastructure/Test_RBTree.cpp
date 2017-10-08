#include <iostream>
#include <map>
#include <unordered_map>
#include <set>
#include "../../infrastructure/Supersonic.h"
#include "../Tester.h"

int main() {
	ssvm::test::TimeTester t;

	std::map<unsigned int, unsigned int> m;
	ssvm::map<unsigned int, unsigned int> tree;
	std::unordered_map<unsigned int, unsigned int> um;
	std::set<unsigned int> st;

	static const int TEST_TIMES = 5000000;

	t.setHeader("Correctness Verify")
		.setTask("ssvm::map", [&tree](void)->void {
		//the following data were retrieved from <Introduction to Algorithm Trd Edition>
		tree.put(26, 0);

		tree.put(17, 0);
		tree.put(41, 0);

		tree.put(14, 0);
		tree.put(21, 0);
		tree.put(30, 0);
		tree.put(47, 0);

		tree.put(10, 0);
		tree.put(16, 0);
		tree.put(19, 0);
		tree.put(23, 0);
		tree.put(28, 0);
		tree.put(38, 0);

		tree.put(7, 0);
		tree.put(12, 0);
		tree.put(15, 0);
		tree.put(20, 0);
		tree.put(35, 0);
		tree.put(39, 0);

		tree.put(3, 0);
		tree.remove(17);
		tree.remove(23);
		tree.remove(19);
		tree.remove(1024);
	})();

	t.setHeader("Test For inserting 5000000 elements")
		.setTask("std::map",[&m](void)->void {
			for (size_t i = 0; i < TEST_TIMES; i++) {
				m.insert(std::make_pair(i, i));
			}
		})
		.setTask("ssvm::map",[&tree](void)->void{
			for (size_t i = 0; i < TEST_TIMES; i++) {
				tree.put(i, i);
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
				tree.remove(i);
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
				tree.put(x,y);
				tree.remove(z);
			}
		})();

	getchar();
	return 0;
}