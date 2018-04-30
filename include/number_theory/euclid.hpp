#ifndef EUCLID_HPP
#define EUCLID_HPP

#include <stdexcept>

namespace cgn {
    template <typename T>
    T gcd_euclid(T a, T b) {
        if(a <= 0 || b <= 0) {
            throw std::invalid_argument("Arguments must be natural numbers");
        }

        while(b != 0) {
            auto t = b;
            b = a % b;
            a = t;
        }

        return a;
    }
}

#endif
