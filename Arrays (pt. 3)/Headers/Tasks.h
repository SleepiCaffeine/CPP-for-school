#include <bits/stdc++.h>
#include "Read&Write.h"

// 1st task
void family_heights(std::vector <int> fam_vec) {
    if (fam_vec.size() % 2 != 0 && fam_vec.size() < 1)
        throw std::invalid_argument("Invalid Vector Size");

    std::vector <int> men_vec;
    auto it = fam_vec.begin();

    while(it != fam_vec.end()) {
        it++;
        men_vec.push_back(*it);
        fam_vec.erase(it);
    }
    std::sort(men_vec.begin(), men_vec.end(), std::greater <int>());
    std::sort(fam_vec.begin(), fam_vec.end(), std::greater <int>());

    int men_diff = men_vec.at(0) - men_vec.at(men_vec.size()-1);
    int wom_diff = fam_vec.at(0) - fam_vec.at(fam_vec.size()-1);

    (men_diff > wom_diff)? write_text("1_out", "Largest difference was between men: " + std::to_string(men_diff)) :
                           write_text("1_out", "Largest difference was between women: " + std::to_string(wom_diff));    
}

// 2nd task
void price_freq(std::vector <float> price_vec) {
    if (price_vec.size() < 0 || price_vec.size() > 100)
        throw std::invalid_argument("Invalid Vector Size");
    std::sort(price_vec.begin(), price_vec.end(), std::greater<float>());
    int count = 0;

    for (auto it = price_vec.begin(); it != price_vec.end(); it++) 
        if (price_vec.at(0) == *it) count++;
        else break;
    
    write_text("2_out", std::to_string(count));
}

// 3rd task
void temp_pressure_avg(int p0) {
    std::vector <int> temp_vec = i_read("3_temp");
    std::vector <int> pres_vec = i_read("3_pressure");

    if (temp_vec.size() < 1 || pres_vec.size() < 1 || temp_vec.size() != pres_vec.size())
        throw std::invalid_argument("Invalid Vector Sizes");
    
    int count = 0;
    int temp = 0;
    for (int i = 0; i < temp_vec.size(); i++) {
        if (temp_vec.at(i) > 0 && pres_vec.at(i) > p0) {
            temp++;
            std::cout << "AT: " << i << " TEMP IS: " << temp << std::endl;
            count += (count == temp-1)? 1 : 0;
        }
        else
            temp = 0;
    }
    write_text("3_out", std::to_string(count));
}

// 4th task
void nut_sizes() {
    std::unordered_map <int, int> umap;                                // Learned about unordered maps!
    std::ifstream IN("IN/4_in.txt");
    int n; IN >> n;
    if (n >= 500 || n < 0) 
        throw std::invalid_argument("Invalid Vector Size");

    int size; int amount;
    for (int i = 0; i < n; i++) {
        IN >> size;
        IN >> amount;
        if (umap.find(size) != umap.end()) {
            umap[size] += amount;
        }
        else
            umap[size] = amount;
    }
    IN.close();

    std::vector<std::pair<int, int>> nuts(umap.begin(), umap.end());    // Ty Barry fro SO (https://stackoverflow.com/users/2069064/barry)
    std::sort(nuts.begin(), nuts.end(), comp);

    std::string result = "";
    for (auto it = nuts.begin(); it != nuts.end(); it++) 
        result += "M" + std::to_string(it->first) + ": " + std::to_string(it->second) +" \n";

    write_text("4_out", result);
}

// 5th task
void coordinates() {
    std::vector <int> coords = i_read("5_in", true);
    std::unordered_map <int, double> umap;
    int size = (coords.size()/2)-1;
    if (size < 3 || size > 100)
        throw std::invalid_argument("Invalid Vector Size");

    int x0 = coords.at(0);
    int y0 = coords.at(1);

    int xi; int yi; double len; int key = 1;
    for (auto it = coords.begin()+2; it != coords.end(); it+=2) {
        xi = abs(x0-*it);
        yi = abs(y0-*(it+1));
        len = sqrt(xi*xi + yi*yi);
        umap[key] = len;
        key++;
    }

    std::vector<std::pair<int, double>> lens(umap.begin(), umap.end());
    std::sort(lens.begin(), lens.end(), comp_d);

    std::string result = "";
    for (auto it = lens.begin(); it != lens.begin()+3; it++) 
        result += "(" + std::to_string(coords.at(it->first*2)) + "; " + std::to_string(coords.at(it->first*2+1)) + ")\n";

    write_text("5_out", result);
}

// 6th task
void pew_pew() {
    std::vector <int> scores = i_read("6_in", true);
    if (scores.size() > 200 || scores.size() < 0)
        throw std::invalid_argument("Invalid Vector Size");

    std::unordered_map <int, int> umap;
    for (auto it = scores.begin(); it != scores.end(); it++) {
        if (umap.find(*it) != umap.end())
            umap[*it]++;
        else
            umap[*it] = 1;
    }

    std::vector<std::pair<int, int>> new_scores(umap.begin(), umap.end());
    std::sort(new_scores.begin(), new_scores.end(), comp);

    std::string result = "Highest frequency was: " + std::to_string(new_scores.at(0).first) + "\n";
    for (auto it = new_scores.begin(); it != new_scores.end(); it++)
        result += std::to_string(it->first) + ": " + std::to_string(it->second) +"\n";
 
    write_text("6_out", result);
}

// 8th task
void birth_freq() {
    std::vector <int> months = i_read("8_in");
    if (months.size() > 9000000 || months.size() < 0)
        throw std::invalid_argument("Invalid Vector Size");

    std::unordered_map <int, int> umap;
    for (auto it = months.begin(); it != months.end(); it++) {
        it++;
        if (umap.find(*it) != umap.end())
            umap[*it]++;
        else
            umap[*it] = 1;
        it++;
    }

    std::vector<std::pair<int, int>> new_scores(umap.begin(), umap.end());
    std::sort(new_scores.begin(), new_scores.end(), comp);

    std::string result = "Highest frequency was: " + std::to_string(new_scores.at(0).first) + "\n";
    for (auto it = new_scores.begin(); it != new_scores.end(); it++)
        result += std::to_string(it->first) + ": " + std::to_string(it->second) +"\n";
 
    write_text("8_out", result);
}