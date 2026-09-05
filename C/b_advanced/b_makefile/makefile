#   A simple makefile which allows you to build a project very easy. Usually on any UNIX system this
#   makefile runs without flaws, except for special commands.
#
#   left side:      target(s)
#   right side:     command(s) for the given target(s)
#
#   Every target may contain dependencies.
#
#   the top target will be used automatically
#   by calling 'make'
#
#   attention:
#   - Windows (with Mingw) may also be able to use that file (without a file extention),
#     but there's no guarantee to work with.
#
#   NOTE:   A makefile MUST contain tabs, not spaces. Otherwise
#           you're unable to build your application(s).
#
#   How to display spaces / tabs in Visual Studio Code:
#   1) go to manage (gear symbol left corner)
#   2) settings
#   3) whitespace => render whitespace => all
#
#   4) search bar: enter tab => first entry
#   5) go to "Editor: Detect Indentation" => (first entry)
#   6) go to "Editor: insert spaces => uncheck the check box
#      "Insert Spaces when pressing Tab"
#
#   any other editor could use: view => render whitespace (or similar)
#
#   to suppress the command output on the console, use: @<command>

#target     dependency for target 'all'

###############
#  example 1
###############
# direct compile
###############

all:
		@gcc -Wall src/main.c src/math_functions.c -Iheader -o application.run -lm

clean:
		@rm -f application.run


###############
#  example 2
###############
# using sub targes
###############

all:	main.o math_functions.o
		@gcc -Wall main.o math_functions.o -o application.run -lm
		@rm *.o

main.o:	src/main.c
		@gcc -c src/main.c -Iheader

math_functions.o:	src/math_functions.c
		@gcc -c src/math_functions.c -Iheader

clean:
		@rm -f application.run


###############
#  example 3
###############
# using variables with direct access
###############

application = application.run
sources = src/main.c src/math_functions.c
compiler = gcc
flags = -Wall -g3
linker = -Iheader -lm -o

all:
		@$(compiler) $(flags) $(sources) $(linker) $(application)

clean:
		@rm -f $(application)

###############
#  example 4
###############
# using variables with sub targets
###############

application = application.run
objective_a = main.o
objective_b = math_functions.o
source_a = src/main.c
source_b = src/math_functions.c
compiler = gcc
flags = -Wall -g3
precompile = -c
output = -o
header = -Iheader
linker = -lm

all:	$(objective_a) $(objective_b)
		@$(compiler) $(flags) $(objective_a) $(objective_b) $(output) $(application) $(linker)
		@rm $(objective_a) $(objective_b)

$(objective_a):	$(source_a)
		@$(compiler) $(precompile) $(source_a) $(header)

$(objective_b): $(source_b)
		@$(compiler) $(precompile) $(source_b) $(header)

clean:
		@rm -f $(application)