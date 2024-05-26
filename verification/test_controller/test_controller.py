import cocotb
from cocotb.clock import Clock
from cocotb.triggers import Timer, RisingEdge, FallingEdge, Join, ClockCycles
from cocotb.regression import TestFactory
import sys
import os
import numpy as np
import random

#DRIVER
async def driver(dut,val_in,rdy_out):
    dut.val_in <= val_in
    dut.rdy_out <= rdy_out
    await Timer(0.002*10, units="ns")
#MONITOR
# async def monitor(dut):
#     res = 0
#     while(1):
#         await RisingEdge(dut.clk)
#         if(dut.val_out.value == 1):
#             res = int(dut.res.value.binstr,2)
#             break;
#     return res

@cocotb.test() #we use it without test factory
async def controller_test(dut):
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

    val_in = 1
    rdy_out = 1

    #Wait a clock cycle then start the driver and monitor thread
    driver_task  = cocotb.fork(driver(dut,val_in,rdy_out))
    # monitor_task = cocotb.fork(monitor(dut))
    
    #Wait for the processes to finish and capture the result
    await Join(driver_task)
    # await Join(monitor_task)