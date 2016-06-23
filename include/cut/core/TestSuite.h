#ifndef _XQBZGMWOMI9Q1NW1QO2NOR2WRZOSTWAMCG6MQK2TZOV2MSWVLCBZUPKZ               
#define _XQBZGMWOMI9Q1NW1QO2NOR2WRZOSTWAMCG6MQK2TZOV2MSWVLCBZUPKZ

#include <vector>
#include <cut/core/Test.h>

CUT_NS_BEGIN

struct TestSuite : Test
{
    explicit TestSuite(const std::string& name);
    ~TestSuite();

    bool hasChild() const;
    void addTest(Test*);
    void runBare(TestResult &result);

private:
    CUI_OVERRIDE(const std::string& getName() const);
    CUI_OVERRIDE(int countTestCases() const);
    CUI_OVERRIDE(int countChildTests() const);
    CUI_OVERRIDE(void run(TestResult&));

private:
    const std::string name;
    std::vector<Test*> tests;
};

CUT_NS_END

#endif

