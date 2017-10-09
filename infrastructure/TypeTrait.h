#ifndef SSVM_TYPETRAIT_H
#define SSVM_TYPETRAIT_H

namespace ssvm {
	namespace typetrait {
		template<typename _Type>
		struct addConst {
			typedef const _Type type;
		};

		template<typename _Type>
		struct addLRef {
			typedef _Type & type;
		};

		template <bool _Cond, typename _Result_Type_A, typename _Result_Type_B>
		struct selector {
		};
		template <typename _Result_Type_A, typename _Result_Type_B>
		struct selector<true, _Result_Type_A, _Result_Type_B> {
			typedef _Result_Type_A type;
		};
		template <typename _Result_Type_A, typename _Result_Type_B>
		struct selector<false, _Result_Type_A, _Result_Type_B> {
			typedef _Result_Type_B type;
		};
	}
}

#endif //SSVM_TYPETRAIT_H
