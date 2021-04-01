COMPILATION INSTRUCTIONS For MULTITHREADING QUESTIONS:
------------------------------------------------------


Linux
-----
g++ -std=c++11 -pthread *.cpp -o _main

on Linux you will not link libpthread unless you ask.

Windows:
--------
g++ -std=c++11 *.cpp -o _main

Windows ports of GCC link libpthread by default.