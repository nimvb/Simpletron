#pragma once
#include "base.h"

namespace SimulatorUnit {
  namespace MemoryUnit {
    
    class Memory {
      public:
      
        // [!!] Constructor
        Memory();
      
        // [!!] Write a word value into specefic location of memory.
        void write(byte_t index,short_t data);
      
        // [!!] Read a value of the memory location at specefic memory location.Read
        // [*]  Note: Consider bound checking.
        short_t read(byte_t index);
      
        // [!!] Returns a pointer to the beginning of the memory unit
        short_t* get_mem();
      
        // [!!] Dump memory values
        void dump();
      
      private:
      
        // [!!] Size of the memory.
        const static int kSize = 100;
      
        // [!!] Array that represents the memory locations.
        short_t mem_[Memory::kSize];
    };
    
  }
}