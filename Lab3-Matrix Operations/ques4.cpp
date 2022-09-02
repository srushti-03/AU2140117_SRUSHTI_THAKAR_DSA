//AU2140117 SRUSHTI THAKAR DATA STRUCTURES AND ALGORITHMS lab 3 Matrices

//ques-4: game of life( follow 3 rules: birth rule, death rule, survival rule):

#include <bits/stdc++.h>
using namespace std;

class LifeGrid{
    public:
    int rows;
    int cols;
    int defaultValue;
    map<pair<int,int>,int> m1;

    LifeGrid(int r, int c)
    {
        rows = r;
        cols = c;
    }

    int numRows() {
         return this->rows;   //returns number of rows
    }
    int numCols() {
         return this->cols;
          }                          // returns number of columns

    void configureCell(vector<pair<int,int>> v){
        for (int i = 0; i < v.size(); i++)
        {
            m1[v[i]]=1;
        }        
    }

    void clearCell(int rows, int cols){
        if(rows>=0 && cols>=0 && rows<numRows() && cols<numCols()){
            m1[{rows,cols}] = 0;
        }else{
            throw invalid_argument("Index out of bound error");
        }
    }

    void setCell(int rows, int cols){
        if(rows>=0 && cols>=0 && rows<numRows() && cols<numCols()){
        }else{
            throw invalid_argument("Index out of bound error");
        }
    }
    
    bool isLiveCell(int rows, int cols){
        if(rows>=0 && cols>=0 && rows<numRows() && cols<numCols()){
            if(m1[{rows,cols}]){
                return true;
            }else{
                return false;
            }
        }else{
            throw invalid_argument("Index out of bound error");
        }
    }

    int numOfLiveNeighbors(int i, int j){
        if(i>=0 && j>=0 && i<numRows() && j<numCols()){
            int counter = 0;
            vector<pair<int,int>> n{{i+1, j}, {i+1,j+1}, {i+1, j-1},{i-1, j}, {i-1, j+1}, {i-1,j-1},{i,j+1},{i,j-1}};
            for(auto itr: n){
                if(isLiveCell(itr.first, itr.second)) counter++; 
            }
            return counter;
        }else{
            throw invalid_argument("Index out of bound error");
        }        
    }

};

int main(){
    LifeGrid obj(5,5);
    obj.configureCell({{1,1},{2,1},{3,4}});
    obj.setCell(3,3);
    if(obj.isLiveCell(1,3)){
        cout<<"cell 1,3 is alive."<<endl;
    }else{
        cout<<"cell 1,3  is dead."<<endl;
    }
    cout<<"The number of alive neighbors of 4,2 is: "<<obj.numOfLiveNeighbors(1,1)<<endl;

    return 0;
}



// output:

// cell 1,3  is dead.
// The number of alive neighbors of 4,2 is: 1