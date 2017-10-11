#ifndef SSVM_STRING_H
#define SSVM_STRING_H

#include <iostream>
#include <string>


/*
1. store basic characters and utf8(like Chinese)
2. the find operation may the maximum frequency
3. should support converting from u4 array
4. comparsion operation may the maximum frequency
*/
class String {
public:
	String() {
	}

	void print();

private:
	volatile int ref;
	volatile int len;
	wchar_t * raw;
};


#endif //SSVM_STRING_H
