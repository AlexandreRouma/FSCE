#include <fsce/multiply.h>

namespace fsce {
    MultiplyClass::MultiplyClass(Expression a, Expression b) {
        _a = std::move(a);
        _b = std::move(b);
    }

    double MultiplyClass::evaluate() {
        return _a->evaluate() * _b->evaluate();
    }

    std::string MultiplyClass::printHuman() {
        return "(" + _a->printHuman() + " * " + _b->printHuman() + ")";
    }

    Expression MultiplyClass::derive(std::string by) {
        return (_a * _b->derive(by)) + (_a->derive(by) * _b);
    }

    Expression MultiplyClass::simplify() {
        Expression as = _a->simplify();
        Expression bs = _b->simplify();

        auto avalue = std::dynamic_pointer_cast<fsce::ValueClass>(as);
        auto bvalue = std::dynamic_pointer_cast<fsce::ValueClass>(bs);
        
        if (avalue != nullptr && avalue->evaluate() == 0.0) {
            return Value(0);
        }
        if (bvalue != nullptr && bvalue->evaluate() == 0.0) {
            return Value(0);
        }
        if (avalue != nullptr && avalue->evaluate() == 1.0) {
            return bs;
        }
        if (bvalue != nullptr && bvalue->evaluate() == 1.0) {
            return as;
        }

        return as * bs;
    }

    Expression Multiply(Expression a, Expression b) {
        return Expression(std::static_pointer_cast<ExpressionClass>(std::make_shared<MultiplyClass>(a, b)));
    }
}