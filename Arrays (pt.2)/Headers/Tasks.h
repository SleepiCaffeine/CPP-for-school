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
            i += i*(percent / 100.0);
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
        start.push_back(full.at(i - 1));
        end.push_back(full.at(full.size() - i));
    }

    write_text("6_out", (start==end)? "YES" : "NO");
}

// 7th task
void dupe_check() {
    std::vector <int> vec = i_read("7_in", true);
    std::ofstream OUT("OUT/7_out.txt");

    for (auto it = vec.begin(); it != vec.end(); it++) {
        auto it_2 = std::find(it + 1, vec.end(), *it);
        if (it == vec.end())
            throw std::runtime_error("No Duplicate numbers found");
        else if (it_2 == vec.end())
            continue;
        OUT << std::distance(vec.begin(), it) + 1 <<  " " << std::distance(vec.begin(), it_2) + 1 << " " << *it << "\n";
    }

    OUT.close();
}

// 8th task
void repeats() {
    std::vector <int> vec = i_read("8_in", true);
    auto end = vec.end();
    // Dynamic loop, fixing issue of going out of bounds when modifying vector size
    for (auto it = vec.begin(); it != end; it++)
        end = std::remove(it + 1, vec.end(), *it); // Removes all values same as *it, past 'it'

    vec.erase(end, vec.end());
    i_write_s("8_out", vec);
}

// 9th task
void wom_paycheck() {
    std::vector <int> vec = i_read("9_in", true);
    auto it = vec.begin();

    while(it != vec.end()) {
        it++;
        vec.erase(it);
    }

    i_write_s("9_out", vec);
}

// 10th task
void remove_heights() {
    std::vector <int> vec = i_read("10_in", true);
    auto it = vec.begin();
    int p = vec[0]; vec.erase(it);
    
    for (it = vec.begin(); it != vec.end(); ) {
        if (*it < p)
            it = vec.erase(it); // This avoids a segfault
        else it++;
    }

    i_write_s("10_out", vec);
}

// 11th task
void class_heights() {
    std::vector <int> cl = i_read("11_in_class", true);
    std::vector <int> fresh = i_read("11_in_freshmen", true);

    cl.insert(cl.end(), fresh.begin(), fresh.end());
    std::sort(cl.begin(), cl.end(), std::greater<int>()); //cppreference +rep

    std::ofstream OUT("OUT/11_out.txt");
    OUT << cl.size() << "\n";
    for (auto& i : cl)
        OUT << i << " ";
    OUT.close();
}

// 12th task
void figure_judging() {
    std::vector <int> tech = i_read("12_in", true);
    std::vector <int> style;

    auto it = tech.begin();
    while(it != tech.end()) {
        it++;                   // Sets iterator to begin()+1, aka second element
        style.push_back(*it);   // Pushes back pointer value
        tech.erase(it);         // Removes value from initial vector, leaving odd value behind
    }

    // Sort the vectors, so the highest value is the first element and the lowest in the last element
    std::sort(tech.begin(), tech.end(), std::greater<int>());
    std::sort(style.begin(), style.end(), std::greater<int>());

    // Removing first and last elements
    tech.erase(tech.begin());
    tech.erase(tech.end() - 1);
    style.erase(style.begin());
    style.erase(style.end() - 1);

    auto tech_avg = std::accumulate(tech.begin(), tech.end(), 0.0) / tech.size();
    auto style_avg = std::accumulate(style.begin(), style.end(), 0.0) / style.size();
    
    std::ofstream OUT("OUT/12_out.txt");
    OUT << std::setprecision(2) << tech_avg << "\n";
    OUT << std::setprecision(2) << style_avg <<  "\n";
    OUT.close();
}

// 13th task
void team_tournament() {
    std::vector <int> team_num = i_read("13_in", true);
    std::vector <int> score;

    auto it = team_num.begin();
    while(it != team_num.end()) {
        it++;             
        score.push_back(*it);
        team_num.erase(it); 
    }

    std::vector <int> score_copy = score;
    std::sort(score_copy.begin(), score_copy.end(), std::greater<int>());
    
    std::ofstream OUT("OUT/13_out.txt");
    OUT << score.size() / 2 << "\n";

    for (it = score_copy.begin(); it != score_copy.end() - (score_copy.size() / 2); it++) {
        auto it_2 = std::find(it + 1, score.end(), *it);    // Finds the value in the unsorted array
        int index = std::distance(score.begin(), it_2);     // Finds the index of the searched value
        OUT << team_num.at(index) << " " << score.at(index) << "\n";  // Output from unsorted array
    }
    OUT.close();
}
