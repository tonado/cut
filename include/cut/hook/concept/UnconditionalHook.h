#ifndef H9ABDDEDF_C97D_4D65_80C2_33DE40D6F46A
#define H9ABDDEDF_C97D_4D65_80C2_33DE40D6F46A

#include <cui/dci/__Role__.h>
#include <cut/cut.h>

CUT_NS_BEGIN

CUI_DEF_ROLE(UnconditionalHook)
{
    CUI_ABSTRACT(void invoke());
};

CUT_NS_END

#endif
