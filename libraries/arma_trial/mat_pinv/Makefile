#Parameters
#OLEVEL: 0 | 1 | 2 | 3
#BLASLIB: blas | openblas

OLEVEL?=0
BLASLIB?=blas
ARMAINCDIR=$(HOME)/.local/libs/arma-12.0.1/include
ARMALIBDIR=$(HOME)/.local/libs/arma-12.0.1/lib
ifeq ($(BLASLIB),openblas)
	LAPACKLIB=$(BLASLIB)
else
	LAPACKLIB=lapack
endif

all: run_mat_pinv run_wrapped_mat_pinv

mat_pinv_O$(OLEVEL).exe: mat_pinv.cpp
	g++ -O$(OLEVEL) -std=c++11 -DARMA_DONT_USE_WRAPPER -DARMA_USE_BLAS -DARMA_USE_LAPACK -I$(ARMAINCDIR) -o mat_pinv_O$(OLEVEL).o -c mat_pinv.cpp
	g++ -O$(OLEVEL) -std=c++11 -o mat_pinv_O$(OLEVEL).exe mat_pinv_O$(OLEVEL).o -l$(BLASLIB) -l$(LAPACKLIB)

run_mat_pinv: mat_pinv_O$(OLEVEL).exe
	echo -n "O$(OLEVEL),"; ./mat_pinv_O$(OLEVEL).exe

wrapped_mat_pinv_O$(OLEVEL).exe: mat_pinv.cpp
	g++ -O$(OLEVEL) -std=c++11 -DARMA_USE_BLAS -DARMA_USE_LAPACK -I$(ARMAINCDIR) -o wrapped_mat_pinv_O$(OLEVEL).o -c mat_pinv.cpp
	g++ -O$(OLEVEL) -std=c++11 -L$(ARMALIBDIR) -o wrapped_mat_pinv_O$(OLEVEL).exe wrapped_mat_pinv_O$(OLEVEL).o -larmadillo

run_wrapped_mat_pinv: wrapped_mat_pinv_O$(OLEVEL).exe
	echo -n "O$(OLEVEL),"; LD_LIBRARY_PATH=${ARMALIBDIR} ./wrapped_mat_pinv_O$(OLEVEL).exe

clean:
	rm *.o *.exe