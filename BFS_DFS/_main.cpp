#include "_helper.h"

using namespace std;


void printMatrix(vector<vector<int>>& mat){
    int R = mat.size();
    int C = mat[0].size();

    for(int i = 0; i< R; i++){
        for(int j = 0; j< C; j++){
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
    return;
}

int main(){


    vector<vector<char>> grid = {{'1','1','0','0','0'},
                                 {'1','1','0','0','0'},
                                 {'0','0','1','0','0'},
                                 {'0','0','0','1','1'}};

    cout << "Num Islands = " << numIslandsBFS(grid) << endl;

    // cout << "Num Islands = " << numIslandsBFS(grid) << endl;

    vector<vector<int>> grid2 = {{ 1,  1,  0,  0 , 0 },
                                 { 1 , 1 , 0 , 0 , 0 },
                                 { 0 , 0 , 1 , 0 , 0 },
                                 { 0 , 0 , 0 , 1 , 1 }};

    vector<vector<int>> gridZ1{{1, 1, 1, 1, 1},
                             {1, 1, 1, 1, 1},
                             {1, 1, 1, 1, 1},
                             {1, 1, 1, 1, 1}};

    // cout << "Max Area Islands = " << maxAreaOfIsland(grid2) << endl;
    cout << "Zombie Matrix " << zombieMatrix(grid2) << endl;
    cout << "Zombie Matrix " << zombieMatrix(gridZ1) << endl;  

    vector<vector<char>> grid3 = {{'O', 'O', 'O', 'O'},
                                  {'D', 'O', 'D', 'O'},
                                  {'O', 'O', 'O', 'D'},
                                  {'D', 'D', 'O', 'X'}};

    // cout << "Treasure Isalnd = " << treasure_island(grid3) << endl;


    cout << "Treasure Isalnd = " << treasure_island_BFS(grid3) << endl;

    cout << "II" << endl;
    vector<vector<char>> grid4 = {{'S', 'O', 'O', 'S', 'S'},
                                  {'D', 'O', 'D', 'O', 'D'},
                                  {'O', 'O', 'O', 'O', 'X'},
                                  {'X', 'D', 'D', 'O', 'O'},
                                  {'X', 'D', 'D', 'D', 'O'}};
    // cout << "Treasure Isalnd II = " << treasure_island_II(grid4) << endl;


    vector<vector<int>> edges = {{1, 0}, {0, 2}, {2, 1}, {0,3}, {3,4}};

    // critical_connections(5, edges);

    vector<vector<int>> test1 = {{1, 2},{1, 3},{3, 4},{1, 4},{4, 5}};
    auto result = critConnections(5,test1);
    for(auto x:result)
    {
        cout<<x[0]<<" "<<x[1]<<endl;
    }
    result = {{}};
    
    vector<vector<int>> test2 = {{1, 2}, {1, 3}, {2, 3}, {2, 4}, {2, 5}, {4, 6}, {5, 6}};
    result = critConnections(6,test2);
    for(auto x:result)
    {
        cout<<x[0]<<" "<<x[1]<<endl;
    }
    
    cout<<"\n";
    
    vector<vector<int>> test3 = {{1, 2}, {1, 3}, {2, 3}, {3, 4}, {3, 6}, {4, 5}, {6, 7}, {6, 9}, {7, 8}, {8, 9}};
    result = critConnections(9,test3);
    for(auto x:result)
    {
        cout<<x[0]<<" "<<x[1]<<endl;
    }

    vector<vector<int> > grid5 = {{ 1, 1, 0, 1, 1 }, 
                                  { 1, 0, 0, 0, 0 }, 
                                  { 0, 0, 0, 0, 1 }, 
                                  { 1, 1, 0, 1, 1 } }; 
  
    cout << "Number of distinct islands is " << countDistinctIslands(grid5);
               

}