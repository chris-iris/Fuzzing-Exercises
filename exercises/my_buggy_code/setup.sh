#!/usr/bin/env bash

# Gather examples
if [ ! -d "./input_seeds" ]; then
    mkdir input_seeds
fi 

cd input_seeds

wget https://github.com/mozilla/pdf.js-sample-files/raw/master/helloworld.pdf
wget http://www.africau.edu/images/default/sample.pdf
wget https://www.melbpc.org.au/wp-content/uploads/2017/10/small-example-pdf-file.pdf

cd ..

wget https://dl.xpdfreader.com/old/xpdf-3.02.tar.gz
tar -xvzf xpdf-3.02.tar.gz
rm xpdf-3.02.tar.gz

mkdir build instrumented_build fuzz_dir sut_out

echo "Gathering completed. Remember to set --prefix=$(pwd)/build option in \".configure\" inside Xpdf"
