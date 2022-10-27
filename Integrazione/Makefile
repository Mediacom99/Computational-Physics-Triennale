default_target: all
.PHONY: all ex1 ex2 ex3

CXXFLAGS = -lm -std=c99 -Wall -I./

all: ex1 ex2

ex1:
	@gcc ex1.c ${CXXFLAGS}  -o ex1.unx

ex2:
	@gcc ex2.c  ${CXXFLAGS} -o ex2.unx

ex3:
	@gcc ex3.c ${CXXFLAGS}  -o ex3.unx
