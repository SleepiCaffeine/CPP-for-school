#include <bits/stdc++.h>
#include "ReadAndWrite.h"

// 1st task
void reverse_arr() {
    std::vector <float> vec = __f_init__("1_in");

    std::reverse(vec.begin(), vec.end());
    print_float("1_out", vec);
}

// 2nd task
void price_avg(int percent) {
    std::vector <float> vec = __f_init__("2_in");
    // auto result = std::reduce(vec.begin(), vec.end()) / 1.0;  Would use this if exams allowed C++17
    auto avg_price = std::accumulate(vec.begin(), vec.end(), 0.0) / vec.size();

    for (auto& i : vec) {
        if (i < avg_price)
            i += i*(percent/100.0);
    }

    avg_price = std::accumulate(vec.begin(), vec.end(), 0.0) / vec.size();
    vec.clear();
    vec.push_back(avg_price);
    print_float("2_out", vec);
}

// 3rd task
void temp_count(float t0) {
    if (t0 <= 0)
        throw std::invalid_argument("t0 is not a positive value!");

    int count = 0;
    std::vector <float> vec = __f_init__("3_in");
    
    for (auto& i : vec) {
        if(i > 0 && i < t0)
            count++;
    }

    vec.clear();
    vec.push_back(count);
    print_float("3_out", vec);
}

// 4th task
void count_of_3() {
    int count = 0;
    std::vector <int> vec = __i_init__("4_in");

    for (auto& i : vec) {
        if(i / 10 == 3)
            count++;
    }

    vec.clear();
    vec.push_back(count);
    print_int("4_out", vec);
}

// 5th task
void atmospheric_pressure(int p1, int p2) {
    int count = 0;
    std::vector <int> vec = __i_init__("5_in");

    for (auto& i : vec) {
        if(i > p1 &&  i < p2)
            count++;
    }

    vec.clear();
    vec.push_back(count);
    print_int("5_out", vec);

}



