import cocotb
from cocotb.clock import Clock
from cocotb.triggers import Timer, RisingEdge, FallingEdge, Join, ClockCycles
from cocotb.regression import TestFactory
import sys
import os
import numpy as np
import random

# import custom python methods aka model
sys.path.insert(1, "../../model/")
from adder_model import adder_model

# input from environmental varible in the terminal
if ("TEST_SETS" in os.environ):
    sets = int(os.environ["TEST_SETS"])
else:
    sets = 1

#DRIVER
async def driver(dut,val_in,rdy_out,a,b):
    dut.val_in <= val_in
    dut.rdy_out <= rdy_out
    dut.A <= a
    dut.B <= b

#MONITOR
async def monitor(dut):
    S = 0
    C = 0
    while(1):
        await RisingEdge(dut.clk)
        if(dut.val_out.value == 1):
            S = dut.S.value.binstr
            C = dut.C.value.binstr
            res = int(C+S,2)
            break;
    return res

# @cocotb.test() no need with testfactory
async def adder_basic_test(dut,test_set):
    #Create 0.002ns period clock on port clk
    clock = Clock(dut.clk, 0.002, units="ns")                 
    #Start the clock
    cocotb.fork(clock.start())                                
    #Reset
    await RisingEdge(dut.clk)
    dut.rst      <= 1
    #Set reset to low
    await RisingEdge(dut.clk)
    dut.rst      <= 0

    val_in  = 1#random.randint(0,1)
    rdy_out = 1#random.randint(0,1)

    a = random.randint(0, 15)
    b = random.randint(0, 15)

    #Wait a clock cycle then start the driver and monitor thread
    driver_task  = cocotb.fork(driver(dut,val_in,rdy_out,a,b))
    monitor_task = cocotb.fork(monitor(dut))
    
    #Wait for the processes to finish and capture the result
    await Join(driver_task)
    dut_res = await Join(monitor_task)

    model_res = adder_model(a,b)

    print(f"A={a}  B={b}  DUT={dut_res}  MODEL={model_res}")
    assert dut_res == model_res, f"Adder result of {a}+{b} is incorrect: {dut_res} != {model_res}"

# # ============ Test case generation ==================  
tf = TestFactory (test_function=adder_basic_test)        
tf.add_option("test_set" ,[(i+1) for i in range(sets)])     #number of test set we want to run               
tf.generate_tests()  