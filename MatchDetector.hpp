//
//  MatchDetector.hpp
//  final
//
//  Created by Shayan Khorsandi on 11/1/16.
//  Copyright © 2016 Shayan Khorsandi. All rights reserved.
//

#ifndef MatchDetector_hpp
#define MatchDetector_hpp

#include <stdio.h>
#include "DataCompressor.hpp"
#include "MatchMakingResult.hpp"

class MatchDetector
{
public:
    
    void detectMatch(const CompressedData &compressed_data, MatchMakingResult &return_result)
    {
        MatchMakingResult result;
        for(int cnt = 0; cnt < 65535; cnt++)
        {
            result.addNode(cnt, compressed_data.x[cnt]);
        }
        
        return_result = result;
    }
};

#endif /* MatchDetector_hpp */
