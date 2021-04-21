#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<string> loadWordlist(string filename);


vector<string> anagram(string word, vector<string> wordlist);

int main()
{
    vector<string> words;
    vector<string> anagrams;
    string inputWord;
    words=loadWordlist("wordlist.txt");
    cout << "Find single-word anagrams for the following word: ";
    cin >> inputWord;
    anagrams = anagram(inputWord, words);
    for (int i=0; i<anagrams.size(); i++)
    {
        cout << anagrams[i] << endl;
    }
    return 0;
}

vector<string> loadWordlist(string filename)
{
    vector<string> words;
    ifstream inFile;
    string word;
    inFile.open(filename);
    if(inFile.is_open())
    {
        while(getline(inFile,word))
        {
            if(word.length() > 0)
            {
                words.push_back(word);
            }
        }
        inFile.close();
    }
    return words;
}

//Implement this function
vector<string> anagram(string word, vector<string> wordlist)
{
    vector<string> anagramHolder;   //store found anagrams
    
    string item;    //stores item from word list
    
    for(int a = 0; a < wordlist.size(); a++)    //loop to search through every item in word list
    {
        item = wordlist[a];
        
        int wordList = word.length();
        int itemList = item.length();
        
        unordered_map<char,int> z;      //initialize unordered_map
       
        if(wordList != itemList)    //if lengths are different, then they cannot be anagrams
        {
            continue;
        }
        
        for(int i = 0; i < wordList; i++)
        {
            z[word[i]]++;   //increases key values for characters
        }
        
        for(int i = 0; i < itemList; i++)
        {
            if(z.find(item[i]) == z.end())  //if any character was in the word but not the item, they are not an anagram
            {
                break;
            }
            else
            {
                z[item[i]]--;
                if(z[item[i]] == 0) //map will be empty if all characters are zero
                { 
                    z.erase(item[i]);
                }
            }
        }

        if(z.size() == 0) //the original item and word are anagrams if the map is empty
        {
            anagramHolder.push_back(item);
        }    
    } 

  return anagramHolder;
  
}