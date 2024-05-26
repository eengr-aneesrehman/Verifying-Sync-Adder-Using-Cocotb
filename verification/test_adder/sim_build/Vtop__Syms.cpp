// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table implementation internals

#include "Vtop__Syms.h"
#include "Vtop.h"



// FUNCTIONS
Vtop__Syms::Vtop__Syms(Vtop* topp, const char* namep)
    // Setup locals
    : __Vm_namep(namep)
    , __Vm_didInit(false)
    // Setup submodule names
{
    // Pointer to top level
    TOPp = topp;
    // Setup each module's pointers to their submodules
    // Setup each module's pointer back to symbol table (for public functions)
    TOPp->__Vconfigure(this, true);
    // Setup scopes
    __Vscope_TOP.configure(this, name(), "TOP", "TOP", 0, VerilatedScope::SCOPE_OTHER);
    __Vscope_adder.configure(this, name(), "adder", "adder", -12, VerilatedScope::SCOPE_MODULE);
    __Vscope_adder__cntr.configure(this, name(), "adder.cntr", "cntr", -12, VerilatedScope::SCOPE_MODULE);
    
    // Setup scope hierarchy
    __Vhier.add(0, &__Vscope_adder);
    __Vhier.add(&__Vscope_adder, &__Vscope_adder__cntr);
    
    // Setup export functions
    for (int __Vfinal=0; __Vfinal<2; __Vfinal++) {
        __Vscope_TOP.varInsert(__Vfinal,"A", &(TOPp->A), VLVT_UINT8,VLVD_IN|VLVF_PUB_RW,1 ,3,0);
        __Vscope_TOP.varInsert(__Vfinal,"B", &(TOPp->B), VLVT_UINT8,VLVD_IN|VLVF_PUB_RW,1 ,3,0);
        __Vscope_TOP.varInsert(__Vfinal,"C", &(TOPp->C), VLVT_UINT8,VLVD_OUT|VLVF_PUB_RW,0);
        __Vscope_TOP.varInsert(__Vfinal,"S", &(TOPp->S), VLVT_UINT8,VLVD_OUT|VLVF_PUB_RW,1 ,3,0);
        __Vscope_TOP.varInsert(__Vfinal,"clk", &(TOPp->clk), VLVT_UINT8,VLVD_IN|VLVF_PUB_RW,0);
        __Vscope_TOP.varInsert(__Vfinal,"rdy_in", &(TOPp->rdy_in), VLVT_UINT8,VLVD_OUT|VLVF_PUB_RW,0);
        __Vscope_TOP.varInsert(__Vfinal,"rdy_out", &(TOPp->rdy_out), VLVT_UINT8,VLVD_IN|VLVF_PUB_RW,0);
        __Vscope_TOP.varInsert(__Vfinal,"rst", &(TOPp->rst), VLVT_UINT8,VLVD_IN|VLVF_PUB_RW,0);
        __Vscope_TOP.varInsert(__Vfinal,"val_in", &(TOPp->val_in), VLVT_UINT8,VLVD_IN|VLVF_PUB_RW,0);
        __Vscope_TOP.varInsert(__Vfinal,"val_out", &(TOPp->val_out), VLVT_UINT8,VLVD_OUT|VLVF_PUB_RW,0);
        __Vscope_adder.varInsert(__Vfinal,"A", &(TOPp->adder__DOT__A), VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,1 ,3,0);
        __Vscope_adder.varInsert(__Vfinal,"B", &(TOPp->adder__DOT__B), VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,1 ,3,0);
        __Vscope_adder.varInsert(__Vfinal,"C", &(TOPp->adder__DOT__C), VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0);
        __Vscope_adder.varInsert(__Vfinal,"S", &(TOPp->adder__DOT__S), VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,1 ,3,0);
        __Vscope_adder.varInsert(__Vfinal,"X", &(TOPp->adder__DOT__X), VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,1 ,4,0);
        __Vscope_adder.varInsert(__Vfinal,"a_reg", &(TOPp->adder__DOT__a_reg), VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,1 ,3,0);
        __Vscope_adder.varInsert(__Vfinal,"b_reg", &(TOPp->adder__DOT__b_reg), VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,1 ,3,0);
        __Vscope_adder.varInsert(__Vfinal,"clk", &(TOPp->adder__DOT__clk), VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0);
        __Vscope_adder.varInsert(__Vfinal,"rdy_in", &(TOPp->adder__DOT__rdy_in), VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0);
        __Vscope_adder.varInsert(__Vfinal,"rdy_out", &(TOPp->adder__DOT__rdy_out), VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0);
        __Vscope_adder.varInsert(__Vfinal,"rst", &(TOPp->adder__DOT__rst), VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0);
        __Vscope_adder.varInsert(__Vfinal,"val_in", &(TOPp->adder__DOT__val_in), VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0);
        __Vscope_adder.varInsert(__Vfinal,"val_out", &(TOPp->adder__DOT__val_out), VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0);
        __Vscope_adder.varInsert(__Vfinal,"x_reg", &(TOPp->adder__DOT__x_reg), VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,1 ,4,0);
        __Vscope_adder__cntr.varInsert(__Vfinal,"clk", &(TOPp->adder__DOT__cntr__DOT__clk), VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0);
        __Vscope_adder__cntr.varInsert(__Vfinal,"rdy_in", &(TOPp->adder__DOT__cntr__DOT__rdy_in), VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0);
        __Vscope_adder__cntr.varInsert(__Vfinal,"rdy_out", &(TOPp->adder__DOT__cntr__DOT__rdy_out), VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0);
        __Vscope_adder__cntr.varInsert(__Vfinal,"rst", &(TOPp->adder__DOT__cntr__DOT__rst), VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0);
        __Vscope_adder__cntr.varInsert(__Vfinal,"state_next", &(TOPp->adder__DOT__cntr__DOT__state_next), VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW|VLVF_DPI_CLAY,1 ,31,0);
        __Vscope_adder__cntr.varInsert(__Vfinal,"state_reg", &(TOPp->adder__DOT__cntr__DOT__state_reg), VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW|VLVF_DPI_CLAY,1 ,31,0);
        __Vscope_adder__cntr.varInsert(__Vfinal,"val_in", &(TOPp->adder__DOT__cntr__DOT__val_in), VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0);
        __Vscope_adder__cntr.varInsert(__Vfinal,"val_out", &(TOPp->adder__DOT__cntr__DOT__val_out), VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0);
    }
}
