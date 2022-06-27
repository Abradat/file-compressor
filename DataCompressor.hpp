//
//  DataCompressor.hpp
//  final
//
//  Created by Shayan Khorsandi on 10/31/16.
//  Copyright © 2016 Shayan Khorsandi. All rights reserved.
//

#ifndef DataCompressor_hpp
#define DataCompressor_hpp

#include <stdio.h>
#include "CompressedData.hpp"
#include <string>
#include <fstream>


using namespace std;

class DataCompressor
{
public:
    void init(const string &entry_file)
    {
        ifstream ifs(entry_file);
        ushort a,b,c;
        cout<<"Compressing"<<endl;
        while(!ifs.eof())
        {
            ifs>>a>>b>>c;
            compressedData.x[a-1]->insert_node(b,c);
        }
        /*
        int x_cnt = 0;
        cout<<"Deleting"<<endl;
        for(ushort cnt = 0; cnt <65535; cnt++)
        {
            compressedData.x[cnt]->clean();
            x_cnt++;
        }
        cout<<x_cnt<<endl<<endl;
         */
    }
    
    void getCompressedData(CompressedData &return_compressed_data)
    {
        return_compressed_data = compressedData;
    }
private:
    CompressedData compressedData;
    
};
#endif /* DataCompressor_hpp */
