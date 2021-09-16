#include <stdio.h>
#include <fsce/fsce.h>

int main() {
    fsce::Expression val1 = fsce::Value(42.0, "a");
    fsce::Expression val2 = fsce::Value(2.0, "b");
    fsce::Expression val3 = fsce::Value(69.0, "c");

    fsce::Expression sum1 = (val1 ^ val2) / val3;
    fsce::Expression sum1simple = sum1->simplify();

    printf("%s = %lf\n", sum1->printHuman().c_str(), (double)sum1);
    printf("%s = %lf\n", sum1simple->printHuman().c_str(), (double)sum1simple);

    return 0;
}