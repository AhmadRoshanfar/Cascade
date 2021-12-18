#
# To use this example, the cascade library must be built with
#
#   env VERILOG=1 make
#
RM := /bin/rm -rf

VCS     := $(VCS_HOME)/bin/vcs
CXX		:= g++
CFLAGS  := -ggdb3 -Wall -std=gnu++0x -I../../include
VFLAGS  := -sverilog +vpi -P ../../verilog/vpi.tab -full64

LIBHPPFILES := $(wildcard ../../include/*/*.hpp) 

LIBDESCORE := ../../objs/descore/libdescore.a
LIBCASCADE := ../../objs/cascade_verilog/libcascade_verilog.a

simv: $(LIBDESCORE) $(LIBCASCADE) Gcd.o tb_gcd.sv CGCD.sv 
	$(VCS) $(VFLAGS) Gcd.o CGCD.sv tb_gcd.sv $(LIBCASCADE) $(LIBDESCORE) -lz -ltermcap 

Adder.o: Gcd.cpp $(LIBHPPFILES)
	$(CXX) $(CFLAGS) -D_VERILOG -I$(VCS_HOME)/include -c -o Gcd.o Gcd.cpp

$(LIBDESCORE):
	cd ../../src/descore; make

$(LIBCASCADE):
	cd ../../src/cascade; make verilog

clean:
	$(RM) simv
	$(RM) Gcd.o
	$(RM) csrc
	$(RM) simv.daidir
	$(RM) ucli.key
