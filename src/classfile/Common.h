#ifndef SSVM_COMMON_H
#define SSVM_COMMON_H

#include "../infrastructure/Supersonic.h"

#define JAVA_9_MAJOR                            53
#define JAVA_8_MAJOR                            52
#define JAVA_7_MAJOR                            51
#define JAVA_6_MAJOR                            50

#define JAVA_CLASS_FILE_MAGIC_NUMBER            0XCAFEBABE

#define SUPERSONIC_MAX_SUPPORTED_VERSION        JAVA_9_MAJOR
#define SUPERSONIC_MIN_SUPPORTED_VERSION        JAVA_6_MAJOR

enum class ConstantTag {
    CONSTANT_Class =7,
    CONSTANT_Fieldref =9,
    CONSTANT_Methodref =10,
    CONSTANT_InterfaceMethodref =11,
    CONSTANT_String =8,
    CONSTANT_Integer =3,
    CONSTANT_Float= 4,
    CONSTANT_Long= 5,
    CONSTANT_Double =6,
    CONSTANT_NameAndType =12,
    CONSTANT_Utf8 =1,
    CONSTANT_MethodHandle =15,
    CONSTANT_MethodType =16,
    CONSTANT_InvokeDynamic =18
};
#endif //SSVM_CLASSFILE_COMMON_H
