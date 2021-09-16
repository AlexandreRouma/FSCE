#include <fsce/divide.h>

namespace fsce {
    DivideClass::DivideClass(Expression a, Expression b) {
        _a = std::move(a);
        _b = std::move(b);
    }

    double DivideClass::evaluate() {
        return _a->evaluate() / _b->evaluate();
    }

    std::string DivideClass::printHuman() {
        return "(" + _a->printHuman() + " / " + _b->printHuman() + ")";
    }

    Expression DivideClass::derive(std::string by) {
        return ((_a * _b->derive(by)) - (_a->derive(by) * _b)) / (_b * _b);
    }

    Expression DivideClass::simplify(Expression self) {
        Expression as = _a->simplify(_a);
        Expression bs = _b->simplify(_b);

        auto avalue = std::dynamic_pointer_cast<fsce::ValueClass>(as);
        auto bvalue = std::dynamic_pointer_cast<fsce::ValueClass>(bs);
        
        if (avalue != nullptr && avalue->evaluate() == 0.0) {
            return Value(0);
        }
        if (bvalue != nullptr && bvalue->evaluate() == 1.0) {
            return as;
        }

        return as / bs;
    }

    Expression Divide(Expression a, Expression b) {
        return Expression(std::static_pointer_cast<ExpressionClass>(std::make_shared<DivideClass>(a, b)));
    }
}