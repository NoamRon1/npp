#ifndef NPP_VM_H
#define NPP_VM_H

#include "chunk.h"

#define STACK_MAX 256

class VM {
public:
    VM() = default;
    void run(const chunk& chunk);

private:
    double _stack[STACK_MAX];
    double* _sp = _stack; //stack pointer

    //helpers
    void push(double value);
    double pop(); 
};


#endif //NPP_VM_H
