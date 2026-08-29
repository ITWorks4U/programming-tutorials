#	makefile for UNIX, e. g. Linux, macOS, ... only

#	--------------
#	settings
#	--------------
compiler = gcc
c_flags = -Wall -o
header_ref = -Iheader
executable = header_example.run
source = src/main.c src/math_functions.c

all:
	@$(compiler) $(c_flags) $(executable) $(source) $(header_ref)

clean:
	@rm -f $(executable)