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

	static const int TEST_TIMES = 5000000;

	t.setHeader("Correctness Verify")
		.addTask("ssvm::map", [&tree](void)->void {
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

	t.setHeader("Time Test For inserting 5000000 elements")
		.addTask("std::map",[&m](void)->void {
			for (size_t i = 0; i < TEST_TIMES; i++) {
				m.insert(std::make_pair(i, i));
			}
		})
		.addTask("ssvm::map",[&tree](void)->void{
			for (size_t i = 0; i < TEST_TIMES; i++) {
				tree.add(i, i);
			}
		})
		.addTask("std::unordered_map", [&um](void)->void {
			for (size_t i = 0; i < TEST_TIMES; i++) {
				um.insert(std::make_pair(i, i));
			}
		})
		.addTask("std::set", [&st](void)->void {
			for (size_t i = 0; i < TEST_TIMES; i++) {
				st.insert(i);
			}
		})();


	t.setHeader("Time Test For deleting 5000000 elements")
		.addTask("std::map", [&m](void)->void {
			for (size_t i = 0; i < TEST_TIMES; i++) {
				m.erase(m.find(i));
			}
		})
		.addTask("std::unordered_map", [&um](void)->void {
			for (size_t i = 0; i < TEST_TIMES; i++) {
				um.erase(um.find(i));
			}
		})
		.addTask("ssvm::map", [&tree](void)->void {
			for (size_t i = 0; i < TEST_TIMES; i++) {
				tree.del(i);
			}
		})
		.addTask("std::set", [&st](void)->void {
			for (size_t i = 0; i < TEST_TIMES; i++) {
				st.erase(st.find(i));
			}
		})();


	t.setHeader("Time Test For random inserting and deleting")
		.addTask("ssvm::map", [&tree](void)->void {
			for (size_t i = 0; i < TEST_TIMES; i++) {
				int x, y, z;
				x = std::rand();
				y = std::rand();
				z = std::rand();
				tree.add(x,y);
				tree.del(z);
			}
		})();

	ssvm::test::AssertTester at;
	at.addCondition("clear and check empty", [&tree](void)->bool {
		tree.clear();
		return tree.empty();
	})
		.addCondition("add 1 but find 3", [&tree](void)->bool {
		tree.add(1, 1024);
		return tree.exist(3);
	})
		.addCondition("add 7 and find 7", [&tree](void)->bool {
		tree.add(7, 1024);
		return tree.exist(7);
	})
		.addCondition("del 7 and find 7", [&tree](void)->bool {
		tree.del(7);
		return tree.exist(7);
	})
		.addCondition("get key 1's value", [&tree](void)->bool {
		return tree.get(1);
	})();
	getchar();
	return 0;
}