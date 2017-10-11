#ifndef SSVM_CONSTANTSTRUCTURES_H
#define SSVM_CONSTANTSTRUCTURES_H

#include "Common.h"

using ssvm::u1;
using ssvm::u2;
using ssvm::u4;
using ssvm::machine_ptr;

struct ConstantBase {
    u2 index;
    u2 tag;
};

struct ConstantClass : public ConstantBase{
    machine_ptr nameIndex;
};

struct ConstantFieldRef :public ConstantBase{
    machine_ptr classIndex;
    machine_ptr nameIndex;
    machine_ptr descriptorIndex;
};

struct ConstantMethodRef :public ConstantBase{
    machine_ptr classIndex;
    machine_ptr nameIndex;
    machine_ptr descriptorIndex;
};

struct ConstantInterfaceMethodRef :public ConstantBase{
    machine_ptr classIndex;
    machine_ptr nameIndex;
    machine_ptr descriptorIndex;
};

struct ConstantString : public ConstantBase{
    machine_ptr stringIndex;
};

struct ConstantInteger : public ConstantBase{
    u4 bytes;
};

struct ConstantFloat: public ConstantBase{
    u4 bytes;
};

struct ConstantNameAndType : public ConstantBase{
    machine_ptr nameIndex;
    machine_ptr descriptorIndex;
};

struct ConstantUTF8 : public ConstantBase{
    u2 length;
    u1 typeIndex[];
};

struct ConstantMethodHandle : public ConstantBase{
    u1 referenceKind;
    machine_ptr classIndex;
    machine_ptr nameIndex;
    machine_ptr descriptorIndex;
};

struct ConstantMethodType : public ConstantBase{
    machine_ptr nameIndex;
};

struct ConstantInvokeDynamic : public ConstantBase{
    u2 bootstrapMethodAttrIndex;
    machine_ptr nameIndex;
    machine_ptr descriptorIndex;
};

#endif //SSVM_CONSTANTSTRUCTURES_H
