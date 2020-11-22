# A repo with my practice for algorithms in c++

Run this command in your shell

```shell

mkdir -p bin

```

Add these into your shell config files (.bashrc/.zshrc) file

```bash

compile-and-run() {
        g++ $1 -o bin/$1.out && ./bin/$1.out < input.txt > output.txt
}

com-run() {
        rm -f bin/$1.out && g++ $1 -o bin/$1.out && ./bin/$1.out
}

```
