/*
 * Name: Ethan Tompkins 
 * Date Submitted: 11/15/20
 * Lab Section: 004
 * Assignment Name: Using Recursion to Solve the N-Queens Problem
 */

#include <iostream>
#include <vector>

using namespace std;

bool isSolution(const vector<int>&, int S);

bool possibilities(const vector<int>&, int row, int S, vector<int>&);

void makeSolutions(vector<int>&, int row, int S);

bool isSafe(const vector<int>&, int row, int col, int S);


vector <int> solutions;

bool isSolution(const vector<int>& queens, int S)
{ 
    return queens.size() == S;
}

bool possibilities(const vector<int>& queens, int row, int S, vector<int>& candidates)
{
    for(int a = 0; a < S; a++)
    {
        if(isSafe(queens, row, a, S))
        {
            candidates.push_back(a);
        }
    }
    return candidates.size() > 0;
}

void makeSolutions(vector<int>& queens, int row, int S)
{
    if(isSolution(queens, S))
    {
        solutions.push_back(1);
    }
    else
    {
        vector<int> candidates;
        
        if(possibilities(queens, row, S, candidates))
        {
            for(int a = 0; a < candidates.size(); a++)
            {
                queens.push_back(candidates[a]);
                makeSolutions(queens, row+1, S);
                queens.pop_back();
            }
        }
    }
}

bool isSafe(const vector<int>& queens, int row, int column, int S)
{
    for(int a = 0; a < queens.size(); ++a)
    {
        if(abs(a - row) == abs(queens[a] - column))
        return false;
        if(a == row || queens[a] == column)
        return false;
    }
    return true;
}

int nQueens(int s)
{
   vector<int> queens;
   makeSolutions(queens, 0, s);
   return solutions.size();

}

int main()
{
    cout << "1: " << nQueens(1) << endl;
    cout << "2: " << nQueens(2) << endl;
    cout << "3: " << nQueens(3) << endl;
    cout << "4: " << nQueens(4) << endl;
    cout << "5: " << nQueens(5) << endl;
    cout << "6: " << nQueens(6) << endl;
    cout << "7: " << nQueens(7) << endl;
    cout << "8: " << nQueens(8) << endl;
    cout << "9: " << nQueens(9) << endl;
    cout << "10: " << nQueens(10) << endl;
    cout << "11: " << nQueens(11) << endl;
    cout << "12: " << nQueens(12) << endl;
    return 0;
}