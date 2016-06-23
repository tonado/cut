#ifndef H8830446F_F68B_4ECB_945B_1474064EB768
#define H8830446F_F68B_4ECB_945B_1474064EB768

#include <cut/core/TestCase.h>

CUT_NS_BEGIN

template <typename Fixture>
struct TestCaller : TestCase
{
    using Method = void(Fixture::*)();

    TestCaller(const std::string& name, Method method)
        : TestCase(name), fixture(0), method(method)
    {}

private:
    CUI_OVERRIDE(void setUp())
    {
        fixture = new Fixture;
        fixture->setUp();
    }

    CUI_OVERRIDE(void tearDown())
    {
        fixture->tearDown();
        delete fixture;
        fixture = 0;
    }

    CUI_OVERRIDE(void runTest())
    {
        (fixture->*method)();
    }

private:
    Fixture* fixture;
    Method method;
};

CUT_NS_END

#endif
