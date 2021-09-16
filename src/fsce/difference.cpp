#include <fsce/difference.h>

namespace fsce {
    DifferenceClass::DifferenceClass(Expression a, Expression b) {
        _a = std::move(a);
        _b = std::move(b);
    }

    double DifferenceClass::evaluate() {
        return _a->evaluate() - _b->evaluate();
    }

    std::string DifferenceClass::printHuman() {
        return "(" + _a->printHuman() + " - " + _b->printHuman() + ")";
    }

    Expression DifferenceClass::derive(std::string by) {
        return _a->derive(by) - _b->derive(by);
    }

    Expression DifferenceClass::simplify(Expression self) {
        Expression as = _a->simplify(_a);
        Expression bs = _b->simplify(_b);

        auto avalue = std::dynamic_pointer_cast<fsce::ValueClass>(as);
        auto bvalue = std::dynamic_pointer_cast<fsce::ValueClass>(bs);
        
        if (avalue != nullptr && bvalue != nullptr && avalue->evaluate() == 0.0 && bvalue->evaluate() == 0.0) {
            return Value(0);
        }
        if (bvalue != nullptr && bvalue->evaluate() == 0.0) {
            return as;
        }

        return as - bs;
    }

    Expression Difference(Expression a, Expression b) {
        return Expression(std::static_pointer_cast<ExpressionClass>(std::make_shared<DifferenceClass>(a, b)));
    }
}