wget https://sourceforge.net/projects/arma/files/armadillo-12.0.1.tar.xz
tar -xx -f armadillo-12.0.1.tar.xz
cd armadillo-12.0.1
cmake . -DCMAKE_INSTALL_PREFIX:PATH=${HOME}/.local/libs/arma-12.0.1
rm -rf ${HOME}/.local/libs/arma-12.0.1
mkdir -p ${HOME}/.local/libs/arma-12.0.1
make install