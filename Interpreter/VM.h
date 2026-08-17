#ifndef NPP_VM_H
#define NPP_VM_H

#include "Chunk.h"

#define STACK_MAX 256

class VM {
public:
    VM() = default;
    void run(const Chunk& chunk);

private:
    uint32_t _stack[STACK_MAX];
    uint32_t* _sp = _stack; //stack pointer

    //helpers
    void push(double value);
    uint32_t pop();
};


#endif //NPP_VM_H
