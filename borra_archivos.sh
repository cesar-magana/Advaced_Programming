#! /bin/bash
find . -name "build" -exec rm -rf {} \;
find . -name ".DS_Store" -exec rm -rf {} \;
rm -Rf *.aux;
rm -rf *.log;
rm -rf *.out;
rm -rf *.synctex.gz; 
