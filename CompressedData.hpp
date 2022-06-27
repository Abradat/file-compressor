//
//  CompressedData.hpp
//  final
//
//  Created by Shayan Khorsandi on 10/31/16.
//  Copyright © 2016 Shayan Khorsandi. All rights reserved.
//

#ifndef CompressedData_hpp
#define CompressedData_hpp

#include <stdio.h>
#include "Node.hpp"

class CompressedData
{
public:
    
    Node * x[65535];
    CompressedData()
    {
        for(ushort node_creator =0; node_creator<65535; node_creator++)
            x[node_creator] = new Node(node_creator);
    }
    
};
#endif /* CompressedData_hpp */
