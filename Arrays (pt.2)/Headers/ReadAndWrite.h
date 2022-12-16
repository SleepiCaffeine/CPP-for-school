#include <bits/stdc++.h>


// Text Reading Functions
// This funcion reads text dynamically, so no need for an initial size 'n' value
std::vector <float> __f_init__(std::string txt) {
    float n; std::vector <float> vec;

    std::ifstream IN("IN/" + txt + ".txt");
    while (IN >> n)     // Reads text file until the end
        vec.push_back(n);   
    
    IN.close();
    return vec;
}

std::vector <int> __i_init__(std::string txt) {
    int n; std::vector <int> vec;

    std::ifstream IN("IN/" + txt + "_in.txt");
    while (IN >> n)
        vec.push_back(n);   
    
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