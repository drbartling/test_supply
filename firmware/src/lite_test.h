#ifndef LITE_TEST_H
#define LITE_TEST_H

#include <assert.h>

#define TestAssert(exp)                                                        \
    Nop();                                                                     \
    __conditional_software_breakpoint(exp);                                    \
    Nop();

#define TestPause()                                                            \
    Nop();                                                                     \
    __builtin_software_breakpoint();                                           \
    Nop();

#define RunTest(TestFunction)                                                  \
    Setup();                                                                   \
    TestFunction();                                                            \
    TearDown()

void Setup(void);

void TearDown(void);

#endif
