module controller(
  input logic clk,rst,
  input logic val_in,rdy_out,
  output logic rdy_in,val_out
);

//State Defination
typedef enum {idle,s0,s1,s2,s3} state_name;
state_name state_reg, state_next;

//Present State Logic
always_ff @(posedge clk)
begin
  if(rst)
    state_reg <= idle;
  else
    state_reg <= state_next;
end

//Next State Logic
always_comb 
begin
  unique case (state_reg)
  idle:
    state_next = s0;
  s0:
    state_next = s1;
  s1:
    state_next = s2;
  s2:
    state_next = s3;
  s3:
    state_next = s0;
  endcase
end

//Output Logic
always_comb
begin
    if (state_reg == idle)
    begin
        rdy_in  = 1'b0;
        val_out = 1'b0;
    end
    if(state_reg == s0)
    begin
        rdy_in  = 1'b1;
        val_out = 1'b0;
    end
    else if(state_reg == s3)
    begin
        rdy_in  = 1'b0;
        val_out = 1'b1;
    end
    else
    begin
        rdy_in  = 1'b0;
        val_out = 1'b0;
    end
end

// Dump waves
initial 
begin
  $dumpfile("dump.vcd");   // Specifies the name of the dump file
  $dumpvars(1, controller);     // Dumps the variables of the adder module
end

endmodule