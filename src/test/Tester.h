#ifndef SSVM_TEST_TESTER_H
#define SSVM_TEST_TESTER_H

#include <cstring>
#include <ctime>
#include <functional>
#include <iostream>
#include <map>


namespace ssvm {
    namespace test {
        struct TimeTester {
            TimeTester &setHeader(const char *str) {
                header = str;
                return *this;
            }

            TimeTester &addTask(const char *prefix, std::function<void(void)> task) {
                clock_t startTime, endTime;
                startTime = clock();
                task();
                endTime = clock();
                double taskTime = static_cast<double>(endTime - startTime) / CLOCKS_PER_SEC * 1000;
                taskPair.insert(std::make_pair(prefix, taskTime));

                return *this;
            }

            void operator()() {
                std::cout << "######" << header << "#####" << std::endl;

                for (auto start = taskPair.cbegin(); start != taskPair.cend(); start++) {
                    std::cout << start->first << ":" << start->second << std::endl;
                }

                std::cout << "######";
                for (size_t i = 0; i < strlen(header); i++) {
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
            const char *header;
        };

        struct AssertTester {
            AssertTester &addCondition(const char *prefix, std::function<bool(void)> predicate) {
                bv.insert(std::make_pair(prefix, predicate()));
                return *this;
            }

            void operator()() {
                std::cout << "#####Assertion#####" << std::endl;
                for (auto i = bv.cbegin(); i != bv.cend(); i++) {
                    std::cout << i->first << " == " << i->second << std::endl;
                }
                std::cout << "###################" << std::endl;
                clearInnerState();
            }

        private:
            inline void clearInnerState() {
                bv.clear();
            }

        private:
            std::map<const char *, bool> bv;
        };
    }
}

#endif // !SSVM_TEST_TESTER_H
