# Makefile for cocotb-based testbench
# Cocotb settings 
TOPLEVEL_LANG ?= verilog   #HDL
SIM ?= vcs #verilator #icarus

PWD=$(shell pwd)
VERILOG_SOURCES = $(wildcard $(PWD)/../../sources/*.sv)  #directory having all the verilog source files (.sv).

TOPLEVEL := adder  				# RTL top-level module name
MODULE := test_adder  			# Name of the Python test module

include $(shell cocotb-config --makefiles)/Makefile.sim