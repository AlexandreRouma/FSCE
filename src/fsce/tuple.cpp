#include <fsce/tuple.h>
#include <exception>

namespace fsce {
    double TupleClass::evaluate() {
        throw std::exception();
    }

    std::string TupleClass::printHuman() {
        std::string rec = "[";
        bool first = true;
        for (auto& e : elements) {
            rec += ", ";
            if (first) { first = false; }
            rec += e->printHuman();
        }
        return rec;
    }
}