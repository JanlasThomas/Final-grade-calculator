cmake CMakeLists.txt
cmake --install .
cmake --build .
copy src\students.txt Debug\students.txt
cd Debug\
Task1.exe
pause