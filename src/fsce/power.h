#pragma once
#include <fsce/fsce.h>

namespace fsce {
    class PowerClass : public ExpressionClass {
    public:
        PowerClass(Expression a, Expression b);
        double evaluate();
        std::string printHuman();
        Expression derive(std::string by);
        Expression simplify();

    private:
        Expression _a;
        Expression _b;

    };

    Expression Power(Expression a, Expression b);
}