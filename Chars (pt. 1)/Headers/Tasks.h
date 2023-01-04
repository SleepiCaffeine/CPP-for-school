#include <algorithm>
#include <fstream>
#include <vector>
#include <numeric>
#include <iostream>
#include <iomanip>

// Writing function, just for comfort
void write_text(std::string txt, std::string custom_text) {
    std::ofstream OUT("OUT/" + txt + ".txt");
    OUT << custom_text;
    OUT.close();
}

// 1st task
void newline_freq(std::string IN, std::string OUT) {
    std::ifstream input("IN/" + IN + ".txt");
    int count = 0;
    char ch;
    while (input.get(ch))                  // 'Gets' raw characters using an "unformatted input operation" aka reads "\n" as "\n", not "\" and "n"
        count += (ch == '\n')? 1 : 0;      // Ternary operator, that will increment 'count' if there has been a newline character detected

    write_text(OUT, std::to_string(count));
}

// Lithuanian letter bool = (188 < ASCII && ASCII < 191 || (197 < ASCII && ASCII < 200) || (206 < ASCII && ASCII < 217));

// 2nd task
void captical_count(std::string IN, std::string OUT) {
    std::ifstream input("IN/" + IN + ".txt");

    int count = 0;
    char ch;
    while (input.get(ch))
        count += (64 < int(ch) && int(ch) < 91)? 1 : 0;
    
    input.close();
    write_text(OUT, std::to_string(count));
    
}

// 3rd task
void space_removal(std::string IN, std::string OUT) {
    std::ifstream input("IN/" + IN + ".txt");
    std::ofstream output("OUT/" + OUT + ".txt");

    int count = 0;
    char ch;
    char next;
    while (input.get(ch)) {
        if (ch == ' ') {
            switch(input.peek()) {
            case '!':
            case '?':
            case ',':
            case '.':
            case ';':
            case ':':
                ch = input.peek();
                output << ch;
                input.get(ch);
                ch = ' ';
            };
        }
        output << ch;
    }
    input.close();
    output.close();
}

// 4th task
void class_heights(std::string IN, std::string OUT) {
    std::ifstream input("IN/" + IN + ".txt");
    std::ofstream output("OUT/" + OUT + ".txt");
    
    short n;
    input >> n;  // Removing initial n

    struct kid {
        std::vector <short> heights;
        short count = 0;
    };

    struct kid *m, k;
    m = &k;
    struct kid *f, k2;
    f = &k2;

    char ch;
    while (input) {
        input >> n >> ch; // Reading height and gender
        switch (ch) {
            case 'm':
                m->count++;
                m->heights.push_back(n);
                break;
            case 'f':
                f->count++;
                f->heights.push_back(n);
                break;
        }
    }

    std::sort(m->heights.begin(), m->heights.end(),std::greater<short>());
    std::sort(f->heights.begin(), f->heights.end(),std::greater<short>());

    output << "Boys in the class: "<< m->count << std::endl <<
              "Average boy height: "<< std::fixed << std::setprecision(2) << std::accumulate(m->heights.begin(), m->heights.end(), 0)*1.0 / m->count << std::endl << 
              "Tallest boy: "<< m->heights.at(0) << std::endl << 
              "========================\n" <<
              "Girls in the class: "<< f->count << std::endl <<
              "Average girl height: "<< std::fixed << std::setprecision(2) << std::accumulate(f->heights.begin(), f->heights.end(), 0)*1.0 / f->count << std::endl <<
              "Tallest girl: "<< f->heights.at(0) << std::endl;
}


