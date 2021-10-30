echo off

g++ -std=c++17 -O2 gen.cpp -o gen
g++ -std=c++17 -O2 G.cpp -o sol

for /l %%i in (1, 1, 10) do (
	./gen > test || break
	./sol < test || break
	echo "Ok %%st"
)
echo on