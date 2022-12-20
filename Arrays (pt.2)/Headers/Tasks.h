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



