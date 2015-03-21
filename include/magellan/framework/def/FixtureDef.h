#ifndef HBAD0E026_1661_48E7_B0EE_F3DA07EA24F9
#define HBAD0E026_1661_48E7_B0EE_F3DA07EA24F9

#include <magellan/framework/core/TestFixture.h>
#include <magellan/framework/core/AutoTestSuite.h>
#include <magellan/framework/core/FixtureTraits.h>
#include <magellan/infra/std/Symbol.h>

////////////////////////////////////////////////////////////////////////////////
#define __DEF_FIXTURE(fixture)                                     \
static magellan::AutoTestSuite<fixture> UNIQUE_NAME(auto_suite_);  \
struct fixture : magellan::TestFixture, magellan::FixtureTraits<fixture>

////////////////////////////////////////////////////////////////////////////////
#define FIXTURE(fixture)  struct fixture; __DEF_FIXTURE(fixture)

////////////////////////////////////////////////////////////////////////////////
#define SETUP()    OVERRIDE(void setUp())
#define TEARDOWN() OVERRIDE(void tearDown())

#endif
