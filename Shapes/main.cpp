#include "..\cppunitlite\TestHarness.h"
#include "utShapes.h"
#include "Functions.h"
int main()
{
    TestResult tr;
    TestRegistry::runAllTests(tr);
    runGeometry();

    return 0;
}

