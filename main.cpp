#include <stdio.h>
#include <fsce/fsce.h>

#define fn aut

int main() {
    fsce::Expression val1 = fsce::Value(42.0);
    fsce::Expression val2 = fsce::Value(54.0);
    fsce::Expression val3 = fsce::Value(69.0);

    fsce::Expression sum1 = val2 * val3 / val1;

    printf("%s = %lf\n", sum1->printHuman().c_str(), (double)sum1);

    return 0;
}

auto test() {
    return 4;
}