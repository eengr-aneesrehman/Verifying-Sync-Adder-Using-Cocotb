# Verifying-Sync-Adder-Using-Cocotb

## Overview

Welcome to the "Verifying-Sync-Adder-Using-Cocotb" repository! This project demonstrates the verification of a synchronous adder module using Cocotb, a coroutine-based cosimulation library for writing testbenches in Python. The repository includes the RTL design of the synchronous adder, testbenches, and simulation scripts.

## Repository Structure
![image](https://github.com/eengr-aneesrehman/Verifying-Sync-Adder-Using-Cocotb/assets/103167188/24261262-6557-4f8a-bea4-b4c43bedc954)

- **sources/:** Contains the RTL design files.
   - `adder.sv`
   - `controller.sv` 
- **verification/:** Contains the testbenches written using Cocotb.
   - **test_adder/:**
       - `Makefile`
       - `test_adder.py`
   - **test_controller**
       - `Makefile`
       - `test_controller.py`
- **model/:** Contains the ideal software model of the RTL
   - `model.py`

## Prerequisites

To run the simulations, ensure you have the following software installed:

- Python 3.6+
- Cocotb
- A Verilog simulator (e.g., Synopsys VCS, Verilator, Icarus Verilog)

## Detailed Documentation

- ### Synchronous Adder (adder.sv)
  The synchronous adder is a basic digital design module that adds two input signals and provides the sum and carry output. It takes four cycles to give output. The design is implemented in System Verilog and can be found in the `sources/` directory.

- ### Cocotb Testbench (test_adder.py)
  The testbench for the synchronous adder is written in Python using the Cocotb library. It includes various test cases to verify the functionality of the adder under different scenarios. The testbench is located in the `verification/test_adder/` directory.

- ### Simulation Script (Makefile)
  The simulation script sets up the environment and run the simulation. This script is located in the `verification/test_adder/` directory.

## Contact

For any questions or issues, please open an issue on GitHub or contact aneesrehmanroonjho@gmail.com.

Best of luck!
