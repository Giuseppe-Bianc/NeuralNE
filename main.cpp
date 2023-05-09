#include <iostream>
#include <chrono>
#include <vector>
#include "Lexer.h"

int main() {

    std::string input = "1 + 2 * (3 - 4) + 3333333333333 + 222222222222 / 22222222";
    Lexer lexer(input);
    auto start = std::chrono::high_resolution_clock::now();
    std::vector<Token> tokens = lexer.Tokenize();
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();

    for (const Token& token : tokens) {
        std::cout << token.toString() << std::endl;
    }
    std::cout << "Tempo impiegato: " << duration << " ns" << std::endl << "premi un tasto  per continuare";
	std::cin.get();

	return 0;
}