//
//  main.cpp
//  feature_search
//
//  Created by Shashvat Gupta on 3/9/21.
//  Copyright © 2021 Shashvat Gupta. All rights reserved.
//

#include <iostream>
#include <fstream>





int main(int argc, const char * argv[]) {

    std::string input;
    
    float lung;
    
    float height;
    float years;
    float weight;
    float cigs;
    
    // open input file
    std::ifstream myfile("movieReviews.txt");
    if (myfile.fail()) {
        std::cout << "could not open file" << std::endl;
        exit(1);
    }
    
    
    //parse through file input
    while (!myfile.eof()) {
        myfile >> input;                //input value
        lung = std::stof(input);      //convert to float
        myfile.get();                   //get blank space
        
        myfile >> input;                //input value
        height = std::stof(input);      //convert to float
        myfile.get();                   //get blank space
        
        myfile >> input;                //input value
        years = std::stof(input);      //convert to float
        myfile.get();                   //get blank space
        
        myfile >> input;                //input value
        weight = std::stof(input);      //convert to float
        myfile.get();                   //get blank space
        
        myfile >> input;                //input value
        cigs = std::stof(input);      //convert to float
        myfile.get();                   //get blank space
    }
    
    return 0;
}
