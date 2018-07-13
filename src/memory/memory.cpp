#include "../../include/memory.h"

namespace SimulatorUnit {
  namespace MemoryUnit {
    const int Memory::kSize;
    
    Memory::Memory(){
      byte_t index = 0;
      for(index = 0 ; index < kSize; index++){
        write(index,0);
      }
    }
    
    void Memory::write(byte_t index,short_t data){
      // Your code here!
    }
    
    short_t Memory::read(byte_t index){
      short_t value = 0;
      // Your code here!
      return value;
    }
    
    short_t* Memory::get_mem(){
      return mem_;
    }
    
    void Memory::dump() {
      byte_t index = 0;
      byte_t line_counter = 0;
      cout << "***** MEMORY DUMP *****" << endl;
      cout << left;
      cout << " " << (ushort_t)(line_counter) << "\t";
      for(index = 0 ; index < kSize; index++){
        short_t value = read(index);
        cout << setw(4) << value << " ";
        if((index + 1) % 8 == 0){
          cout << endl;
          cout << " " << setw(4) << (ushort_t)(++line_counter) << "\t";
        }
      }
      
      cout << endl;
    }
    
    
  }
}