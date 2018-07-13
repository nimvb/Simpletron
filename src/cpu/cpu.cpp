#include "../../include/cpu.h"

namespace SimulatorUnit {
  namespace CpuUnit {
    
    Cpu::Cpu(Memory* memory){
      reset();
      memory_ = memory;
    }
    
    void Cpu::reset(){
      // Your code here!
    }
    
    bool Cpu::next(){
      bool ok = false;
      fetch();
      decode();
      Opcodes opcode = (Opcodes)operation_code_;
      switch(opcode){
					// Your code here!
				default:
          ok = false;
          break;
          
      }
      
      return ok;
    }
            
    void Cpu::fetch(){
      // Your code here!
    }
       
    void Cpu::decode(){
      // Your code here!
    }
    
    void Cpu::read(byte_t index){
      // Your code here!
    }
        
    void Cpu::write(byte_t index){
      // Your code here!
    }

    void Cpu::load(byte_t index){
      // Your code here!
    }
      
    void Cpu::store(byte_t index){
      // Your code here!
    }

    void Cpu::add(byte_t index){
      // Your code here!
    }

    void Cpu::subtract(byte_t index){
      // Your code here!
    }
      
    void Cpu::divide(byte_t index){
      // Your code here!
    }
      
    void Cpu::multiply(byte_t index){
      // Your code here!
    }
      
    void Cpu::branch(){
      // Your code here!
    }
      
    void Cpu::branch_neg(){
      // Your code here!
    }
      
    void Cpu::branch_zero(){
      // Your code here!
    }
    
    void Cpu::halt(){
      // Your code here!
    }
    
    void Cpu::dump(){
      cout << "***** CPU DUMP *****" << endl;
      cout << "[!] ACCUMLATOR : " << accumulator_ << endl;
      cout << "[!] INSTRUCTION REGISTER : " << instruction_register_ << endl;
      cout << "[!] INSTRUCTION POINTER : " << (ushort_t)instruction_pointer_ << endl;
      cout << endl;
    }
    
  }
}