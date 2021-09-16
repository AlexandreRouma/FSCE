#pragma once
#include <vector>
#include <memory>
#include <string>

namespace fsce {
    class Expression;

    class ExpressionClass {
    public:
        virtual ~ExpressionClass() {}
        virtual double evaluate() = 0;
        virtual std::string printHuman() = 0;
        virtual std::string printLaTeX() { return printHuman(); }
        virtual Expression derive(std::string by) = 0;
        virtual Expression simplify() = 0;
    };

    class Expression : public std::shared_ptr<ExpressionClass> {
    public:
        Expression() {}
        Expression(std::shared_ptr<ExpressionClass> a) : std::shared_ptr<ExpressionClass>(a) {}

        Expression operator+(Expression b);
        Expression operator-(Expression b);
        Expression operator*(Expression b);
        Expression operator/(Expression b);
        Expression operator^(Expression b);

        explicit operator std::string() const { return (*this)->printHuman(); }
        explicit operator double() const { return (*this)->evaluate(); }
    };
}

#include <fsce/value.h>
#include <fsce/sum.h>
#include <fsce/difference.h>
#include <fsce/multiply.h>
#include <fsce/divide.h>
#include <fsce/power.h>