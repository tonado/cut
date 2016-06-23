#ifndef H4F7A9E79_EF75_4EEE_BA1E_F5C16CF3DD3D
#define H4F7A9E79_EF75_4EEE_BA1E_F5C16CF3DD3D

#include <cum/internal/BaseMatcher.h>

CUM_NS_BEGIN

struct StringMatcher : BaseMatcher<std::string>
{
protected:
    StringMatcher
        ( bool ignoringCase
        , const std::string& relationship
        , const std::string& substring);

private:
    CUI_OVERRIDE(bool matches(const std::string& actual) const);
    CUI_OVERRIDE(void describeTo(Description& desc) const);
    CUI_OVERRIDE(void describeMismatch(const std::string&, Description&) const);

private:
    std::string converted(const std::string& string) const;

private:
    CUI_ABSTRACT(bool evalOf(const std::string&) const);

protected:
    const bool ignoringCase;
    const std::string relationship;
    const std::string expected;
};

CUM_NS_END

#endif
