wget https://gitlab.com/libeigen/eigen/-/archive/3.4.0/eigen-3.4.0.tar.gz
tar -xz -f eigen-3.4.0.tar.gz
cd eigen-3.4.0
rm -rf ${HOME}/.local/libs/eigen-3.4.0/
mkdir -p ${HOME}/.local/libs/eigen-3.4.0/
cp -R Eigen/ ${HOME}/.local/libs/eigen-3.4.0/
mkdir -p ${HOME}/.local/libs/eigen-3.4.0/unsupported/
cp -R unsupported/Eigen/ ${HOME}/.local/libs/eigen-3.4.0/unsupported/