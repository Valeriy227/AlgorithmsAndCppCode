echo off

g++ -std=c++17 -O2 gen.cpp -o gen
g++ -std=c++17 -O2 sol.cpp -o sol
g++ -std=c++17 -O2 ok.cpp -o ok

for /l %%i in (1, 1, 100) do (
    echo %%i > seed
	gen < seed > test || break
	sol < test > my_ans || break
	ok < test > corr_ans || break

	FC corr_ans my_ans > log

    echo "OK %%i"
    if errorlevel 1 (
        exit
    )
)
echo on