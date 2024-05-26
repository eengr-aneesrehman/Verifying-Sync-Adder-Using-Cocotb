module adder #(
  parameter integer DATA_WIDTH = 4
) (
  input logic clk,rst,
  input logic val_in,rdy_out,
  input  logic unsigned [DATA_WIDTH-1:0] A,
  input  logic unsigned [DATA_WIDTH-1:0] B,
  output logic rdy_in,val_out,
  output logic unsigned [DATA_WIDTH-1:0] S,
  output logic C
);
// Signals
reg [DATA_WIDTH-1:0] a_reg,b_reg;
reg [DATA_WIDTH:0] x_reg;
logic [DATA_WIDTH:0] X;

// Instantiation
controller cntr(
  .clk(clk),
  .rst(rst),
  .val_in(val_in),
  .rdy_out(rdy_out),
  .rdy_in(rdy_in),
  .val_out(val_out)
);

//Assign Statements
assign X = a_reg + b_reg;
//Output Logic
assign S = x_reg[DATA_WIDTH-1:0];
assign C = x_reg[DATA_WIDTH];

//Always Statements
always@(posedge clk)
begin
  if(rst)
  begin
    a_reg <= 0;
    b_reg <= 0;
  end
  else
  begin
    if(val_in && rdy_in)
    begin
      a_reg <= A;
      b_reg <= B;
    end
  end
  x_reg <= X;
end

// Dump waves
initial 
begin
  $dumpfile("dump.vcd");   // Specifies the name of the dump file
  $dumpvars(1, adder);     // Dumps the variables of the adder module
end

endmodule