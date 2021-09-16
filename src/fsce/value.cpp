#include <fsce/value.h>
#include <sstream>

namespace fsce {
    ValueClass::ValueClass(double value, std::string name) {
        _value = value;
        _name = name;
    }

    double ValueClass::evaluate() {
        return _value;
    }

    std::string ValueClass::printHuman() {
        std::stringstream ss;
        if (!_name.empty()) {
            ss << _name;
        }
        else {
            ss << _value;
        }
        return ss.str();
    }

    Expression ValueClass::derive(std::string by) {
        if (_name.empty() || _name != by) { return Value(0); }
        return Value(1);
    }

    Expression ValueClass::simplify() {
        // TODO:  REPLACE THIS WITH SOMETHING THAT WILL KEEP THE LINK
        return Value(_value, _name);
    }

    std::string ValueClass::getName() {
        return _name;
    }

    void ValueClass::setValue(double value) {
        _value = value;
    }

    void ValueClass::setName(std::string name) {
        _name = name;
    }

    Expression Value(double value, std::string name) {
        return Expression(std::static_pointer_cast<ExpressionClass>(std::make_shared<ValueClass>(value, name)));
    }
}