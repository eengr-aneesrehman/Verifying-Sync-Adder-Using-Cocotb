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
    __Vscope_controller.configure(this, name(), "controller", "controller", -12, VerilatedScope::SCOPE_MODULE);
    
    // Setup scope hierarchy
    __Vhier.add(0, &__Vscope_controller);
    
    // Setup export functions
    for (int __Vfinal=0; __Vfinal<2; __Vfinal++) {
        __Vscope_TOP.varInsert(__Vfinal,"clk", &(TOPp->clk), VLVT_UINT8,VLVD_IN|VLVF_PUB_RW,0);
        __Vscope_TOP.varInsert(__Vfinal,"rdy_in", &(TOPp->rdy_in), VLVT_UINT8,VLVD_OUT|VLVF_PUB_RW,0);
        __Vscope_TOP.varInsert(__Vfinal,"rdy_out", &(TOPp->rdy_out), VLVT_UINT8,VLVD_IN|VLVF_PUB_RW,0);
        __Vscope_TOP.varInsert(__Vfinal,"rst", &(TOPp->rst), VLVT_UINT8,VLVD_IN|VLVF_PUB_RW,0);
        __Vscope_TOP.varInsert(__Vfinal,"val_in", &(TOPp->val_in), VLVT_UINT8,VLVD_IN|VLVF_PUB_RW,0);
        __Vscope_TOP.varInsert(__Vfinal,"val_out", &(TOPp->val_out), VLVT_UINT8,VLVD_OUT|VLVF_PUB_RW,0);
        __Vscope_controller.varInsert(__Vfinal,"clk", &(TOPp->controller__DOT__clk), VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0);
        __Vscope_controller.varInsert(__Vfinal,"rdy_in", &(TOPp->controller__DOT__rdy_in), VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0);
        __Vscope_controller.varInsert(__Vfinal,"rdy_out", &(TOPp->controller__DOT__rdy_out), VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0);
        __Vscope_controller.varInsert(__Vfinal,"rst", &(TOPp->controller__DOT__rst), VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0);
        __Vscope_controller.varInsert(__Vfinal,"state_next", &(TOPp->controller__DOT__state_next), VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW|VLVF_DPI_CLAY,1 ,31,0);
        __Vscope_controller.varInsert(__Vfinal,"state_reg", &(TOPp->controller__DOT__state_reg), VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW|VLVF_DPI_CLAY,1 ,31,0);
        __Vscope_controller.varInsert(__Vfinal,"val_in", &(TOPp->controller__DOT__val_in), VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0);
        __Vscope_controller.varInsert(__Vfinal,"val_out", &(TOPp->controller__DOT__val_out), VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0);
    }
}
