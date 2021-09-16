#pragma once
#include <fsce/fsce.h>

namespace fsce {
    class MultiplyClass : public ExpressionClass {
    public:
        MultiplyClass(Expression a, Expression b);
        double evaluate();
        std::string printHuman();
        Expression derive(std::string by);
        Expression simplify(Expression self);

    private:
        Expression _a;
        Expression _b;

    };

    Expression Multiply(Expression a, Expression b);
}