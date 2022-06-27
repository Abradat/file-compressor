//
//  Node.hpp
//  final
//
//  Created by Shayan Khorsandi on 10/31/16.
//  Copyright © 2016 Shayan Khorsandi. All rights reserved.
//

#ifndef Node_hpp
#define Node_hpp

#include <stdio.h>
#include "vector.hpp"
#include <iostream>
#include <cstdlib>

using namespace std;

typedef unsigned short int ushort;

class Node
{
    ushort id;
    
public:
    
    Vector< ushort> dests;
    Vector< Vector <ushort>* > times;
    
    Node(ushort number)
    {
        this->id = number;
        //bool insert_check[number];
    }
    ushort get_id()
    {
        return this->id;
    }
    
    ushort getEdgesCount()
    {
        ushort count = 0 ;
        ushort dest_size = dests.getSize();
        for(ushort dest_counter =0; dest_counter < dest_size; dest_counter++)
        {
            ushort time_size = times[dest_counter]->getSize();
            count += time_size;
        }
        return count;
    }
    void printEdges()
    {
        ushort dest_size = dests.getSize();
        for(ushort dest_counter = 0; dest_counter < dest_size ; dest_counter++)
        {
            ushort time_size = times[dest_counter]->getSize();
            cout<<"Edge "<<id << " , " << dests[dest_counter] << " repeated " << time_size << " times in ";
            for(ushort time_counter = 0; time_counter < time_size; time_counter++ )
            {
                cout<<times[dest_counter]->get(time_counter) << " , ";
            }
            cout<<endl;
        }
    }
    void insert_node(ushort dest, ushort time)
    {
        bool check =0;
        ushort dest_size = dests.getSize();
        for(ushort dest_counter =0; dest_counter < dest_size; dest_counter++)
        {
            if(dest == dests[dest_counter])
            {
                check = 1;
                bool dup_check = 1;
                ushort time_size = times[dest_counter]->getSize();
                for(ushort time_counter =0; time_counter < time_size; time_counter++)
                {
                    if(time == times[dest_counter]->get(time_counter))
                    {
                        dup_check = 0;
                        break;
                    }
                }
                if(dup_check == 1)
                    times[dest_counter]->insert(time);
                
                break;
            }
        }
        if(check == 0)
        {
            Vector<ushort> *insertion = new Vector<ushort>;
            insertion->insert(time);
            times.insert(insertion);
            dests.insert(dest);
        }
    }
    
    void clean()
    {
        Vector<ushort>cleaner;
        ushort dest_size = dests.getSize();
        for(ushort dest_counter = 0; dest_counter < dest_size; dest_counter++)
        {
            ushort time_size = times[dest_counter]->getSize();
            if(time_size == 1)
            {
                //dests.remove(dest_counter);
                //times.remove(dest_counter);
                cleaner.insert(dest_counter);
            }
        }
        ushort cleaner_size = cleaner.getSize(), cnt =0;
        for(ushort cleaner_counter = 0; cleaner_counter < cleaner_size; cleaner_counter++)
        {
            dests.remove(cleaner_counter - cnt);
            times.remove(cleaner_counter - cnt);
            cnt++;
        }
    }
    
};

#endif /* Node_hpp */
