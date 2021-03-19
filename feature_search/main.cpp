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

#define inf 999999999999;

bool notDup(std::vector<int> set, int k) {
    for(int i = 0; i < set.size(); i++) {
        if(set.at(i) == k) {
            return false;
        }
    }
    return true;
}

void printSet(std::vector<int> set) {
    
    if(set.size()==1) {
        std::cout << "{" << set.at(0) << "}";
        return;
    }
    
    std::cout << "{" << set.at(0) << ",";
    
    for(int i = 1; i<set.size()-1; i++) {
        std::cout << set.at(i) << ",";
    }
    
    std::cout << set.at(set.size()-1) << "}";
    
}

float findAccuracy(std::vector<std::vector<float>> data, std::vector<int> current_set_of_features, int feature_to_add) {
    
    bool in_set = true;
    
    for(int i = 1; i < data.size(); i++) {
        in_set = false;
        
        for(int w = 0; w < current_set_of_features.size(); w++) {
            if(i==current_set_of_features.at(w)) {
                in_set = true;
            }
        }
        
        if(i==feature_to_add) {
            in_set = true;
        }
        
        if(in_set==false) {
            for(int w = 0; w < data.at(i).size(); w++) {
                for(int k = 0; k < data.at(0).size(); k++) {
                    data.at(i).at(k) = 0;
                }
            }
        }
    }
    
    
    
    int number_correct = 0;
    
    for(int i = 0; i < data.at(0).size(); i++) {              //object i compared to object k;
        //float object_to_classify = data.at(i);
        
        //std::cout << "Looping over i, at the " << i << " location" << std::endl;
        //std::cout << "The " << i << "th object is in class" << label_object_to_classify << std::endl;
        
        float label_object_to_classify = data.at(0).at(i);
        
        float nearest_neighbor_distance = inf;
        float nearest_neighbor_location = inf;
        float nearest_neighbor_label = inf;
        
        for(int k = 0; k < data.at(0).size(); k++) {
            if(k!=i) {
                //std::cout << "Ask if " << i << " is nearest neighbor with " << k << std::endl;
                float sum = 0;
                for(int w = 1; w < data.size(); w++) {
                    sum += pow((data.at(w).at(i)-data.at(w).at(k)), 2);
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
    
    float accuracy = (float)number_correct/(float)(data.at(0).size());
    //std::cout << "accuracy: " << accuracy << std::endl;
    return accuracy;
}
//----------------------------

void backward(std::vector<std::vector<float>> data) {
    std::vector<int> current_set_of_features;
    
    // current_set_of_features.resize(data.size()-1);
    
    float accuracy = 0;
    float best_accuracy = 0;
    float final_accuracy = 0;
    std::vector<int> best_set;
    std::vector<int> tmp ;

    
    for(int  i = 1; i < data.size()-1; i++) {
        if(i==1) {
            std::cout << "On the 1st level of the search tree" << std::endl;
        }
        else {
            std::cout << "On the " << i << "th level of the search tree" << std::endl;
        }
        //display level
        
        best_accuracy = 0;
        int  feature_to_add = 0;
        
        for(int k = 1; k < data.size(); k++) {
            
            if(notDup(current_set_of_features, k)) {
                
                //std::cout << "--Considering adding the " << k << " feature" << std::endl;
                
                tmp = current_set_of_features;
                tmp.push_back(k);
                
                std::cout << "--Using feature(s)";
                printSet(tmp);
                
                
                accuracy = findAccuracy(data, current_set_of_features, k);    //k = number of rows?
                //accuracy = rand();  //accuracy = leave_out_cross_validation(data, current_set_of_features, k+1);

                
                std::cout << " accuracy is " << accuracy*100 << "%" << std::endl;

                
                if(accuracy > best_accuracy) {
                    best_accuracy = accuracy;
                    feature_to_add = k;
                }
            }
        }
        //look for main features
        current_set_of_features.push_back(feature_to_add);
        if(final_accuracy<best_accuracy) {
            final_accuracy=best_accuracy;
            best_set = current_set_of_features;
        }
        else {
            std::cout << "Warning, previous sets had better accuracy of: " << final_accuracy*100 << "%" << std::endl;
        }
        //std::cout << "\nOn level " << i << " I added feature " << feature_to_add << " to current set" << std::endl;
        std::cout << "\nFeature set ";
        if(i==1) {
            std::cout << feature_to_add;
        }
        else {
        printSet(tmp);
        }
        std::cout << " was best, accuracy is " << best_accuracy*100 << " %\n" << std::endl;
    }
    
    std::cout << "\nBest accuracy was: " << final_accuracy << " on set: ";
    printSet(best_set);
    std::cout<<std::endl;
    
}

//----------------------------

void forward(std::vector<std::vector<float>> data) {
    std::vector<int> current_set_of_features;
    
    // current_set_of_features.resize(data.size()-1);
    
    float accuracy = 0;
    float best_accuracy = 0;
    float final_accuracy = 0;
    std::vector<int> best_set;
    std::vector<int> tmp ;

    
    for(int  i = 1; i < data.size()-1; i++) {
        if(i==1) {
            std::cout << "On the 1st level of the search tree" << std::endl;
        }
        else {
            std::cout << "On the " << i << "th level of the search tree" << std::endl;
        }
        //display level
        
        best_accuracy = 0;
        int  feature_to_add = 0;
        
        for(int k = 1; k < data.size(); k++) {
            
            if(notDup(current_set_of_features, k)) {
                
                //std::cout << "--Considering adding the " << k << " feature" << std::endl;
                
                tmp = current_set_of_features;
                tmp.push_back(k);
                
                std::cout << "--Using feature(s)";
                printSet(tmp);
                
                
                accuracy = findAccuracy(data, current_set_of_features, k);    //k = number of rows?
                //accuracy = rand();  //accuracy = leave_out_cross_validation(data, current_set_of_features, k+1);

                
                std::cout << " accuracy is " << accuracy*100 << "%" << std::endl;

                
                if(accuracy > best_accuracy) {
                    best_accuracy = accuracy;
                    feature_to_add = k;
                }
            }
        }
        //look for main features
        current_set_of_features.push_back(feature_to_add);
        if(final_accuracy<best_accuracy) {
            final_accuracy=best_accuracy;
            best_set = current_set_of_features;
        }
        else {
            std::cout << "Warning, previous sets had better accuracy of: " << final_accuracy*100 << "%" << std::endl;
        }
        //std::cout << "\nOn level " << i << " I added feature " << feature_to_add << " to current set" << std::endl;
        std::cout << "\nFeature set ";
        if(i==1) {
            std::cout << feature_to_add;
        }
        else {
        printSet(tmp);
        }
        std::cout << " was best, accuracy is " << best_accuracy*100 << " %\n" << std::endl;
    }
    
    std::cout << "\nBest accuracy was: " << final_accuracy << " on set: ";
    printSet(best_set);
    std::cout<<std::endl;
    
}



int main(int argc, const char * argv[]) {
    
    std::string input;
    
    //std::string fileName = "CS170_SMALLtestdata__75.txt";
    //std::string fileName = "CS170_largetestdata__26.txt";
    
    std::string fileName = "CS170_small_special_testdata__97.txt";

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
            if(input=="" || input=="\r") {
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
    
    feature_search(data);
    //std::cout << x < std::endl;
    
    
    
    return 0;
}
