#include <stdio.h>
#include <fsce/fsce.h>

int main() {
    fsce::Expression sum1 = (fsce::Value(1.0/2.0) * fsce::Value(2, "a") * (fsce::Value(2, "t") ^ fsce::Value(2))) + (fsce::Value(2, "v") * fsce::Value(2, "t")) + fsce::Value(2, "x0");
    fsce::Expression sum1simple = sum1->simplify();
    fsce::Expression der1 = sum1simple->derive("t");
    fsce::Expression der1simple = der1->simplify();
    fsce::Expression der2 = der1simple->derive("t");
    fsce::Expression der2simple = der2->simplify();

    //printf("%s = %lf\n", sum1->printHuman().c_str(), (double)sum1);
    printf("%s\n", sum1simple->printHuman().c_str(), (double)sum1simple);
    //printf("%s = %lf\n", der1->printHuman().c_str(), (double)der1);
    printf("%s\n", der1simple->printHuman().c_str(), (double)der1simple);
    //printf("%s = %lf\n", der2->printHuman().c_str(), (double)der2);
    printf("%s\n", der2simple->printHuman().c_str(), (double)der2simple);

    return 0;
}