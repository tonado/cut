#ifndef HA3666DFB_6D18_4E3F_99B9_DDDF3DDC46EB
#define HA3666DFB_6D18_4E3F_99B9_DDDF3DDC46EB

#include <cut/cut.h>
#include <string>
#include <typeinfo>

CUT_NS_BEGIN

///////////////////////////////////////////////////////////////
std::string getDemangledName(const std::type_info& typeInfo);

///////////////////////////////////////////////////////////////
template<typename T>
struct TypeName
{
    static std::string value()
    {
        return getDemangledName(typeid(T));
    }
};

///////////////////////////////////////////////////////////////
template<>
struct TypeName<std::string>
{
    static std::string value() { return "std::string"; }
};

///////////////////////////////////////////////////////////////
template<>
struct TypeName<std::nullptr_t>
{
    static std::string value() { return "std::nullptr_t"; }
};

CUT_NS_END

#endif
