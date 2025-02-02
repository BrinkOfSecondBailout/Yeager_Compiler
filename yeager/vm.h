#ifndef yeager_vm_h
#define yeager_vm_h

#include "chunk.h"
#include "value.h"
#define STACK_MAX 256


typedef struct {
    uint8_t *ip;
    Chunk *chunk;
    Value stack[STACK_MAX];
    Value *stackTop;
} Vm;

typedef enum {
    INTERPRET_OK,
    INTERPRET_COMPILE_ERROR,
    INTERPRET_RUNTIME_ERROR
} InterpretResult;

void initVm();
void freeVm();
InterpretResult interpret(Chunk *chunk);
void push(Value value);
Value pop();

#endif