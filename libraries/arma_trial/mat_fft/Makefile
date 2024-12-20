#Parameters
#OLEVEL: 0 | 1 | 2 | 3

OLEVEL?=0
FFTLIB=fftw3
ARMAINCDIR?=$(HOME)/.local/libs/arma-12.0.1/include
ARMALIBDIR?=$(HOME)/.local/libs/arma-12.0.1/lib

all: run_mat_fft_builtin run_mat_fft_external run_wrapped_mat_fft_builtin run_wrapped_mat_fft_external

mat_fft_builtin_O$(OLEVEL).exe: mat_fft.cpp
	g++ -O$(OLEVEL) -std=c++11 -DARMA_DONT_USE_WRAPPER -DARMA_DONT_USE_FFTW3 -I$(ARMAINCDIR) -o mat_fft_builtin_O$(OLEVEL).o -c mat_fft.cpp
	g++ -O$(OLEVEL) -std=c++11 -o mat_fft_builtin_O$(OLEVEL).exe mat_fft_builtin_O$(OLEVEL).o

run_mat_fft_builtin: mat_fft_builtin_O$(OLEVEL).exe
	echo -n "O$(OLEVEL),"; ./mat_fft_builtin_O$(OLEVEL).exe

mat_fft_external_O$(OLEVEL).exe: mat_fft.cpp
	g++ -O$(OLEVEL) -std=c++11 -DARMA_DONT_USE_WRAPPER -DARMA_USE_FFTW3 -I$(ARMAINCDIR) -o mat_fft_external_O$(OLEVEL).o -c mat_fft.cpp
	g++ -O$(OLEVEL) -std=c++11 -o mat_fft_external_O$(OLEVEL).exe mat_fft_external_O$(OLEVEL).o -l$(FFTLIB)

run_mat_fft_external: mat_fft_external_O$(OLEVEL).exe
	echo -n "O$(OLEVEL),"; ./mat_fft_external_O$(OLEVEL).exe

wrapped_mat_fft_builtin_O$(OLEVEL).exe: mat_fft.cpp
	g++ -O$(OLEVEL) -std=c++11 -DARMA_DONT_USE_FFTW3 -I$(ARMAINCDIR) -o wrapped_mat_fft_builtin_O$(OLEVEL).o -c mat_fft.cpp
	g++ -O$(OLEVEL) -std=c++11 -L$(ARMALIBDIR) -o wrapped_mat_fft_builtin_O$(OLEVEL).exe wrapped_mat_fft_builtin_O$(OLEVEL).o -larmadillo

run_wrapped_mat_fft_builtin: wrapped_mat_fft_builtin_O$(OLEVEL).exe
	echo -n "O$(OLEVEL),"; LD_LIBRARY_PATH=${ARMALIBDIR} ./wrapped_mat_fft_builtin_O$(OLEVEL).exe

wrapped_mat_fft_external_O$(OLEVEL).exe: mat_fft.cpp
	echo "libarmadillo.so doesn't wrap FFTW, so an explicit reference to libfftw3.so is necessary"
	g++ -O$(OLEVEL) -std=c++11 -DARMA_USE_FFTW3 -I$(ARMAINCDIR) -o wrapped_mat_fft_external_O$(OLEVEL).o -c mat_fft.cpp
	g++ -O$(OLEVEL) -std=c++11 -L$(ARMALIBDIR) -o wrapped_mat_fft_external_O$(OLEVEL).exe wrapped_mat_fft_external_O$(OLEVEL).o -larmadillo -lfftw3

run_wrapped_mat_fft_external: wrapped_mat_fft_external_O$(OLEVEL).exe
	echo "libarmadillo.so doesn't wrap FFTW, so an explicit reference to libfftw3.so is necessary"
	echo -n "O$(OLEVEL),"; LD_LIBRARY_PATH=${ARMALIBDIR} ./wrapped_mat_fft_external_O$(OLEVEL).exe

clean:
	rm *.o *.exe