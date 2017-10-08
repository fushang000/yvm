#ifndef SSVM_TEST_TESTER_H

#include <ctime>
#include <functional>
#include <iostream>
#include <map>
#include <cstring>

#define NP_SSVM_TEST_START namespace ssvm{ namespace test{
#define NP_SSVM_TEST_END }}

NP_SSVM_TEST_START

struct TimeTester {
	TimeTester &  setHeader(const char * str) {
		header = str;
		return *this;
	}

	TimeTester &  setTask(const char * prefix,std::function<void(void)> task) {
		clock_t startTime, endTime;
		startTime = clock();
		task();
		endTime = clock();
		double taskTime = static_cast<double>(endTime - startTime) / CLOCKS_PER_SEC * 1000;
		taskPair.insert(std::make_pair(prefix,taskTime));

		return *this;
	}

	void operator()() {
		std::cout << "######" << header << "#####" << std::endl;

		for (auto start = taskPair.cbegin(); start != taskPair.cend(); start++){
			std::cout << start->first << ":" << start->second << std::endl;
		}
				
		std::cout << "######";
		for (size_t i = 0; i < strlen(header); i++){
			std::cout << "#";
		}
		std::cout << "######" << std::endl;
		clearInnerState();
	}

private:
	inline void clearInnerState() {
		taskPair.clear();
		header = nullptr;
	}

private:
	std::map<const char *, double> taskPair;
	const char *  header;
};

NP_SSVM_TEST_END

#endif // !SSVM_TEST_TESTER_H
