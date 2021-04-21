/*
 * Name: Ethan Tompkins 
 * Date Submitted: 10/22/20
 * Lab Section:004
 * Assignment Name Finding the closest pair of points
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <cmath>

using namespace std;

struct point
{
    double x;
    double y;
};

double getDistance(point p1, point p2){
    double result = sqrt(pow((p2.x-p1.x),2)+pow((p2.y-p1.y),2));
    return result;
}

double closestPair(string filename)
{
    point Pt;
    int numPoints, xposition, yposition, a;
    double xp, yp, interval;
    string line, temp, stx, sty;
    fstream myFile;
    
    myFile.open(filename);
    if(!myFile.is_open())
    return 0;
    
    getline(myFile, temp);
    numPoints = stoi(temp);
    
    a = sqrt(numPoints);
    
    interval = (1.0 / a);
    
    vector<vector<vector<point> > > grid(a, vector<vector<point> > (a));
    
    for(int i = 0; i < numPoints; i++)
    {
        myFile >> stx >> sty;
        xp = stod(stx);
        yp = stod(sty);
        
        xposition = xp/interval;
        yposition = yp/interval;
        
        Pt.x = xp;
        Pt.y = yp;
        
        grid[xposition][yposition].push_back(Pt);
    }
    
    double currentMin = 5.0;
    double d;
    int i, j, k, l;
    

    for(i = 0; i < a; i++)
    {
        for(j = 0; j < a; j++)
        {
            for(k = 0; k < grid[i][j].size(); k++)
            {
                point p1 = grid[i][j][k];
                
                for(l = k+1; l < grid[i][j].size(); l++)
                {
                    point p2 = grid[i][j][l];
                    d = getDistance(p1, p2);
                    if(d < currentMin)
                    currentMin = d;
                }
            if(i+1 < a)
            {
                for(l = 0; l < grid[i+1][j].size(); l++)
                {
                    point p2 = grid[i+1][j][l];
                    d = getDistance(p1, p2);
                    if(d < currentMin)
                    currentMin = d;
                }
            }
           
            if(j+1 < a)
            {
                for(l = 0; l < grid[i][j+1].size(); l++)
                {
                    point p2 = grid[i][j+1][l];
                    d = getDistance(p1, p2);
                    if(d < currentMin)
                    currentMin = d;
                }
            }

            if(i+1 < a && j+1 < a)
            {
                for(l = 0; l < grid[i+1][j+1].size(); l++)
                {
                    point p2 = grid[i+1][j+1][l];
                    d = getDistance(p1, p2);
                    if(d < currentMin)
                    currentMin = d;
                }
            }
            
            if(i+1 < a && j-1 >= 0)
            {
                for(l = 0; l < grid[i+1][j-1].size(); l++)
                {
                    point p2 = grid[i+1][j-1][l];
                    d = getDistance(p1, p2);
                    if(d < currentMin)
                    currentMin = d;
                }
            }
        }
    }
}

    myFile.close();

    return currentMin;
}

int main()
{
    double min;
    string filename;
    cout << "File with list of points within unit square: ";
    cin >> filename;
    min = closestPair(filename);
    cout << setprecision(16);
    cout << "Distance between closest pair of points: " << min << endl;
    return 0;
}