#pragma once
#include "base.h"
#include "memory.h"
#include "cpu.h"
using namespace SimulatorUnit;
using namespace SimulatorUnit::CpuUnit;
using namespace SimulatorUnit::MemoryUnit;


namespace SimulatorUnit {
  class Simulator {
    public:
      Simulator() : cpu_(&memory_) {
        cpu_.reset();
      }
      
      void dump(){
        memory_.dump();
        cpu_.dump();
      }
    
      void read_program() {
        short_t user_input = 0;
        byte_t counter = 0;
        while(true){
          
          // Get user input
          cout << (short_t)counter << " ? ";
          cin >> user_input;
          
          // Validate user input
          if(cin.fail()){
            cout << "[*] ERROR: INVALID INPUT!" << endl;
            user_input = 0;
            cin.clear();
            cin.ignore();
            continue;
          }
          
          if(user_input == (short_t)-9999){
            cout << "[*] Program loading completed." << endl;
            break;
          }
          
          memory_.write(counter,user_input);
          
          ++counter;
        }
      }
    
      void run_program() {
        while(cpu_.next()){
          
        }
      }
    
      void simulate() {
        read_program();
        cpu_.reset();
        cout << "[*] Program execution begins." << endl << endl;
        run_program();
        cout << endl << endl << "[*] Program execution terminated." << endl << endl;
        dump();
      }
    private:
      Memory memory_;
      Cpu cpu_;
  };
}