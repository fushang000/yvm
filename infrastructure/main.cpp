#include <iostream>
#include "RBTree.hpp"

int main(int argc, char *args[]){
    RBTree<unsigned int, unsigned int> tree;
    for (size_t i = 0; i < 5000000; i++){
        tree.put(i, i);
        tree.remove(i);
    }
    return 0;
}