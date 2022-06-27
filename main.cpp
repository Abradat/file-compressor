//
//  main.cpp
//  final
//
//  Created by Shayan Khorsandi on 10/31/16.
//  Copyright © 2016 Shayan Khorsandi. All rights reserved.
//

#include <iostream>
#include "vector.hpp"
#include "Node.hpp"
#include "DataCompressor.hpp"
#include "MatchDetector.hpp"


int main(int argc, const char * argv[]) {
    DataCompressor dataCompressor;
    dataCompressor.init("/Users/SlyTaNiX/Desktop/DS-project/final/final/x.txt");
    
    cout<<"Data Compressed"<<endl;
    
    CompressedData compressedData;
    dataCompressor.getCompressedData(compressedData);
    
    MatchDetector matchDetector;
    MatchMakingResult result;
    
    matchDetector.detectMatch(compressedData, result);
    
    result.print();
     
    while(true)
    {
        
    }
    return 0;
}
