#include <cut/hook/runtime/Runtime.h>
#include <cut/auto/TestFactorySuite.h>
#include <cut/hook/registry/HookRegistries.h>
#include <cut/startup/TestOptions.h>
#include <cut/core/TestRunner.h>

CUT_NS_BEGIN

namespace
{
    struct RuntimeImpl
        : private BeforeAllHookRegistry
        , private AfterAllHookRegistry
        , private TestFactorySuite
        , private TestOptions
        , private TestRunner
        , Runtime
    {
    private:
        CUI_IMPL_ROLE(BeforeAllHookRegistry);
        CUI_IMPL_ROLE(AfterAllHookRegistry);
        CUI_IMPL_ROLE(TestFactorySuite);
        CUI_IMPL_ROLE(TestOptions);
        CUI_IMPL_ROLE(TestRunner);
    };
}

Runtime& Runtime::getIntance()
{
    static RuntimeImpl runtime;
    return runtime;
}

CUT_NS_END
