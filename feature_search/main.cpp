//
//  main.cpp
//  feature_search
//
//  Created by Shashvat Gupta on 3/9/21.
//  Copyright © 2021 Shashvat Gupta. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <vector>


void feature_search() {
    //for(int  i = 0; i < )
}

int main(int argc, const char * argv[]) {

    std::string input;
    
    
    //lungs
    
    //height
    //years
    //weight
    //cigs
    
    std::vector<std::vector<float>> data {
        {},{},{},{},{}
    };
    
    // open input file
    std::ifstream myfile("movieReviews.txt");
    if (myfile.fail()) {
        std::cout << "could not open file" << std::endl;
        exit(1);
    }
    
    
    //parse through file input
    while (!myfile.eof()) {
        myfile >> input;                             //input value
        data.at(0).push_back(std::stof(input));      //convert to float
        myfile.get();                                //get blank space
        
        myfile >> input;                             //input value
        data.at(1).push_back(std::stof(input));      //convert to float
        myfile.get();                                //get blank space
        
        myfile >> input;                             //input value
        data.at(2).push_back(std::stof(input));      //convert to float
        myfile.get();                                //get blank space
        
        myfile >> input;                             //input value
        data.at(3).push_back(std::stof(input));      //convert to float
        myfile.get();                                //get blank space
        
        myfile >> input;                             //input value
        data.at(4).push_back(std::stof(input));      //convert to float
        myfile.get();                                //get blank space
    }
    
    return 0;
}
