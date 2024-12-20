#Parameters
#OLEVEL: 0 | 1 | 2 | 3

OLEVEL?=0
EIGENINCDIR=$(HOME)/.local/libs/eigen-3.4.0/

all: run_mat_mult

mat_mult_O$(OLEVEL).exe: mat_mult.cpp
	g++ -O$(OLEVEL) -std=c++11 -I$(EIGENINCDIR) -o mat_mult_O$(OLEVEL).o -c mat_mult.cpp
	g++ -O$(OLEVEL) -std=c++11 -I$(EIGENINCDIR) -o mat_mult_O$(OLEVEL).exe mat_mult_O$(OLEVEL).o

run_mat_mult: mat_mult_O$(OLEVEL).exe
	echo -n "O$(OLEVEL),"; ./mat_mult_O$(OLEVEL).exe

clean:
	rm *.o *.exe