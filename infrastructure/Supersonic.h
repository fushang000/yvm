#ifndef SSVM_INFRASTRUCTURE_SUPERSONIC_H
#define SSVM_INFRASTRUCTURE_SUPERSONIC_H

#define VM_FULL_NAME        "Supersonic Virtual Machine"
#define VM_ABBRE_NAME       "SSVM"

#define SSVM_DEBUG

#ifdef SSVM_DEBUG
#include <iostream>
#include <climits>
#endif

#include <cstdint>
#include "RBTree.hpp"

namespace ssvm{
    using u1 = std::uint_fast8_t;           //unsigned 1 byte
    using u2 = std::uint_fast16_t;          //unsigned 2 bytes
    using u4 = std::uint_fast32_t;          //unsigned 4 bytes
    using machine_ptr =   void *;           //a pointer which pointed to an memory address
                                            //and  the bits of the ptr depends on its machine
    template<typename _KeyType, typename _ValueType>
    using map = RBTree<_KeyType, _ValueType>;
}
#endif //SSVM_INFRASTRUCTURE_SUPERSONIC_H
