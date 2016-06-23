#ifndef HCAB75B4B_8F10_461E_9087_04A4AC719FAF
#define HCAB75B4B_8F10_461E_9087_04A4AC719FAF

#include <cum/internal/BaseMatcher.h>

CUM_NS_BEGIN

struct IsNil : BaseMatcher<const void*>
{
    CUI_OVERRIDE(bool matches(const void* const& actual) const);
    CUI_OVERRIDE(void describeTo(Description& desc) const);
};

CUM_MATCHER_TAG(IsNil, const void*);

CUM_NS_END

#endif
