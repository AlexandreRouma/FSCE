#pragma once
#include <fsce/fsce.h>

namespace fsce {
    class DifferenceClass : public ExpressionClass {
    public:
        DifferenceClass(Expression a, Expression b);
        double evaluate();
        std::string printHuman();
        Expression derive(std::string by);
        Expression simplify();

    private:
        Expression _a;
        Expression _b;

    };

    Expression Difference(Expression a, Expression b);
}