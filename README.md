A repo with my practice for algorithms in c++

Add these into your rc file


compile-and-run() {
        g++ $1 -o bin/$1.out && ./bin/$1.out < input.txt > output.txt
}

com-run() {
        rm -f bin/$1.out && g++ $1 -o bin/$1.out && ./bin/$1.out
}

