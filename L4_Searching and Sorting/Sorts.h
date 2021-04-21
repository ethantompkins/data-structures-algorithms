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
std::vector<T> mergeSort(std::vector<T> lst){
   
    int m = lst.size()/2;
    
    int a = m;
   
    int z = 0;
    
    vector <T> right;
    vector <T> left;
    vector <T> tempR;
    vector <T> tempL;
    vector <T> sorted;
    if(lst.size() <= 1){
        return lst;
    }
    while(z < m){
        tempL.emplace_back(lst[z]);
        z++;
    }
    while(a < lst.size()){
        tempR.emplace_back(lst[a]);
        a++;
    }
   
    z = 0;
    a = 0;
    left = mergeSort(tempL);
    right = mergeSort(tempR);
    
    while(sorted.size() != lst.size()){
        if(z < left.size() && a < right.size() && left[z] < right[a]){
            sorted.emplace_back(left[z]);
            z++;
        }
        else if(a < right.size()){
            sorted.emplace_back(right[a]);
            a++;
        }
        else if(z < left.size()){
            sorted.emplace_back(left[z]);
            z++;
        }
    }
    return sorted;
}


template <class T>
std::vector<T> partition(std::vector<T> &lst, int min, int max){
    if(min < max){
        T pivotValue = lst[min];
        int z = min + 1;
        int pivotIndex = min;
        
        while(z <= max){
            if(pivotValue > lst[z]){
                pivotIndex = pivotIndex+1;
                swap(lst[z], lst[pivotIndex]);
            }
            z++;
        }
        swap(lst[min], lst[pivotIndex]);
        partition(lst, min, pivotIndex-1);
        partition(lst, pivotIndex + 1, max);
    }
    return lst;
}

template <class T>
std::vector<T> quickSort(std::vector<T> lst){
    return partition(lst, 0, lst.size()-1);
}
