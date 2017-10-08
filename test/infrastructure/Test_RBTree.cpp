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

	static const int TEST_TIMES = 50000;

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
				std::cout << "time" << i;
				tree.put(std::rand(),std::rand());
				tree.remove(std::rand());
			}
	})();
	getchar();
	return 0;
}