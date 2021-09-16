#pragma once
#include <fsce/fsce.h>

namespace fsce {
    class DivideClass : public ExpressionClass {
    public:
        DivideClass(Expression a, Expression b);
        double evaluate();
        std::string printHuman();
        Expression derive(std::string by);
        Expression simplify();

    private:
        Expression _a;
        Expression _b;

    };

    Expression Divide(Expression a, Expression b);
}