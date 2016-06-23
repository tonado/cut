#ifndef _30KHGDCAF3MOKCBO9D1E7TLHUX8AUQ8FLRZ2MNXSJTX011I7KFOCMGJY               
#define _30KHGDCAF3MOKCBO9D1E7TLHUX8AUQ8FLRZ2MNXSJTX011I7KFOCMGJY

#include <cui/dci/__Role__.h>
#include <cut/cut.h>
#include <string>

CUT_NS_BEGIN

struct TestResult;

CUI_DEF_ROLE(Test)
{
    CUI_ABSTRACT(const std::string& getName () const);
    CUI_ABSTRACT(int countTestCases() const);
    CUI_ABSTRACT(int countChildTests() const);
    CUI_ABSTRACT(void run(TestResult&));
};

CUT_NS_END

#endif
