#include <fsce/exp.h>
#include <math.h>
#include <sstream>

namespace fsce {
    ExpClass::ExpClass(Expression arg) {
        _arg = arg;
    }

    double ExpClass::evaluate() {
        return pow(2.71828182845904523, _arg->evaluate());
    }

    std::string ExpClass::printHuman() {
        std::stringstream ss;
        ss << "(e ^ " << _arg->printHuman() << ")";
        return ss.str();
    }

    Expression ExpClass::derive(std::string by) {
        return Exp(_arg) * _arg->derive(by);
    }

    Expression ExpClass::simplify() {
        // TODO:  REPLACE THIS WITH SOMETHING THAT WILL KEEP THE LINK
        return Exp(_arg);
    }

    Expression Exp(Expression arg) {
        return Expression(std::static_pointer_cast<ExpressionClass>(std::make_shared<ExpClass>(arg)));
    }
}