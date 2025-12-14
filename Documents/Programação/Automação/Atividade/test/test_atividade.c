#include "unity.h"
#include "atividade.h"

void setUp(void) {}
void tearDown(void) {}

void test_soma(void) {
    TEST_ASSERT_EQUAL(4, soma(2, 2));
}

int main(void)
{
    UNITY_BEGIN();
    RUN_TEST(test_soma);
    return UNITY_END();
}