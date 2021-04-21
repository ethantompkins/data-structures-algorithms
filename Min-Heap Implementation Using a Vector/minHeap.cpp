/*
 * Name: Ethan Tompkins 
 * Date Submitted: 11/24/20
 * Assignment Name: minHeap Implementation Using a Vector
 */
 
 #include <vector>
 #include "minHeap.h"
 #include <iostream>
 #include <fstream>
 
 minHeap::minHeap(vector<int> data)
 {
    for(int i = 0; i < data.size(); i++)
    {
        insert(data[i]);
    }
 }
 
 void minHeap::insert(int value)
 {
     heap.push_back(value);
     siftUp(heap.size()-1);
 }
 
 int minHeap::removeMin()
 {
     int retValue = heap[0];
     swap(heap[0], heap[heap.size()-1]);
     heap.pop_back();
     siftDown(0);
     return retValue;
 }
 
 void minHeap::siftUp(int pos)
 {
     if(pos == 0)
     {
         return;
     }
     int child = pos - 1;
     int parent = child/2;
     
     if((heap[parent] > heap[pos]))
     {
         int temporary = heap[parent];
         heap[parent] = heap[pos];
         heap[pos] = temporary;
     }
     siftUp(parent);
 }
 
 void minHeap::siftDown(int pos)
 {
     int lChild;
     int rChild;
     int sChild;
 
     if(((pos*2) + 1) < heap.size())
     {
         lChild = (pos*2) + 1;
     }
     else{
         lChild = pos;
     }
     
     if(((pos*2) + 2) < heap.size())
     {
         rChild = (pos*2) + 2;
     }
     else{
         rChild = pos;
     }
     
     if(heap[lChild] < heap[rChild])
     {
         sChild = lChild;
     }
     else{
         sChild = rChild;
     }
     
     if(heap[pos] > heap[sChild])
     {
         swap(heap[pos], heap[sChild]);
         pos = sChild;
         siftDown(pos);
     }
     
 }
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 