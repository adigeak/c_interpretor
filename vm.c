#include <stdio.h>

#include "common.h"
#include "vm.h"
#include "debug.h"

VM vm;

void initVM() {
}

void freeVM() {
}

static InterpretResult run() {
	for(;;) {
		#ifdef DEBUG_TRACE_EXECUTION
		disassembleInstruction(vm.chunk, (int)(vm.ip - vm.chunk->code));
#endif

		uint8_t instruction;
		switch(instruction = *vm.ip++) {
			case OP_CONSTANT: {
					  Value constant = vm.chunk->constants.values[*vm.ip++];
					  printValue(constant);
					  printf("\n");
					  break;
					  }
			case OP_RETURN: {
					return INTERPRET_OK;
					}
		}
	}
}

InterpretResult interpret(Chunk* chunk) {
	vm.chunk = chunk;
	vm.ip = vm.chunk->code;
	return run();
}
