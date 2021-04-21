#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

vector<string> V; //words from wordlist05.txt
//Global variables for bfs distance, bfs predecessor, and neighboring nodes
//Should be unordered_map type

unordered_map<string, string> pred;

unordered_map<string, bool> visited;

unordered_map<string, vector<string>> nbrs;

unordered_map<string, int> dist;

int path_finder(string, string, vector<string>&);

void build_graph();

//Implement breadth-first search, refer to Lab 10

void wordLadder(string s, string t, int &steps, vector<string> &p)
{
  build_graph();
  
  queue<string> visit;
  visit.push(s);
  visited[s] = true;
  dist[s] = true;
  
  while(!visit.empty())
  {
      string currentNode = visit.front();
      visit.pop();
      for(string a : nbrs[currentNode])
          if(!visited[a])
          {
              pred[a] = currentNode;
              dist[a] = 1 + dist[currentNode];
              visited[a] = true;
              visit.push(a);
          }
  }
  
  steps = path_finder(s, t, p);
}

int path_finder(string start, string end, vector<string>&path)
{
    if(pred.find(end) == pred.end())
        return 0;
    if(start.compare(end) != 0)
    {
        int step = 1 + path_finder(start, pred[end], path);
        path.push_back(end);
        return step;
    }
    else{
        path.push_back(end);
        return 0;
    }
}

void build_graph(void)
{
    ifstream word_file("wordlist05.txt");
    string current_word;
    
    while(word_file >> current_word)
        V.push_back(current_word);
        
    for(auto word : V)
    {
        for(int p = 0; p < word.length(); p++)
        {
            for(char letter = 'a'; letter <= 'z'; letter++)
            {
                if(letter == word.at(p))
                    continue;
                
                string current = word;
                current.at(p) = letter;
                nbrs[word].push_back(current);
            }
        }
    }
}

int main(void)
{
  int steps = 0;
  string s, t;
  vector<string> path;
  
  cout << "Source: ";
  cin >> s;

  cout << "Target: ";
  cin >> t;

  wordLadder(s, t, steps, path);

  if (steps == 0)
  {
      cout << "No path!\n";
  }
  else
  {
      cout << "Steps: " << steps << "\n\n";
      for (int i=0; i<path.size(); i++)
      {
          cout << path[i] << endl;
      }
  }
  return 0;
}
