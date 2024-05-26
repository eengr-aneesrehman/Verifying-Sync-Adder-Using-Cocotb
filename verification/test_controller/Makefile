# Cocotb settings 
TOPLEVEL_LANG ?= verilog  #HDL
SIM ?= vcs #verilator #icarus

# List all system verilog 
PWD=$(shell pwd)
VERILOG_SOURCES = $(PWD)/../../sources/controller.sv
# VERILOG_SOURCES = $(wildcard $(PWD)/../../sources/*.sv)

TOPLEVEL := controller			 # RTL top-level module name
MODULE   := test_controller      # Name of the Python test module

include $(shell cocotb-config --makefiles)/Makefile.sim