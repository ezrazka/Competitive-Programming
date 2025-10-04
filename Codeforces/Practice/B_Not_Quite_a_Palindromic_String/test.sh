#!/bin/bash

g++-14 -O2 generator.cpp -o generator
g++-14 -O2 solution.cpp -o solution
g++-14 -O2 brute.cpp -o brute

MAX_TESTS=${1:-100}
wa_found=0
for ((i=1; i<=MAX_TESTS; i++)); do
    echo "Test #$i"

    ./generator $i > test.in

    ./solution < test.in > solution.out
    ./brute < test.in > brute.out

    if ! diff -wB solution.out brute.out > /dev/null; then
        echo -e "\033[1;31mWA found on test #$i!\033[0m"
        open -a "Visual Studio Code" test.in
        echo "Your Output:"
        cat solution.out
        echo "Answer:"
        cat brute.out
        wa_found=1
        break
    fi
done

if [ $wa_found -eq 0 ]; then
    echo -e "\033[1;32mAll test cases passed!\033[0m"
fi