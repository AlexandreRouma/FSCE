#pragma once
#include <fsce/fsce.h>

namespace fsce {
    class ValueClass : public ExpressionClass {
    public:
        ValueClass(double value, std::string name = "");
        double evaluate();
        std::string printHuman();
        Expression derive(std::string by);
        Expression simplify();

        void setValue(double value);
        void setName(std::string name);

        std::string getName();

    private:
        double _value;
        std::string _name;

    };

    Expression Value(double value, std::string name = "");
}