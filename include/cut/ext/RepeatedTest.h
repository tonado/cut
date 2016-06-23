#ifndef HBB45B5B7_7E6D_4259_88E1_37CEC4BD7E7A
#define HBB45B5B7_7E6D_4259_88E1_37CEC4BD7E7A

#include <cut/ext/TestDecorator.h>

CUT_NS_BEGIN

struct RepeatedTest : TestDecorator
{
    RepeatedTest(Test& test, int times);

private:
    CUI_OVERRIDE(void run(TestResult&));
    CUI_OVERRIDE(int countTestCases() const);
    CUI_OVERRIDE(int countChildTests() const);

private:
    int times;
};

CUT_NS_END

#endif
