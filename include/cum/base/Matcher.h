#ifndef H20D1811C_DB7E_4401_803C_98BA018ECCCB
#define H20D1811C_DB7E_4401_803C_98BA018ECCCB

#include <cum/base/SelfDescribing.h>
#include <cum/base/MatcherTraits.h>
#include <functional>

CUM_NS_BEGIN

struct Description;

template <typename T>
struct Matcher : SelfDescribing
{
    using argument_type = T;

    CUI_ABSTRACT(bool matches(const T& actual) const);
    CUI_ABSTRACT(void describeMismatch(const T& actual, Description& mismatch) const);
};

CUM_NS_END

#endif
