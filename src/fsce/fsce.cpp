#include <fsce/fsce.h>

namespace fsce {
    Expression Expression::operator+(Expression b) {
        return Expression(std::static_pointer_cast<ExpressionClass>(std::make_shared<SumClass>(*this, b)));
    }

    Expression Expression::operator-(Expression b) {
        return Expression(std::static_pointer_cast<ExpressionClass>(std::make_shared<DifferenceClass>(*this, b)));
    }

    Expression Expression::operator*(Expression b) {
        return Expression(std::static_pointer_cast<ExpressionClass>(std::make_shared<MultiplyClass>(*this, b)));
    }

    Expression Expression::operator/(Expression b) {
        return Expression(std::static_pointer_cast<ExpressionClass>(std::make_shared<DivideClass>(*this, b)));
    }

    Expression Expression::operator^(Expression b) {
        return Expression(std::static_pointer_cast<ExpressionClass>(std::make_shared<PowerClass>(*this, b)));
    }
}