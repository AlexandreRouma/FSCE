#pragma once
#include <fsce/fsce.h>

namespace fsce {
    class SumClass : public ExpressionClass {
    public:
        SumClass(Expression a, Expression b);
        double evaluate();
        std::string printHuman();
        Expression derive(std::string by);
        Expression simplify(Expression self);

    private:
        Expression _a;
        Expression _b;

    };

    Expression Sum(Expression a, Expression b);
}