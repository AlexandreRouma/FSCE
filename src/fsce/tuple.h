#pragma once
#include <fsce/fsce.h>
#include <vector>

namespace fsce {
    class TupleClass : ExpressionClass {
    public:
        double evaluate();
        std::string printHuman();

        std::vector<Expression> elements;

    private:
        

    };
}