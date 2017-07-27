/* Copyright (C) 2017 ETH Zurich, University of Bologna
 * All rights reserved.
 *
 * This code is under development and not yet released to the public.
 * Until it is released, the code is under the copyright of ETH Zurich and
 * the University of Bologna, and may contain confidential and/or unpublished
 * work. Any reuse/redistribution is strictly forbidden without written
 * permission from ETH Zurich.
 *
 * Bug fixes and contributions will eventually be released under the
 * SolderPad open hardware license in the context of the PULP platform
 * (http://www.pulp-platform.org), under the copyright of ETH Zurich and the
 * University of Bologna.
 */

module apb_mock_uart
#(
    parameter APB_ADDR_WIDTH = 12  //APB slaves are 4KB by default
)
(
    input  logic                      CLK,
    input  logic                      RSTN,
    input  logic [APB_ADDR_WIDTH-1:0] PADDR,
    input  logic               [31:0] PWDATA,
    input  logic                      PWRITE,
    input  logic                      PSEL,
    input  logic                      PENABLE,
    output logic               [31:0] PRDATA,
    output logic                      PREADY,
    output logic                      PSLVERR,

    output logic                      INT,       //Interrupt output

    output logic                      OUT1N,     // Output 1
    output logic                      OUT2N,     // Output 2
    output logic                      RTSN,      // RTS output
    output logic                      DTRN,      // DTR output
    input  logic                      CTSN,      // CTS input
    input  logic                      DSRN,      // DSR input
    input  logic                      DCDN,      // DCD input
    input  logic                      RIN,       // RI input
    input  logic                      SIN,       // Receiver input
    output logic                      SOUT       // Transmitter output
);
    // enum { THR = 0, RBR = 0, DLL = 0, IER = 1, DLM = 1, IIR = 2, FCR = 2, LCR = 3, MCR, LSR, MSR, SCR} uart_regs;

    logic [3:0]       register_adr;
    logic [7:0][7:0]  regs_q, regs_n;

    assign register_adr = PADDR[2:0];

    // UART Registers

    // register write logic
    always_comb
    begin
        regs_n = regs_q;

        if (PSEL && PENABLE && PWRITE)
        begin
            regs_n[$unsigned(register_adr)] = PWDATA[7:0];
        end
	regs_n[8'h5] = 32'h60;
    end

    // register read logic
    always_comb
    begin
        PRDATA = 'b0;

        if (PSEL && PENABLE && !PWRITE)
        begin
            PRDATA = {24'b0, regs_q[$unsigned(register_adr)] };
        end
    end

    // synchronouse part
    always_ff @(posedge CLK, negedge RSTN)
    begin
        if(~RSTN)
        begin
            regs_q <= '{8{8'b0}};
        end
        else
        begin
            regs_q <= regs_n;
            if (PSEL && PENABLE && PWRITE)
            begin
                if ($unsigned(register_adr) == 0)
                begin
                    $write("%C", PWDATA[7:0]);
                end
            end
        end
    end

    // APB logic: we are always ready to capture the data into our regs
    // not supporting transfare failure
    assign PREADY  = 1'b1;
    assign PSLVERR = 1'b0;
endmodule
