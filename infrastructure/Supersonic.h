#ifndef SSVM_INFRASTRUCTURE_SUPERSONIC_H
#define SSVM_INFRASTRUCTURE_SUPERSONIC_H

#define VM_FULL_NAME        "Supersonic Virtual Machine"
#define VM_ABBRE_NAME       "SSVM"

#include <cstdint>

#include "RBTree.hpp"
#include "Stack.hpp"

namespace ssvm{
    using u1 = std::uint_fast8_t;           //unsigned 1 byte
    using u2 = std::uint_fast16_t;          //unsigned 2 bytes
    using u4 = std::uint_fast32_t;          //unsigned 4 bytes
    using machine_ptr =   void *;           //a pointer which pointed to an memory address
                                            //and the bits of the ptr depends on its machine
    template<typename _KeyType, typename _ValueType>
    using map = RBTree<_KeyType, _ValueType>;

	template <typename _ElemType>
	using stack = Stack<_ElemType>;
}
#endif //SSVM_INFRASTRUCTURE_SUPERSONIC_H
