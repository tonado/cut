#ifndef HF8E7C28D_81E3_45AC_BF63_B1AFDB2E3FC3
#define HF8E7C28D_81E3_45AC_BF63_B1AFDB2E3FC3

#include <cui/base/__Keywords__.h>

#define CUI_ROLE(role) get##role()
#define CUI_ROLE_PROTO_TYPE(role) role& CUI_ROLE(role) const
#define CUI_USE_ROLE(role) virtual CUI_ROLE_PROTO_TYPE(role) = 0
#define CUI_HAS_ROLE(role) CUI_USE_ROLE(role)

//////////////////////////////////////////////////////////////////
#define CUI_IMPL_ROLE(role)                                       \
CUI_ROLE_PROTO_TYPE(role)                                         \
{                                                             \
   return const_cast<role&>(static_cast<const role&>(*this)); \
}

//////////////////////////////////////////////////////////////////////////
#define CUI_DECL_ROLE(role) CUI_ROLE_PROTO_TYPE(role)

//////////////////////////////////////////////////////////////////////////
#define __CUI_ROLE_CAST_TO(role, obj)       \
    return const_cast<role&>(static_cast<const role&>(obj))

//////////////////////////////////////////////////////////////////////////
#define CUI_IMPL_ROLE_WITH_OBJ(role, obj)   \
    CUI_DECL_ROLE(role)  { __CUI_ROLE_CAST_TO(role, obj); }

/////////////////////////////////////////////////////////////////////////////
namespace details
{
   template<typename T>
   struct __ROLE__
   {
      virtual ~__ROLE__() {}
   };
}

#define CUI_DEF_ROLE(role)  struct role : ::details::__ROLE__<role>

#define CUI_SELF(self, role) static_cast<role&>(self)

#endif

