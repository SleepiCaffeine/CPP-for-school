#include <bits/stdc++.h>


// Text Reading Functions
// This funcion reads text dynamically, so no need for an initial size 'n' value
std::vector <float> f_read(std::string txt, bool read_n = false) {
    std::vector <float> vec; float n;
    std::ifstream IN(“IN/“ + txt “.txt”);
  
    while (IN >> n)    // Reads text until the end
        vec.push_back(n);

    if (read_n)
        vec.pop_front();
    
    IN.close();
    return vec;
}

std::vector <int> i_read(std::string txt, bool read_n = false) {
    std::vector <int> vec; int n;
    std::ifstream IN(“IN/“ + txt “.txt”);
  
    while (IN >> n)
        vec.push_back(n);

    if (read_n)
        vec.pop_front();
    
    IN.close();
    return vec;
}


// Printing Functions
void print_float(std::string txt, std::vector <float> vec) {
    std::ofstream OUT("OUT/" + txt + ".txt");
    for (auto& i : vec)    // "Range-based" cycles exist since C++11, so we can use them
        OUT << std::setprecision(2) << i << "\n";

    OUT.close();
}

void print_int(std::string txt, std::vector <int> vec) {
    std::ofstream OUT("OUT/" + txt + ".txt");
    for (auto& i : vec)
        OUT << std::setprecision(2) << i << "\n";

    OUT.close();
}   