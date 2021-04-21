/*
 * Name: Ethan Tompkins
 * Date Submitted: 9/29/20
 * Lab Section: 004
 * Assignment Name: Searching and Sorting
 */

#pragma once

#include <vector>

using namespace std; 

template <class T>
int linearSearch(std::vector<T> data, T target){
    
    for(int a = 0; a < data.size(); a++){
        
        if(data[a] == target){
            return a;
        }
    }
    return -1;
}


template <class T>
int binarySearch(std::vector<T> data, T target){
    int h = data.size() - 1;    //high variable
    int l = 0;                  //low variable
    int m = ((l + h) / 2);     //middle variable
    
    while(l <= h){ 
        if(data[m] == target){
            return m;
        }
        else if(data[m] > target){
            h = m - 1;
        }
        else{
            l = m + 1;
        }
        m = (l + h) / 2;
    }
    return -1;
}