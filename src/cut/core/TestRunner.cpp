#include <cui/mem/__ScopeExit__.h>
#include <cut/core/TestRunner.h>
#include <cut/startup/TestOptions.h>
#include <cut/core/TestResult.h>
#include <cut/ext/RepeatedTest.h>
#include <cut/auto/TestFactorySuite.h>

CUT_NS_BEGIN

inline void TestRunner::addListeners(TestResult& result) const
{
    result.add(CUI_ROLE(TestOptions).makeTextPrinter());
    result.add(CUI_ROLE(TestOptions).makeXmlPrinter());
}

inline bool TestRunner::run(Test* test)
{
    CUI_SCOPE_EXIT([=]{ delete test; });
                        
    TestResult result;
    addListeners(result);

    RepeatedTest repeated(*test, CUI_ROLE(TestOptions).repeat());
    result.run(repeated);

    return result.isSucc();
}

bool TestRunner::run()
{
    TestFactory& factory = CUI_ROLE(TestFactorySuite);
    return run(factory.make());
}

CUT_NS_END
