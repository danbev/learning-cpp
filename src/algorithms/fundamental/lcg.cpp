#include <iostream>

/*
 * Linear Congruential Generator.
 */
class LCG {
    private:
        unsigned int seed;
        unsigned int a;
        unsigned int b;
        unsigned int m;
    public:
    LCG(unsigned int seed, unsigned int a = 5, unsigned int b = 3, unsigned int m = 7) {
        this->seed = seed;
        this->a = a;
        this->b = b;
        this->m = m;
    }
    ~LCG() { }
    unsigned int generate() {
        seed = (seed * a + b) % m;
        return seed;
    }
    friend std::ostream & operator<<(std::ostream &os, const LCG &lcg) {
        os << "LCG[seed=" << lcg.seed << ", a=" << lcg.a << ", b=" << lcg.b << ", m=" << lcg.m << "]";
        return os;
    }
};

