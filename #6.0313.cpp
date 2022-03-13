#include <iostream>
#include <queue>
#include <cmath>
using namespace std;

int N,Q;
int map[64][64];
int visit[64][64];

int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

int sz;

void rotateMap(int x, int y, int sz){
    vector<vector<int>> tmpMap(sz, vector<int>(sz,0));
    vector<vector<int>> tmpMap2(sz, vector<int>(sz,0));
    
    for(int i=x;i<x+sz;i++){
        for(int j=y;j<y+sz;j++){
            tmpMap[i-x][j-y] = map[i][j];
        }
    }
    
    for(int i=0;i<sz;i++){
        for(int j=0;j<sz;j++){
            tmpMap2[j][sz-i-1] = tmpMap[i][j];
        }
    }
    
    for(int i=0;i<sz;i++){
        for(int j=0;j<sz;j++){
            map[i+x][j+y] = tmpMap2[i][j];
        }
    }
}

bool chk(int x, int y){
    return x>=0 && x<sz && y>=0 && y<sz;
}

void melt_ice(){
    vector<vector<int>> tmpMap(sz, vector<int>(sz,0));
    for(int i=0;i<sz;i++){
        for(int j=0;j<sz;j++){
            int count = 0;
            for(int z=0;z<4;z++){
                int x = i + dx[z], y = j + dy[z];
                if(chk(x,y) && map[x][y]>0){
                    count++;
                }
            }
            if(count<3 && map[i][j]>0){
                tmpMap[i][j] = map[i][j]-1;
            } else{
                tmpMap[i][j] = map[i][j];
            }
        }
    }
    
    for(int i=0;i<sz;i++){
        for(int j=0;j<sz;j++){
            map[i][j] = tmpMap[i][j];
        }
    }
}

void solve(int L){
    int partsz = pow(2,L);
    for(int i=0;i<sz;i+=partsz){
        for(int j=0;j<sz;j+=partsz){
            rotateMap(i, j, partsz);
        }
    }
    
    melt_ice();
}

int bfs(int rx, int ry){
    int result = 0;
    queue<pair<int,int>> q;
    visit[rx][ry] = 0;
    q.push({rx, ry});
    
    while(!q.empty()){
        size_t qs = q.size();
        while(qs--){
            int x = q.front().first, y = q.front().second;
            q.pop();
            
            for(int i=0;i<4;i++){
                int cx = x + dx[i], cy = y + dy[i];
                if(chk(cx,cy) && visit[cx][cy]==0 && map[cx][cy]>0){
                    visit[cx][cy] = 1;
                    q.push({cx,cy});
                    result++;
                }
            }
            
        }
    }
    
    return result;
}

int calc_ice(){
    int result = 0;
    for(int i=0;i<sz;i++){
        for(int j=0;j<sz;j++){
            result += map[i][j];
        }
    }
    return result;
}

int calc_mass() {
    int mass = 0;
    for(int i=0;i<sz;i++){
        for(int j=0;j<sz;j++){
            if (visit[i][j] == 0){
                mass = max(mass, bfs(i,j));
            }
        }
    }
    return mass;
}

int main(){
    cin >> N >> Q;
    sz = pow(2, N);
    
    for (int i=0;i<sz;i++){
        for(int j=0;j<sz;j++){
            cin >> map[i][j];
        }
    }
    
    for(int i=0;i<Q;i++){
        int L;
        cin >> L;
        solve(L);
    }
    
    cout << calc_ice() << endl;
    cout << calc_mass() << endl;
    
    return 0;
}


