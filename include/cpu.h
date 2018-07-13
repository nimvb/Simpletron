#pragma once
#include "memory.h"

using namespace SimulatorUnit::MemoryUnit;

namespace SimulatorUnit {
  namespace CpuUnit {
    
    // [!!] Opcodes definition.
    // [*]  Note: Read each opcode definition from the book.
    typedef enum {
      READ = 10,
      WRITE = 11,
      LOAD = 20,
      STORE = 21,
      ADD = 30,
      SUBTRACT = 31,
      DIVIDE = 32,
      MULTIPLY = 33,
      BRANCH = 40,
      BRANCHNEG = 41,
      BRANCHZERO = 42,
      HALT = 43
    } Opcodes;
    
    
    // [!!] Cpu class definition, complete it by reading descriptions.
    class Cpu {
      public:
        
        // [!!] Constructor: Responsible to reset the cpu state into it's initiate state.
        Cpu(Memory* memory);
        
        // [!!] Reset the cpu and it's registers to their initated state.
        void reset();
      
        // [!!] Read instruction from the memory and executes it.Read
        // [*]  Note: Steps for executing one instruction:
        //              [1]: Fetch value of the memory which is pointed by instruction pointer into instruction register
        //              [2]: Decode the value inside the instruction register to retrive the opcode and operand of it.
        //              [3]: Based on the extracted opcode try to perform the required operations, and also change the instruction pointer value so that it will be pointed to the correct
        //                   location of memory in the next round.
        // @return: true if the operation is done correctly, otherwise false will be returned.
        bool next();
      
        // [!!] Dump CPU registers value;
        void dump();
        
      private:
        // [!!] Required registers for CPU unit.
        //        [.] Accumulator : Used as a location to store desired value of the memory in it.
        //        [.] Instruction register : To process the command, first you should fetch it from the memory into this register.
        short_t instruction_register_;
        short_t accumulator_;
      
        // [*]  Note: Instruction pointer variable usage is about pointing to the specefic memory location.
        byte_t instruction_pointer_;
      
        // [*]  Note: You should fill them with proper values after fetching the instruction value into the instruction register,
        byte_t operation_code_;
        byte_t operand_;
      
        // [!!] Pointer to memory unit
        Memory* memory_;
        
        // [!!] Fetch an instruction from the memory.
        void fetch();
      
        // [!!] Decode the instruction.
        void decode();
        
        // [!!] Read from terminal and put the value into desired location which defined by index parameter.
        void read(byte_t index);
        
        // [!!] Read value of the specefic memory location value and put it down into terminal screen.
        void write(byte_t index);
        
        // [!!] Put the value of the specefic memory location into accumulator.
        void load(byte_t index);
      
        // [!!] Put the value inside the accumulator into the specefic memory location.
        void store(byte_t index);
      
        // [!!] Add the value stored in the specefic memory location to the value in the accumulator, and store the result in accumulator.
        void add(byte_t index);
      
        // [!!] Subtract the value stored in the specefic memory location from the value in the accumulator, and store the result in accumulator.
        void subtract(byte_t index);
      
        // [!!] Divide the value stored in the specefic memory location into the value in the accumulator, and store the result in accumulator.
        void divide(byte_t index);
      
        // [!!] Multiply the value stored in the specefic memory location by the value in the accumulator, and store the result in accumulator.
        void multiply(byte_t index);
      
        // [!!] Branch to a specific location in memory.
        void branch();
      
        // [!!] Branch to a specific location in memory if the value inside the accumulator is negative.
        void branch_neg();
      
        // [!!] Branch to a specific location in memory if the value inside the accumulator is zero.
        void branch_zero();
      
        // [!!] Halt
        void halt();
      
      
        
    };
  }
}