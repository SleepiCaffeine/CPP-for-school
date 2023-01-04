#include <fstream>
#include <iostream>

// Writing function, just for comfort
void write_text(std::string txt, std::string custom_text) {
    std::ofstream OUT("OUT/" + txt + ".txt");
    OUT << custom_text;
    OUT.close();
}

// 1st task
void newline_freq(std::string IN, std::string OUT) {
    std::ifstream input("IN/" + IN + ".txt");

    int count = 0; char ch;
    while (input.get(ch))                  // 'Gets' raw characters using an "unformatted input operation" aka reads "\n" as "\n", not "\" and "n"
        count += (ch == '\n')? 1 : 0;      // Ternary operator, that will increment 'count' if there has been a newline character detected

    write_text(OUT, std::to_string(count));
}


// 2nd task
void captical_count(std::string IN, std::string OUT) {
    std::ifstream input("IN/" + IN + ".txt");

    int count = 0; char ch;
    while (input.get(ch))
        count += (64 < int(ch) && int(ch) < 91)? 1 : 0;
    
    input.close();
    write_text(OUT, std::to_string(count));
}