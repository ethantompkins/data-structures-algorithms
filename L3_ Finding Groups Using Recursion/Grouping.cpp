/*
 * Name: Ethan Tompkins
 * Date Submitted: 9/22/20
 * Lab Section:004
 * Assignment Name: Lab 3 finding groups using recursion
 */

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

//Represents an occupied square in the grid
//Do not modify the GridSquare class or its member functions
class GridSquare
{
    private:
        int row, col;
    public:
        GridSquare() : row(0), col(0) {} //Default constructor, (0,0) square
        GridSquare(int r, int c) : row(r), col(c) {} //(r,c) square
        //Compare with == operator, used in test cases
        bool operator== (const GridSquare r) const
        {
            if ((row == r.row) && (col == r.col))
            {
                return true;
            }
            return false;
        }
        int getRow() { return row; } //return row value
        int getCol() { return col; } //return column value
        //Output using << operator, used in Grouping::printGroups()
        friend ostream& operator<< (ostream& os, const GridSquare obj);
};

//Function definition for <ostream> << <GridSquare>
ostream& operator<< (ostream& os, const GridSquare obj)
{
    os << "(" << obj.row << "," << obj.col << ")";
    return os;
}

/*
Groups squares in 10x10 grid upon construction
Additional private helper functions may be added
Need to implement the constructor that takes a file name
as well as findGroup
The findGroup function's parameter list may be aranged based
on how the function is implemented
*/
class Grouping
{
    private:
        int matrix[10][10];
        vector<vector<GridSquare>> groups;
    public:
        Grouping() : matrix{},groups() {} //Default constructor, no groups
        Grouping(string fileName); //Implement this function
        void findGroup(int r, int c); //Implement this function (recursive)
        void printGroups() //Displays grid's groups of squares
        {
            for(int g=0; g<groups.size(); g++)
            {
                cout << "Group " << g+1 << ": ";
                for(int s=0; s<groups[g].size(); s++)
                {
                    cout << " " << groups[g][s];
                }
                cout << endl;
            }
        }
        vector<vector<GridSquare>> getGroups() //Needed in unit tests
        {
            return groups;
        }
};

//Implement the (parameterized) constructor and findGroup functions below
Grouping::Grouping(string fileName){
    char chara;
    ifstream file;
    file.open(fileName);
    if(!file.is_open())
        return;
    for(int n = 0; n < 10; n++){
        for(int m = 0; m < 10; m++){
            file >> chara;
            matrix[n][m] = chara;
            if(chara == '.')
                matrix[n][m] = 0;
            if(chara == 'X')
                matrix[n][m] = 1;
        }
    }
    file.close();
    for(int n = 0; n < 10; n++){
        for(int m = 0; m < 10; m++){
            if(matrix[n][m] == 1){
                vector<GridSquare> group;
                groups.push_back(group);
                findGroup(n,m);
            }
        }
    }
}

void Grouping::findGroup(int r, int c){
    int pos = groups.size()-1;
    
    if(matrix[r][c] == 0){
        return;
    }else if(matrix[r][c] == 1){
        matrix[r][c] = 0;
        groups[pos].push_back(GridSquare(r,c));
        if(c == 0 && r == 0){
            findGroup(r,c+1);
            findGroup(r+1,c);
        }else if(c == 0 && r == 9){
            findGroup(r-1,c);
            findGroup(r,c+1);
        }else if(c == 0 && r > 0 && r < 9){
            findGroup(r,c+1);
            findGroup(r+1,c);
            findGroup(r-1,c);
        }else if(c == 9 && r == 0){
            findGroup(r+1,c);
            findGroup(r,c-1);
        }else if(c == 9 && r == 9){
            findGroup(r-1,c);
            findGroup(r,c-1);
        }else if(r == 0 && c > 0 && c < 9){
            findGroup(r+1,c);   
            findGroup(r,c+1);
            findGroup(r,c-1);
        }else if(c == 9 && r > 0 && r < 9){
            findGroup(r+1,c);
            findGroup(r-1,c);
            findGroup(r,c-1);
        }else if(r == 0 && c < 9 && c > 0){
            findGroup(r-1,c);
            findGroup(r,c+1);
            findGroup(r,c-1);
        }else{
            findGroup(r+1,c);
            findGroup(r-1,c);
            findGroup(r,c+1);
            findGroup(r,c-1);
        }
    }
}


//Simple main function to test Grouping
int main()
{
    Grouping input1("input1.txt");
    input1.printGroups();
    
    return 0;
}