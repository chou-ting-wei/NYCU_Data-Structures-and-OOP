#include <iostream>
#include <vector>
using namespace std;

int m, n; //m,n represent the size of the universe.
int res = 0; //res is the number of planets in the universe.
vector<vector<int>> universe(15, vector<int>(15, 0));
vector<int> collectingArea; //collectingArea is used to collect the area of every planet.
int used[15][15];


int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int dfs(int x, int y){
    //Hint : Use DFS here to calculate the area of every planet.
    int ret = 0;
    if(!used[x][y]){
        used[x][y] = 1;
        if(universe[x][y]){
            ret ++;
            for(int i = 0; i < 4; i ++){
                if(x + dx[i] >= 0 && x + dx[i] < m && y + dy[i] >= 0 && y + dy[i] < n){
                    ret += dfs(x + dx[i], y + dy[i]);
                }
            }
        }
    }
    return ret;
}

int partition(int low, int high){
    int pivot = collectingArea[high];
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++) {
        if (collectingArea[j] < pivot) {
            i++;
            swap(collectingArea[i], collectingArea[j]);
        }
    }
    swap(collectingArea[i + 1], collectingArea[high]);
    return (i + 1);
}

void quickSort(int low, int high){
    if (low < high) {
        int pi = partition(low, high);
        quickSort(low, pi - 1);
        quickSort(pi + 1, high);
    }
}

int main(){
    cin >> m >> n;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            cin >> universe[i][j];
        }
    }
    
      //TO-DO
    for(int i = 0; i < m; i ++){
        for(int j = 0; j < n; j++){
            int k = dfs(i, j);
            if(k) collectingArea.emplace_back(k);
        }
    }

    //TO-DO : Use the quickSort function you wrote to sort the vector collectingArea.
    quickSort(0, collectingArea.size() - 1);
    res = collectingArea.size();

    cout << "The total number of planets is : " << res << endl;
    cout << "The areas of the planets in non-decreasing order are : ";
    for(int area : collectingArea){
        cout << area << " ";
    }
}