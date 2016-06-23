#ifndef HC3CC1158_A7D9_4CDF_86FA_347EE268638E
#define HC3CC1158_A7D9_4CDF_86FA_347EE268638E

#include <cut/core/TestListener.h>
#include <cut/listener/util/Timer.h>
#include <cut/listener/util/XmlNode.h>
#include <stack>

CUT_NS_BEGIN

struct TestInfo;
struct XmlBuilder;

struct XmlResultPrinter : TestListener
{
    XmlResultPrinter();
    ~XmlResultPrinter();

private:
    CUI_OVERRIDE(void startTestRun(const Test&, TestResult&));
    CUI_OVERRIDE(void endTestRun(const Test&, TestResult&));

    CUI_OVERRIDE(void startSuite(const Test&));
    CUI_OVERRIDE(void endSuite(const Test&));

    CUI_OVERRIDE(void startTest(const Test&));
    CUI_OVERRIDE(void endTest(const Test&));

    CUI_OVERRIDE(void addFailure(const TestFailure&));

private:
    struct Statistics;

private:
    void toXml() const;

    void collectTime(const timeval& elapsed);
    const char* handlerTestResult(const TestInfo& info);
    void addStatusAndTimeAttribute(const std::string& node, const Statistics& stats);
    void recordStartTime();
    void clearStatsBy(Statistics& name);

    bool isAllTestSuiteBy(const std::string& name) const;
private:
    std::stack<TestInfo*> tests;
    XmlNode node;
    XmlBuilder* builder;
    Statistics* testStat;
    Statistics* suiteStat;
};

CUT_NS_END

#endif
