#pragma once
#include <fsce/fsce.h>

namespace fsce {
    class ExpClass : public ExpressionClass {
    public:
        ExpClass(Expression arg);
        double evaluate();
        std::string printHuman();
        Expression derive(std::string by);
        Expression simplify();

    private:
        Expression _arg;

    };

    Expression Exp(Expression arg);
}