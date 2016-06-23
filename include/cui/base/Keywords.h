#ifndef H24444E71_BA4A_444A_8ED4_03C92F43DBF5
#define H24444E71_BA4A_444A_8ED4_03C92F43DBF5

#include <cui/base/Default.h>
#include <cui/cui.h>

CUI_NS_BEGIN

namespace details
{
   template<typename T>
   struct Interface
   {
      virtual ~Interface() {}
   };
}

#define DEF_INTERFACE(Intf)  struct Intf : ::CUB_NS::details::Interface<Intf>
#define ABSTRACT(...) virtual __VA_ARGS__ = 0
#define OVERRIDE(...) virtual __VA_ARGS__

#define EXTENDS(...) , ##__VA_ARGS__
#define IMPLEMENTS(...) EXTENDS(__VA_ARGS__)

CUI_NS_END

#endif

