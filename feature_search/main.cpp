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


void feature_search(std::vector<std::vector<float>> data) {
    for(int  i = 0; i < data.size()-1; i++) {
        if(i==1) {
            std::cout << "On the 1st level of the search tree" << std::endl;
        }
        else {
        std::cout << "On the " << i << "th level of the search tree" << std::endl;
        }
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
    
    
    //parse through file input
    while (std::getline(myfile, line)) {
        std::istringstream iss(line);
        
        for(int i = 0; std::getline(iss, input, ' '); i++) {
            data.at(i).push_back(std::stof(input));      //convert to float
        }
    }
    
    return 0;
}
