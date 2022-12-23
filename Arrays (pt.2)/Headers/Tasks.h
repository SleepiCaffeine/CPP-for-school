#include <bits/stdc++.h>
#include "ReadAndWrite.h"

// 1st task
void reverse_arr() {
    std::vector <float> vec = f_read("1_in");
    std::reverse(vec.begin(), vec.end());
    f_write("1_out", vec);
}

// 2nd task
void price_avg(int percent) {
    std::vector <float> vec = f_read("2_in");
    auto avg_price = std::accumulate(vec.begin(), vec.end(), 0.0) / vec.size();

    for (auto& i : vec) {
        if (i < avg_price)
            i += i*(percent/100.0);
    }

    avg_price = std::accumulate(vec.begin(), vec.end(), 0.0) / vec.size();
    vec.clear();
    vec.push_back(avg_price);
    f_write("2_out", vec);
}

// 3rd task
void temp_count(float t0) {
    if (t0 <= 0)
        throw std::invalid_argument("t0 yra neteigiamas skaicius");

    int count = 0;
    std::vector <float> vec = f_read("3_in");
    
    for (auto& i : vec) {
        if(i > 0 && i < t0)
            count++;
    }

    vec.clear();
    vec.push_back(count);
    f_write("3_out", vec);
}

// 4th task
void count_of_3() {
    int count = 0;
    std::vector <int> vec = i_read("4_in");

    for (auto& i : vec) {
        std::cout << i << std::endl;
        if(i / 10 == 3)
            count++;
    }

    vec.clear();
    vec.push_back(count);
    i_write("4_out", vec);
}

// 5th task
void atmospheric_pressure(int p1, int p2) {
    int count = 0;
    std::vector <int> vec = i_read("5_in");

    for (auto& i : vec) {
        if(i > p1 &&  i < p2)
            count++;
    }

    vec.clear();
    vec.push_back(count);
    i_write("5_out", vec);
}

// 6th task
void symmetry() {
    std::vector <int> full = i_read("6_in", true);

    int size = full.size() / 2;
    std::vector <int> start; std::vector <int> end;

    for (int i = 1; i <= size; i++) {
        start.push_back(full.at(i-1));
        end.push_back(full.at(full.size()-i));
    }

    write_text("6_out", (start==end)? "YES" : "NO");
}

// 7th task
void dupe_check() {
    std::vector <int> vec = i_read("7_in", true);
    std::ofstream OUT("OUT/7_out.txt");

    for (auto it = vec.begin(); it != vec.end(); it++) {
        auto it_2 = std::find(it+1, vec.end(), *it);
        if (it == vec.end())
            throw std::runtime_error("No Duplicate numbers found");
        else if (it_2 == vec.end())
            continue;
        OUT << std::distance(vec.begin(), it)+1 <<  " " << std::distance(vec.begin(), it_2)+1 << " " << *it << "\n";
    }

    OUT.close();
}

// 8th task
void repeats() {
    std::vector <int> vec = i_read("8_in", true);
    auto end = vec.end();
    // Dynamic loop, fixing issue of going out of bounds when modifying vecotr size
    for (auto it = vec.begin(); it != end; it++)
        end = std::remove(it+1, vec.end(), *it); // Removes all values same as *it, past 'it'

    vec.erase(end, vec.end());
    // Solution from TechieDelight, taught me more about iterators and some useful functions

    std::ofstream OUT("OUT/8_out.txt");
    for (auto& i : vec)
        OUT << i << " ";

    OUT.close();
}

// 9th task
void wom_paycheck() {
    std::vector <int> vec = i_read("9_in", true);
    auto it = vec.begin();

    while(it != vec.end()) {
        it++;
        vec.erase(it);
    }

    std::ofstream OUT("OUT/9_out.txt");
    for (auto& i : vec)
        OUT << i << " ";

    OUT.close();
}


