#include <fsce/sum.h>

namespace fsce {
    SumClass::SumClass(Expression a, Expression b) {
        _a = std::move(a);
        _b = std::move(b);
    }

    double SumClass::evaluate() {
        return _a->evaluate() + _b->evaluate();
    }

    std::string SumClass::printHuman() {
        return "(" + _a->printHuman() + " + " + _b->printHuman() + ")";
    }

    Expression SumClass::derive(std::string by) {
        return _a->derive(by) + _b->derive(by);
    }

    Expression SumClass::simplify() {
        Expression as = _a->simplify();
        Expression bs = _b->simplify();

        auto avalue = std::dynamic_pointer_cast<fsce::ValueClass>(as);
        auto bvalue = std::dynamic_pointer_cast<fsce::ValueClass>(bs);
        
        if (avalue != nullptr && bvalue != nullptr && avalue->evaluate() == 0.0 && bvalue->evaluate() == 0.0) {
            return Value(0);
        }
        if (avalue != nullptr && avalue->evaluate() == 0.0) {
            return bs;
        }
        if (bvalue != nullptr && bvalue->evaluate() == 0.0) {
            return as;
        }

        return as + bs;
    }

    Expression Sum(Expression a, Expression b) {
        return Expression(std::static_pointer_cast<ExpressionClass>(std::make_shared<SumClass>(a, b)));
    }
}