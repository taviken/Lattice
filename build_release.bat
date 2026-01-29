call setup.bat
cd build
cmake  -DCMAKE_BUILD_TYPE=Release ../source 


cmake --build . --config Release
