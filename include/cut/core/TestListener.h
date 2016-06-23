#ifndef _SAOXDTVZ85W9YDU8WXPQZX5VG9GYC1PRD9KOOAOJADH827VEOLVORP2L               
#define _SAOXDTVZ85W9YDU8WXPQZX5VG9GYC1PRD9KOOAOJADH827VEOLVORP2L

#include <cui/dci/__Role__.h>
#include <cut/cut.h>

CUT_NS_BEGIN

struct Test;
struct TestResult;
struct TestFailure;

CUI_DEF_ROLE(TestListener)
{
    CUI_DEFAULT(void, startTest(const Test&));
    CUI_DEFAULT(void, endTest(const Test&));
    
    CUI_DEFAULT(void, startSuite(const Test&));
    CUI_DEFAULT(void, endSuite(const Test&));
    
    CUI_DEFAULT(void, startTestRun(const Test&, TestResult&));
    CUI_DEFAULT(void, endTestRun(const Test&, TestResult&));
    
    CUI_DEFAULT(void, addFailure(const TestFailure&));
};

CUT_NS_END

#endif

