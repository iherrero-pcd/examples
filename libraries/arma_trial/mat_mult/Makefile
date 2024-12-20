#Parameters
#OLEVEL: 0 | 1 | 2 | 3
#BLASLIB: blas | openblas

OLEVEL?=0
BLASLIB?=blas
ARMAINCDIR=$(HOME)/.local/libs/arma-12.0.1/include
ARMALIBDIR=$(HOME)/.local/libs/arma-12.0.1/lib

all: run_mat_mult_builtin run_mat_mult_external run_wrapped_mat_mult_builtin run_wrapped_mat_mult_external

mat_mult_builtin_O$(OLEVEL).exe: mat_mult.cpp
	g++ -O$(OLEVEL) -std=c++11 -DARMA_DONT_USE_WRAPPER -DARMA_DONT_USE_BLAS -I$(ARMAINCDIR) -o mat_mult_builtin_O$(OLEVEL).o -c mat_mult.cpp
	g++ -O$(OLEVEL) -std=c++11 -o mat_mult_builtin_O$(OLEVEL).exe mat_mult_builtin_O$(OLEVEL).o

run_mat_mult_builtin: mat_mult_builtin_O$(OLEVEL).exe
	echo -n "O$(OLEVEL),"; ./mat_mult_builtin_O$(OLEVEL).exe

mat_mult_external_O$(OLEVEL).exe: mat_mult.cpp
	g++ -O$(OLEVEL) -std=c++11 -DARMA_DONT_USE_WRAPPER -DARMA_USE_BLAS -I$(ARMAINCDIR) -o mat_mult_external_O$(OLEVEL).o -c mat_mult.cpp
	g++ -O$(OLEVEL) -std=c++11 -o mat_mult_external_O$(OLEVEL).exe mat_mult_external_O$(OLEVEL).o -l$(BLASLIB)

run_mat_mult_external: mat_mult_external_O$(OLEVEL).exe
	echo -n "O$(OLEVEL),"; ./mat_mult_external_O$(OLEVEL).exe

wrapped_mat_mult_builtin_O$(OLEVEL).exe: mat_mult.cpp
	g++ -O$(OLEVEL) -std=c++11 -DARMA_DONT_USE_BLAS -I$(ARMAINCDIR) -o wrapped_mat_mult_builtin_O$(OLEVEL).o -c mat_mult.cpp
	g++ -O$(OLEVEL) -std=c++11 -L$(ARMALIBDIR) -o wrapped_mat_mult_builtin_O$(OLEVEL).exe wrapped_mat_mult_builtin_O$(OLEVEL).o -larmadillo

run_wrapped_mat_mult_builtin: wrapped_mat_mult_builtin_O$(OLEVEL).exe
	echo -n "O$(OLEVEL),"; LD_LIBRARY_PATH=${ARMALIBDIR} ./wrapped_mat_mult_builtin_O$(OLEVEL).exe

wrapped_mat_mult_external_O$(OLEVEL).exe: mat_mult.cpp
	g++ -O$(OLEVEL) -std=c++11 -DARMA_USE_BLAS -I$(ARMAINCDIR) -o wrapped_mat_mult_external_O$(OLEVEL).o -c mat_mult.cpp
	g++ -O$(OLEVEL) -std=c++11 -L$(ARMALIBDIR) -o wrapped_mat_mult_external_O$(OLEVEL).exe wrapped_mat_mult_external_O$(OLEVEL).o -larmadillo

run_wrapped_mat_mult_external: wrapped_mat_mult_external_O$(OLEVEL).exe
	echo -n "O$(OLEVEL),"; LD_LIBRARY_PATH=${ARMALIBDIR} ./wrapped_mat_mult_external_O$(OLEVEL).exe

clean:
	rm *.o *.exe