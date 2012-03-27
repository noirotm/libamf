#include "../UnitTest++.h"
#include "../TestReporterStdout.h"

TEST(OneEqualsZero) {
    CHECK(1 == 0);
}

int main(int, char const *[])
{
    return UnitTest::RunAllTests();
}
