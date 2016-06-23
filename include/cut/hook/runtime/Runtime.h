#ifndef H4F0DAA73_78BC_4665_B214_D485ED463BB1
#define H4F0DAA73_78BC_4665_B214_D485ED463BB1

#include <cui/dci/__Role__.h>
#include <cut/cut.h>

CUT_NS_BEGIN

struct BeforeAllHookRegistry;
struct AfterAllHookRegistry;
struct TestFactorySuite;
struct TestOptions;
struct TestRunner;

CUI_DEF_ROLE(Runtime)
{
    static Runtime& getIntance();

    CUI_HAS_ROLE(BeforeAllHookRegistry);
    CUI_HAS_ROLE(AfterAllHookRegistry);
    CUI_HAS_ROLE(TestFactorySuite);
    CUI_HAS_ROLE(TestOptions);
    CUI_HAS_ROLE(TestRunner);
};

#define RUNTIME(type) Runtime::getIntance().CUI_ROLE(type)

CUT_NS_END

#endif
