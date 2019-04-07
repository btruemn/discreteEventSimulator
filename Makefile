make:
	clang++ -std=c++17 main.cpp Bank.cpp Supermarket.cpp Store.cpp -o simulator

test:
	chmod +x test.sh
	./test.sh > output.txt
