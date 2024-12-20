#Parameters
#OLEVEL: 0 | 1 | 2 | 3

OLEVEL?=0
FFTLIB=fftw3
EIGENINCDIR=$(HOME)/.local/libs/eigen-3.4.0/

all: run_mat_fft

mat_fft_builtin_O$(OLEVEL).exe: mat_fft.cpp
	g++ -O$(OLEVEL) -std=c++11 -I$(EIGENINCDIR) -o mat_fft_builtin_O$(OLEVEL).o -c mat_fft.cpp
	g++ -O$(OLEVEL) -std=c++11 -I$(EIGENINCDIR) -o mat_fft_builtin_O$(OLEVEL).exe mat_fft_builtin_O$(OLEVEL).o

run_mat_fft_builtin: mat_fft_builtin_O$(OLEVEL).exe
	echo -n "O$(OLEVEL),"; ./mat_fft_builtin_O$(OLEVEL).exe

mat_fft_external_O$(OLEVEL).exe: mat_fft.cpp
	g++ -O$(OLEVEL) -std=c++11 -DEIGEN_FFTW_DEFAULT -I$(EIGENINCDIR) -o mat_fft_external_O$(OLEVEL).o -c mat_fft.cpp
	g++ -O$(OLEVEL) -std=c++11 -I$(EIGENINCDIR) -o mat_fft_external_O$(OLEVEL).exe mat_fft_external_O$(OLEVEL).o -l$(FFTLIB)

run_mat_fft_external: mat_fft_external_O$(OLEVEL).exe
	echo -n "O$(OLEVEL),"; ./mat_fft_external_O$(OLEVEL).exe

clean:
	rm *.o *.exe