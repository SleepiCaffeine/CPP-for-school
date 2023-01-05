#include <algorithm>
#include <fstream>
#include <vector>
#include <numeric>
#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <map>

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
    input.close();
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

    kid* m = new kid;
    kid* f = new kid;

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
    input.close();

    std::sort(m->heights.begin(), m->heights.end(),std::greater<short>());
    std::sort(f->heights.begin(), f->heights.end(),std::greater<short>());

    output << "Boys in the class: "<< m->count << std::endl <<
              "Average boy height: "<< std::fixed << std::setprecision(2) << std::accumulate(m->heights.begin(), m->heights.end(), 0)*1.0 / m->count << std::endl << 
              "Tallest boy: "<< m->heights.at(0) << std::endl << 
              "========================\n" <<
              "Girls in the class: "<< f->count << std::endl <<
              "Average girl height: "<< std::fixed << std::setprecision(2) << std::accumulate(f->heights.begin(), f->heights.end(), 0)*1.0 / f->count << std::endl <<
              "Tallest girl: "<< f->heights.at(0) << std::endl;
    output.close();
    delete m;
    delete f;
}

// 5th task
void ROOMBA_YAY(std::string IN, std::string OUT) {
    struct Points {                                
        int x = 0;
        int y = 0;   
    } *tmp = new Points;                          // Temporary Pointer Struct To Read Obstacle Coordinates; It Will Be Deleted Later

    struct Commands {
        char ch;
        int n;
    } *tmp2 = new Commands;                       // Temporary Pointer Struct To Read Commands; It Will Be Deleted Later

    std::ifstream input("IN/" + IN + ".txt");
    int* n = new int; input >> *n;                // Discarding n

    std::vector <Points> point;                   // Vector To Store Obstacle coordinates from temp Struct
    while (point.size() <= *n) {
        input >> tmp->x >> tmp->y;
        point.push_back(*tmp);
    }
    delete n;
    delete tmp;
    
    std::vector <Commands> command;               // Vector To Store Commands form temp Struct
    while (input >> tmp2->ch >> tmp2->n)
        command.push_back(*tmp2);         
    delete tmp2;
    input.close();


    Points* roomba = new Points;                 // Struct to store the coordinates of the roomba
    bool hitWall = false;                        // Bool To Check if Collision will Occur Next Move
    short count = 0;                             // Amount of Spaces Roomba Should Move
    for (auto i: command) {
        switch (i.ch) {
            case 'F':
                while (count < i.n) {
                    for (auto j: point)
                        hitWall = ((roomba->y)+1 == j.y && roomba->x == j.x) || hitWall;                        
                    roomba->y += (!hitWall)? 1 : 0;
                    count++;
                }
                hitWall = false;
                count = 0;
                break;

            case 'B':
                while (count < i.n) {
                    for (auto j: point)
                        hitWall = ((roomba->y)-1 == j.y && roomba->x == j.x) || hitWall;                        
                    roomba->y -= (!hitWall)? 1 : 0;
                    count++;
                }
                hitWall = false;
                count = 0;
                break;

            case 'R':
                while (count < i.n) {
                    for (auto j: point)
                        hitWall = (roomba->y == j.y && (roomba->x)+1) == j.x || hitWall;                        
                    roomba->x += (!hitWall)? 1 : 0;
                    count++;
                }
                hitWall = false;
                count = 0;
                break;

            case 'L':
                while (count < i.n) {
                    for (auto j: point)
                        hitWall = (roomba->y == j.y && (roomba->x)-1 == j.x) || hitWall;                        
                    roomba->x -= (!hitWall)? 1 : 0;
                    count++;
                }
                hitWall = false;
                count = 0;
                break;

            default:
                throw std::invalid_argument("Invalid Command Type\n");

        }
    }
    /*
    How This Switch Works
    1. It Goes Through every command pair using the for (auto i: command) loop
    2. Starts a switch statement, using the i.ch value, aka the command type
    3. Creates 4 cases, for the 4 individual Command types
    4. For Each Case it:
        4.1. Starts a for loop, which will execute the amount of times the command specifies (i.n), using a variable count as an incrementable unit
        4.2. Starts Another range based loop, that will check every obstacle coordinate
        4.3. For each unique case, it checks if the next move will be in an obstacle
        4.4. If so - it will turn the hitWall boolean into true, and will have it permanantly set as true for the duration of the loop
        4.5. If the hitWall Boolean is false, it will increment or decrement the specific coordinate up by one
        4.6. In The end of the loop, it will reset hitWall to False and count back to 0, to start a new case
    */
    write_text(OUT, "(" + std::to_string(roomba->x) + "; " + std::to_string(roomba->y) + ")");
    delete roomba;                             
}

void char_freq(std::string IN, std::string OUT) {
    std::ifstream input("IN/" + IN + ".txt");
    char ch;
    std::map <char, int> freq_table;

    while (input) {
        input >> ch;
        ch = toupper(ch);
        if (isalpha(ch)) {
            if (freq_table.find(ch) != freq_table.end())
                freq_table[ch]++;
            else
                freq_table[ch] = 1;
        }
    }
    input.close();
    std::ofstream output("OUT/" + OUT + ".txt");
    std::map <char, int>::iterator it;

    for (it = freq_table.begin(); it != freq_table.end(); it++)
        output << it->first << ": " << it->second << "\n";
    output.close(); 
}

void calculator(std::string IN, std::string OUT) {
    std::ifstream input("IN/" + IN + ".txt");
    int num1, num2;
    char ch;
    input >> num1 >> ch >> num2;
    switch (ch) {
        case '+':
            num1+=num2;
            break;
        case '-':
            num1-=num2;
            break;
        case '*':
            num1*=num2;
            break;
        case '/': {
            int tmp = num1;
            num1/=num2;
            tmp-=num2*num1;
            if (tmp > 0) { 
                write_text(OUT, std::to_string(num1) + " (" + std::to_string(tmp) + " mod.)");
                return;
            }
        } break;

        default:
            throw std::invalid_argument("Invalid operation");
    }

     write_text(OUT, std::to_string(num1));
}

void jam_thieves(std::string IN, std::string OUT) {
    std::ifstream input("IN/" + IN + ".txt");
    short n; input >> n;
    short* m = new short; input >> *m; delete m; // Removing m
    char ch;
    while (input >> ch) {
        switch (ch) {
            case 'L':
                if (n-2 <= 0) {
                    write_text(OUT, std::to_string(n) + " The Little boy");
                    return;
                }
                n -= 2;
                break;
            case 'C':
                if (n-5 <= 0) {
                    write_text(OUT, std::to_string(n) + " Carlsen");
                    return;
                }
                n -= 5;
                break;
            case 'F':
                if (n-3 <= 0) {
                    write_text(OUT, std::to_string(n) + " Frekenbok");
                    return;
                }
                n -= 3;
                break;
            default:
                throw std::invalid_argument("Invalid char");
        }
    }
    input.close();
    write_text(OUT, std::to_string(n) + " left");
}


