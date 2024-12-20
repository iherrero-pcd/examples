#Parameters
#OLEVEL: 0 | 1 | 2 | 3

OLEVEL?=0
EIGENINCDIR=$(HOME)/.local/libs/eigen-3.4.0/

all: run_mat_pinv

mat_pinv_O$(OLEVEL).exe: mat_pinv.cpp
	g++ -O$(OLEVEL) -std=c++11 -I$(EIGENINCDIR) -o mat_pinv_O$(OLEVEL).o -c mat_pinv.cpp
	g++ -O$(OLEVEL) -std=c++11 -I$(EIGENINCDIR) -o mat_pinv_O$(OLEVEL).exe mat_pinv_O$(OLEVEL).o

run_mat_pinv: mat_pinv_O$(OLEVEL).exe
	echo -n "O$(OLEVEL),"; ./mat_pinv_O$(OLEVEL).exe

clean:
	rm *.o *.exe