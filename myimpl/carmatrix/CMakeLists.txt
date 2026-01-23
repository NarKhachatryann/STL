# 1. Սահմանում ենք CMake-ի նվազագույն պահանջվող տարբերակը
cmake_minimum_required(VERSION 3.10)

# 2. Սահմանում ենք Ծրագրի Անունը
project(Carmatrix CXX) # CXX-ը ցույց է տալիս, որ սա C++ նախագիծ է

# 3. Ավելացնում ենք Գործարկվող Թիրախը (Executable Target)
# a.out անունով ֆայլը կստեղծվի main.cpp ելակետային կոդից
add_executable(a.out main.cpp matrix.cpp car.cpp)