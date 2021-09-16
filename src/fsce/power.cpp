#include <fsce/power.h>
#include <math.h>

namespace fsce {
    PowerClass::PowerClass(Expression a, Expression b) {
        _a = std::move(a);
        _b = std::move(b);
    }

    double PowerClass::evaluate() {
        return pow(_a->evaluate(), _b->evaluate());
    }

    std::string PowerClass::printHuman() {
        return "(" + _a->printHuman() + " ^ " + _b->printHuman() + ")";
    }

    Expression PowerClass::derive(std::string by) {
        throw std::exception();
    }

    Expression PowerClass::simplify() {
        Expression as = _a->simplify();
        Expression bs = _b->simplify();

        auto avalue = std::dynamic_pointer_cast<fsce::ValueClass>(as);
        auto bvalue = std::dynamic_pointer_cast<fsce::ValueClass>(bs);
        
        if (avalue != nullptr && avalue->evaluate() == 0.0) {
            return Value(0);
        }
        if (bvalue != nullptr && bvalue->evaluate() == 0.0) {
            return Value(1);
        }
        if (bvalue != nullptr && bvalue->evaluate() == 1.0) {
            return as;
        }

        return as ^ bs;
    }

    Expression Power(Expression a, Expression b) {
        return Expression(std::static_pointer_cast<ExpressionClass>(std::make_shared<PowerClass>(a, b)));
    }
}