//
//  MatchMakingResult.hpp
//  final
//
//  Created by Shayan Khorsandi on 11/1/16.
//  Copyright © 2016 Shayan Khorsandi. All rights reserved.
//

#ifndef MatchMakingResult_hpp
#define MatchMakingResult_hpp

#include <stdio.h>
#include "DataCompressor.hpp"

class MatchMakingResult
{
private:
    unsigned int repeatedCount = 0;
    Node * x[65535];
public:
    MatchMakingResult()
    {
        for(ushort node_creator =0; node_creator<65535; node_creator++)
            x[node_creator] = new Node(node_creator);
    }
    
    void addNode(ushort index, Node *sourceNode)
    {
        int count = sourceNode->getEdgesCount();
        if(count > 0)
        {
            repeatedCount += count;
            x[index] = sourceNode;
        }
    }
    
    void print()
    {
        cout<<"Number of repeated edges: " << repeatedCount << endl;
        for(ushort print_counter = 0; print_counter < 65535; print_counter++)
        {
            x[print_counter]->printEdges();
        }
    }
};
#endif /* MatchMakingResult_hpp */
