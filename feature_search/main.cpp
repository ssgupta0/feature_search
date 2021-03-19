//
//  main.cpp
//  feature_search
//
//  Created by Shashvat Gupta on 3/9/21.
//  Copyright © 2021 Shashvat Gupta. All rights reserved.
//

#include <iostream>
//#include <bits/stdc++.h>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <cmath>

#define inf 999;

bool notDup(std::vector<int> set, int k) {
    for(int i = 0; i < set.size(); i++) {
        if(set.at(i) == k) {
            return false;
        }
    }
    return true;
}


float findAccuracy(std::vector<std::vector<float>> data, std::vector<int> current_set_of_features) {
    
    
    for(int i = 0; i <data.size(); i++) {
        for(int w = 0; w < current_set_of_features.size(); w++) {
            if(i==current_set_of_features.at(w)) {
                for(int k = 0; k < data.at(0).size(); k++) {
                    data.at(i).at(k) = 0;
                }
            }
        }
    }
    
    
    int number_correct = 0;
    
    for(int i = 0; i < data.size(); i++) {
        //float object_to_classify = data.at(i);
        float label_object_to_classify = data.at(i).at(0);
        
        //std::cout << "Looping over i, at the " << i << " location" << std::endl;
        //std::cout << "The " << i << "th object is in class" << label_object_to_classify << std::endl;
        
        float nearest_neighbor_distance = inf;
        float nearest_neighbor_location = inf;
        float nearest_neighbor_label = inf;
        
        for(int k = 0; k < data.size(); k++) {
            if(k!=i) {
                //std::cout << "Ask if " << i << " is nearest neighbor with " << k << std::endl;
                float sum = 0;
                for(int w = 1; w < data.size(); w++) {
                    sum += (data.at(w).at(i)-data.at(w).at(k));
                }
                float distance = sqrt(sum);
                //find distances from i to k for all dimensions
                
                if(distance < nearest_neighbor_distance) {
                    nearest_neighbor_distance = distance;
                    nearest_neighbor_location = k;
                    nearest_neighbor_label = data.at(0).at(nearest_neighbor_location);
                    
                }
            }
        }
        
        if(label_object_to_classify==nearest_neighbor_label) {
            number_correct++;
        }
        
    }
    
    float accuracy = number_correct/data.size();
    
    return accuracy;
}

void feature_search(std::vector<std::vector<float>> data) {
    std::vector<int> current_set_of_features;
    float accuracy = 0;
    float best_accuracy = 0;
    int  feature_to_add = 0;
    
    for(int  i = 1; i < data.size()-1; i++) {
        if(i==1) {
            std::cout << "On the 1st level of the search tree" << std::endl;
        }
        else {
            std::cout << "On the " << i << "th level of the search tree" << std::endl;
        }
        //display level
        
        for(int k = 1; k < data.size()-1;k++) {
            
            if(notDup(current_set_of_features, k)) {
                
                std::cout << "--Considering adding the " << k << " feature" << std::endl;
                current_set_of_features.push_back(k);
                
                //accuracy = leave_out_cross_validation(data, current_set_of_features, k+1);
                
                accuracy = findAccuracy(data, current_set_of_features);
                
                if(accuracy > best_accuracy) {
                    best_accuracy = accuracy;
                    feature_to_add = k;
                }
            }
        }
        //look for main features
        
        std::cout << "On level " << i << " I added feature " << feature_to_add << " to current set" << std::endl;
    }
}



int main(int argc, const char * argv[]) {
    
    std::string input;
    
    std::string fileName = "CS170_SMALLtestdata__75.txt";
    //std::string fileName = "CS170_largetestdata__26.txt";
    
    std::string line;
    std::vector<std::vector<float>> data;
    
    
    // open input file
    std::ifstream myfile(fileName);
    if (myfile.fail()) {
        std::cout << "could not open file" << std::endl;
        exit(1);
    }
    
    bool sz = true;
    //data.resize(100);
    
    //parse through file input
    while (std::getline(myfile, line)) {
        std::istringstream iss(line);
        
        for(int i = 0; std::getline(iss, input, ' '); i++) {
            if(input=="") {
                i--;
            }
            else {
                if(sz) {
                    data.resize(i+1);
                }
                data.at(i).push_back(std::stof(input));      //convert to float
            }
        }
        sz = false;
    }
    //Inputed into data<><>
    
    
    
    
    
    return 0;
}
