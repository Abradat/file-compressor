//
//  vector.hpp
//  final
//
//  Created by Shayan Khorsandi on 10/31/16.
//  Copyright © 2016 Shayan Khorsandi. All rights reserved.
//

#ifndef vector_hpp
#define vector_hpp

#include <stdio.h>
#include <iostream>
#include <stdexcept>

typedef unsigned short int ushort;

template <typename T>
class Vector {
public:
    Vector			(const ushort size = 1);
    virtual ~Vector		();
    void 	insert		(const T& data);
    T 	operator[]	(const ushort& i) const throw (std::out_of_range);
    T 	remove		(const ushort& i) throw(std::out_of_range);
    void 	print		() const;
    ushort getSize();
    T get(ushort index);
private:
    void 	checkBoundary	(const ushort& i) const throw (std::out_of_range);
    void 	slide		(const ushort& i);
    void 	copy		(const ushort& capacity);
    ushort 	mSize;
    ushort 	mCapacity;
    T* 	mVector;
};




template <typename T>
Vector<T>::Vector(const ushort capacity) {
    mSize = 0;
    mCapacity = capacity;
    mVector = new T [mSize];
}

template <typename T>
Vector<T>::~Vector() {
    delete[] mVector;
}

template <typename T>
void Vector<T>::copy(const ushort& capacity) {
    mCapacity = capacity;
    T* tmp_vector = new T[mCapacity];
    for (ushort i = 0; i < mSize; ++i) {
        tmp_vector[i] = mVector[i];
    }
    //if(mVector != nullptr)
    delete[] mVector;
    mVector = tmp_vector;
}

template <typename T>
void Vector<T>::insert(const T& data) {
    if (mCapacity <= mSize) copy(mCapacity*2);
    
    mVector[mSize++] = data;
}

template <typename T>
void Vector<T>::checkBoundary(const ushort& i) const throw (std::out_of_range) {
    if (i >= mSize) {
        std::string msg = "Out of range 0 - " + std::to_string(mSize - 1);
        throw std::out_of_range(msg);
    }
}

template <typename T>
T Vector<T>::operator[](const ushort& i) const throw (std::out_of_range) {
    checkBoundary(i);
    return mVector[i];
}

template <typename T>
void Vector<T>::print() const {
    for (ushort i = 0; i < mSize; ++i)
        std::cout << &mVector[i] << " ";
    std::cout << " | Size: " << mSize << " | Capacity: " << mCapacity;
    std::cout << std::endl;
}

template <typename T>
void Vector<T>::slide(const ushort& i) {
    for (ushort j = i + 1; j < mSize; ++j) {
        mVector[j - 1] = mVector[j];
    }
    --mSize;
}

template <typename T>
T Vector<T>::remove(const ushort& i) throw(std::out_of_range) {
    checkBoundary(i);
    T data = mVector[i];
    slide(i);
    
    if (mSize <= mCapacity/4) copy(mCapacity/2);
        
        return data;
}

template <typename T>
ushort Vector<T>::getSize()
{
    return mSize;
}

template <typename T>
T Vector<T>::get(ushort index)
{
    return mVector[index];
}

#endif /* vector_hpp */
