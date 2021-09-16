#include <stdio.h>
#include <fsce/fsce.h>

int main() {
    fsce::Expression val1 = fsce::Value(42.0, "a");
    fsce::Expression val2 = fsce::Value(54.0, "b");
    fsce::Expression val3 = fsce::Value(69.0, "c");

    fsce::Expression sum1 = (val1 + val2) / val3;

    printf("%s = %lf\n", sum1->printHuman().c_str(), (double)sum1);

    fsce::Expression der1 = sum1->derive("b");

    fsce::Expression der1simple = der1->simplify(der1);

    printf("%s = %lf\n", sum1->printHuman().c_str(), (double)sum1);
    printf("%s = %lf\n", der1->printHuman().c_str(), (double)der1);
    printf("%s = %lf\n", der1simple->printHuman().c_str(), (double)der1simple);

    std::dynamic_pointer_cast<fsce::ValueClass>(val3)->setName("t");

    printf("%s = %lf\n", sum1->printHuman().c_str(), (double)sum1);
    printf("%s = %lf\n", der1->printHuman().c_str(), (double)der1);
    printf("%s = %lf\n", der1simple->printHuman().c_str(), (double)der1simple);

    return 0;
}