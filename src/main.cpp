#include <cstring>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include "lexer/lexer.h"

std::string readFileContents(const std::string& filename);

int main(int argc, char* argv[]) {
    // Disable output buffering
    std::cout << std::unitbuf;
    std::cerr << std::unitbuf;

    const std::vector<std::string> args(argv, argv + argc);

    if (argc < 3) {
        std::cerr << "Usage: ./your_program tokenize <filename>" << std::endl;
        return 1;
    }

    const std::string& command = args[1];

    if (command == "tokenize") {
        const std::string file_contents = readFileContents(args[2]);
        std::cout << tokenize(file_contents) << std::endl;
    } else {
        std::cerr << "Unknown command: " << command << std::endl;
        return 1;
    }

    return 0;
}

std::string readFileContents(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error reading file: " << filename << std::endl;
        std::exit(1);
    }

    std::stringstream buffer;
    buffer << file.rdbuf();
    file.close();

    return buffer.str();
}

void report(int line, const std::string& where, const std::string& message) {
    std::cerr << "[line " + std::to_string(line) + "] Error" + where + ": " + message;
}

void error(int line, const std::string& message) { report(line, "", message); }
