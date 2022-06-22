// Amazon Coding Challenge
// Author: Aarshi Dwivedi
///////////////////////////////////
// Starting point:  s
// Delivery point:  d
// Feasible path:   *
// Obstacles:       0
//////////////////////////////////

#include <iostream>
#include <stdlib.h>
#include <string>
#include <algorithm>
#include <queue>
#include <time.h>

using namespace std;
 
#define N 10
#define M 10
 
// Pos for current location and distance from start
class Pos {
public:
    int row, col, dist;
    Pos(int x, int y, int w)
        : row(x), col(y), dist(w)
    {
    }
};
 
int minDistance(char grid[N][M])
{
    Pos source(0, 0, 0);
 
    // To keep track of visited Positions. 
    // Marking obstacle cells as visited.
    
    bool visited[N][M];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++)
        {
            if (grid[i][j] == '0')
                visited[i][j] = true;
            else
                visited[i][j] = false;
 
            // Finding source
            if (grid[i][j] == 's')
            {
               source.row = i;
               source.col = j;
            }
        }
    }
 
    // applying BFS on matrix cells beginning from starting point
    
    queue<Pos> q;
    q.push(source);
    visited[source.row][source.col] = true;
    while (!q.empty()) {
        Pos p = q.front();
        q.pop();
 
        // Destination found;
        if (grid[p.row][p.col] == 'd')
            return p.dist;
 
        // moving up
        if (p.row - 1 >= 0 &&
            visited[p.row - 1][p.col] == false) {
            q.push(Pos(p.row - 1, p.col, p.dist + 1));
            visited[p.row - 1][p.col] = true;
        }
 
        // moving down
        if (p.row + 1 < N &&
            visited[p.row + 1][p.col] == false) {
            q.push(Pos(p.row + 1, p.col, p.dist + 1));
            visited[p.row + 1][p.col] = true;
        }
 
        // moving left
        if (p.col - 1 >= 0 &&
            visited[p.row][p.col - 1] == false) {
            q.push(Pos(p.row, p.col - 1, p.dist + 1));
            visited[p.row][p.col - 1] = true;
        }
 
         // moving right
        if (p.col + 1 < M &&
            visited[p.row][p.col + 1] == false) {
            q.push(Pos(p.row, p.col + 1, p.dist + 1));
            visited[p.row][p.col + 1] = true;
        }
        
        // moving diagonal
        if (p.col + 1 < M && p.row + 1 < N && 
            visited[p.row+1][p.col + 1] == false) {
            q.push(Pos(p.row + 1, p.col + 1, p.dist + 1));
            visited[p.row + 1][p.col + 1] = true;
        }
    }
    return -1;
}
 
// Main
int main()
{
    char grid[N][M]; 
    int i,j,a,b,OBS=0;
    for(i = 0; i < 10; i++)
            for(j = 0; j<10; j++){
                grid[i][j]='*';
                grid[0][0]='s';
                grid[9][9]='d';
                grid[9][7]='0';
                grid[8][7]='0';
                grid[6][7]='0';
                grid[6][8]='0';}
    
   
    
    //randomising obstacles
    do{
        a=rand() % 10;
        b=rand() % 10;
        for(i=0;i<10;i++){
            for(j=0;j<10;j++){
                if((grid[a][b]!='0') || (grid[a][b]!='s') || (grid[a][b]!='d')){
                    grid[a][b]='0';}}
            }
        OBS++; 
        srand(time(NULL));
        }while(OBS<20);
    
     for(i=0;i<10;i++){
        for(j=0;j<10;j++){
        cout<<grid[i][j]<<"  ";}
    cout<<endl;}
 
    cout << minDistance(grid);
    return 0;
}
