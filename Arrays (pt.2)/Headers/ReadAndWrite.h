#include <bits/stdc++.h>


// Text Reading Function. Returns <float> Vector
// Dynamically reads text, if there is an intial 'n' value, set the read_n to true
std::vector <float> f_read(std::string txt, bool read_n = false) {
    std::vector <float> vec; float n;
    std::ifstream IN("IN/" + txt + ".txt");
  
    while (IN >> n) 
        vec.push_back(n);

    if (read_n)
        vec.erase(vec.begin());
    
    IN.close();
    return vec;
}

// Text Reading Function. Returns <int> Vector
// Dynamically reads text if there is an intial 'n' value, set the read_n to true
std::vector <int> i_read(std::string txt, bool read_n = false) {
    std::vector <int> vec; int n;
    std::ifstream IN("IN/" + txt + ".txt");
  
    while (IN >> n)
        vec.push_back(n);

    if (read_n)
        vec.erase(vec.begin());
    
    IN.close();
    return vec;
}

// Writing function to output <float> vectors
// Allows for custom outputs as well
void f_write(std::string txt, std::vector <float> vec) {
    std::ofstream OUT("OUT/" + txt + ".txt");

    for (auto& i : vec)    // "Range-based" cycles exist since C++11, so we can use them
        OUT << std::setprecision(2) << i << "\n";

    OUT.close();
}

// Writing function to output <int> vectors
// Allows for custom outputs as well
void i_write(std::string txt, std::vector <int> vec) {
    std::ofstream OUT("OUT/" + txt + ".txt");

    for (auto& i : vec)
        OUT << std::setprecision(2) << i << "\n";

    OUT.close();
}


void write_text(std::string txt, std::string custom_text) {
    std::ofstream OUT("OUT/" + txt + ".txt");
    OUT << custom_text;
    OUT.close();
}
