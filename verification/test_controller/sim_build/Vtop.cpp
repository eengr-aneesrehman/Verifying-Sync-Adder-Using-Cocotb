// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop.h"
#include "Vtop__Syms.h"

#include "verilated_dpi.h"

//==========

VL_CTOR_IMP(Vtop) {
    Vtop__Syms* __restrict vlSymsp = __VlSymsp = new Vtop__Syms(this, name());
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Reset internal values
    
    // Reset structure values
    _ctor_var_reset();
}

void Vtop::__Vconfigure(Vtop__Syms* vlSymsp, bool first) {
    if (false && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
    if (false && this->__VlSymsp) {}  // Prevent unused
    Verilated::timeunit(-12);
    Verilated::timeprecision(-12);
}

Vtop::~Vtop() {
    VL_DO_CLEAR(delete __VlSymsp, __VlSymsp = NULL);
}

void Vtop::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vtop::eval\n"); );
    Vtop__Syms* __restrict vlSymsp = this->__VlSymsp;  // Setup global symbol table
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
#ifdef VL_DEBUG
    // Debug assertions
    _eval_debug_assertions();
#endif  // VL_DEBUG
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Clock loop\n"););
        _eval(vlSymsp);
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = _change_request(vlSymsp);
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("/projects/hydra/t_arehman/my_cocotb/verification/test_controller/../../sources/controller.sv", 1, "",
                "Verilated model didn't converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

void Vtop::_eval_initial_loop(Vtop__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    _eval_initial(vlSymsp);
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
        _eval_settle(vlSymsp);
        _eval(vlSymsp);
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = _change_request(vlSymsp);
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("/projects/hydra/t_arehman/my_cocotb/verification/test_controller/../../sources/controller.sv", 1, "",
                "Verilated model didn't DC converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

void Vtop::_initial__TOP__1(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_initial__TOP__1\n"); );
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vl_dumpctl_filenamep(true, std::string("dump.vcd"));
    VL_PRINTF_MT("-Info: /projects/hydra/t_arehman/my_cocotb/verification/test_controller/../../sources/controller.sv:66: $dumpvar ignored, as Verilated without --trace\n");
}

VL_INLINE_OPT void Vtop::_combo__TOP__2(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_combo__TOP__2\n"); );
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->controller__DOT__clk = vlTOPp->clk;
    vlTOPp->controller__DOT__rst = vlTOPp->rst;
    vlTOPp->controller__DOT__val_in = vlTOPp->val_in;
    vlTOPp->controller__DOT__rdy_out = vlTOPp->rdy_out;
}

void Vtop::_settle__TOP__3(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_settle__TOP__3\n"); );
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->controller__DOT__clk = vlTOPp->clk;
    vlTOPp->controller__DOT__rst = vlTOPp->rst;
    vlTOPp->controller__DOT__val_in = vlTOPp->val_in;
    vlTOPp->controller__DOT__rdy_out = vlTOPp->rdy_out;
    if ((0U == vlTOPp->controller__DOT__state_reg)) {
        vlTOPp->controller__DOT__state_next = 1U;
    } else {
        if ((1U == vlTOPp->controller__DOT__state_reg)) {
            vlTOPp->controller__DOT__state_next = 2U;
        } else {
            if ((2U == vlTOPp->controller__DOT__state_reg)) {
                vlTOPp->controller__DOT__state_next = 3U;
            } else {
                if ((3U == vlTOPp->controller__DOT__state_reg)) {
                    vlTOPp->controller__DOT__state_next = 4U;
                } else {
                    if ((4U == vlTOPp->controller__DOT__state_reg)) {
                        vlTOPp->controller__DOT__state_next = 1U;
                    }
                }
            }
        }
    }
    if ((0U == vlTOPp->controller__DOT__state_reg)) {
        vlTOPp->controller__DOT__rdy_in = 0U;
    }
    vlTOPp->controller__DOT__rdy_in = (1U == vlTOPp->controller__DOT__state_reg);
    if ((0U == vlTOPp->controller__DOT__state_reg)) {
        vlTOPp->controller__DOT__val_out = 0U;
    }
    vlTOPp->controller__DOT__val_out = ((1U != vlTOPp->controller__DOT__state_reg) 
                                        & (4U == vlTOPp->controller__DOT__state_reg));
    vlTOPp->rdy_in = vlTOPp->controller__DOT__rdy_in;
    vlTOPp->val_out = vlTOPp->controller__DOT__val_out;
}

VL_INLINE_OPT void Vtop::_sequent__TOP__4(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_sequent__TOP__4\n"); );
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->controller__DOT__state_reg = ((IData)(vlTOPp->rst)
                                           ? 0U : vlTOPp->controller__DOT__state_next);
    if ((0U == vlTOPp->controller__DOT__state_reg)) {
        vlTOPp->controller__DOT__state_next = 1U;
    } else {
        if ((1U == vlTOPp->controller__DOT__state_reg)) {
            vlTOPp->controller__DOT__state_next = 2U;
        } else {
            if ((2U == vlTOPp->controller__DOT__state_reg)) {
                vlTOPp->controller__DOT__state_next = 3U;
            } else {
                if ((3U == vlTOPp->controller__DOT__state_reg)) {
                    vlTOPp->controller__DOT__state_next = 4U;
                } else {
                    if ((4U == vlTOPp->controller__DOT__state_reg)) {
                        vlTOPp->controller__DOT__state_next = 1U;
                    }
                }
            }
        }
    }
    if ((0U == vlTOPp->controller__DOT__state_reg)) {
        vlTOPp->controller__DOT__rdy_in = 0U;
    }
    vlTOPp->controller__DOT__rdy_in = (1U == vlTOPp->controller__DOT__state_reg);
    if ((0U == vlTOPp->controller__DOT__state_reg)) {
        vlTOPp->controller__DOT__val_out = 0U;
    }
    vlTOPp->controller__DOT__val_out = ((1U != vlTOPp->controller__DOT__state_reg) 
                                        & (4U == vlTOPp->controller__DOT__state_reg));
    vlTOPp->rdy_in = vlTOPp->controller__DOT__rdy_in;
    vlTOPp->val_out = vlTOPp->controller__DOT__val_out;
}

void Vtop::_eval(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_eval\n"); );
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_combo__TOP__2(vlSymsp);
    if (((IData)(vlTOPp->clk) & (~ (IData)(vlTOPp->__Vclklast__TOP__clk)))) {
        vlTOPp->_sequent__TOP__4(vlSymsp);
    }
    // Final
    vlTOPp->__Vclklast__TOP__clk = vlTOPp->clk;
}

void Vtop::_eval_initial(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_eval_initial\n"); );
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_initial__TOP__1(vlSymsp);
    vlTOPp->__Vclklast__TOP__clk = vlTOPp->clk;
}

void Vtop::final() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::final\n"); );
    // Variables
    Vtop__Syms* __restrict vlSymsp = this->__VlSymsp;
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void Vtop::_eval_settle(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_eval_settle\n"); );
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_settle__TOP__3(vlSymsp);
}

VL_INLINE_OPT QData Vtop::_change_request(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_change_request\n"); );
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    return __req;
}

#ifdef VL_DEBUG
void Vtop::_eval_debug_assertions() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((rst & 0xfeU))) {
        Verilated::overWidthError("rst");}
    if (VL_UNLIKELY((val_in & 0xfeU))) {
        Verilated::overWidthError("val_in");}
    if (VL_UNLIKELY((rdy_out & 0xfeU))) {
        Verilated::overWidthError("rdy_out");}
}
#endif  // VL_DEBUG

void Vtop::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_ctor_var_reset\n"); );
    // Body
    clk = VL_RAND_RESET_I(1);
    rst = VL_RAND_RESET_I(1);
    val_in = VL_RAND_RESET_I(1);
    rdy_out = VL_RAND_RESET_I(1);
    rdy_in = VL_RAND_RESET_I(1);
    val_out = VL_RAND_RESET_I(1);
    controller__DOT__clk = VL_RAND_RESET_I(1);
    controller__DOT__rst = VL_RAND_RESET_I(1);
    controller__DOT__val_in = VL_RAND_RESET_I(1);
    controller__DOT__rdy_out = VL_RAND_RESET_I(1);
    controller__DOT__rdy_in = VL_RAND_RESET_I(1);
    controller__DOT__val_out = VL_RAND_RESET_I(1);
    controller__DOT__state_reg = 0;
    controller__DOT__state_next = 0;
}
