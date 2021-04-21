/*
 * Name: Ethan Tompkins
 * Date Submitted: 10/13/20
 * Lab Section: 004
 * Assignment Name: Spell Checker Using a Hash Table
 */

#include "math.h"
#include "stringset.h"

Stringset::Stringset() : table(4), num_elems(0), size(4) {}

Stringset::Stringset(int size) : table(size),num_elems(0),size(size) {}

//Used in test cases and testStringset() in main.cpp, do not modify
vector<list<string>> Stringset::getTable() const
{
    return table;
}

//Used in test cases and testStringset() in main.cpp, do not modify
int Stringset::getNumElems() const
{
    return num_elems;
}

//Used in test cases and testStringset() in main.cpp, do not modify
int Stringset::getSize() const
{
    return size;
}

int Stringset::getHash(string word) const
{
    hash<string> stringHash;
    
    int hashVal = stringHash(word);
    
    return abs(hashVal);
}

void Stringset::insert(string word)
{
    if(find(word))
    {
        return;
    }
    
    int hashValue;
    if(size == num_elems)
    {
        Stringset setNew = Stringset(size * 2);
        
        string placeholder;
        
        for(int z = 0; z < getSize(); z++)
        {
            int listSize = table[z].size();
            for(int x = 0; x < listSize; x++)
            {
                placeholder = table[z].front();
                hashValue = getHash(placeholder) % (getSize() * 2);
                setNew.table[hashValue].push_back(placeholder);
                table[z].pop_front();
            }
        }
        
        table = setNew.table;
        size = size * 2;
    }
    
    hashValue = getHash(word) % size;
    table[hashValue].push_back(word);
    num_elems++;
}

bool Stringset::find(string word) const
{
    bool f = false; //hold false 
    int wordHash = getHash(word) % size;
    if(table[wordHash].empty())
    {
        return false;
    }
    auto z = table[wordHash].begin();
    while(!f && (z != table[wordHash].end()))
    {
        if(*z == word)
        {
            f = true;
        }
        z++;
    }
    return f;
}

void Stringset::remove(string word)
{
    bool f = false;
    int wordHash = getHash(word) % size;
    
    auto z = table[wordHash].begin();
    while(!f && (z != table[wordHash].end()))
    {
        if(*z == word)
        {
            table[wordHash].erase(z);
            num_elems--;
            return;
        }
        z++;
    }
}