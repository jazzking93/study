/* 6087 */
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int w, h;
char map[100][100];
int visit[100][100];

int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};

bool chk(int x ,int y){
    return x >=0 && x < h && y >= 0 && y < w;
}

int bfs(vector<pair<int,int> > raser){
    queue<pair<pair<int,int>, pair<int, int>> > q;
    q.push({{raser[0].first, raser[0].second}, {-1, 0}});
    
    visit[raser[0].first][raser[0].second] = 0;
    
    while(!q.empty()){
        size_t qs =q.size();
        while(qs--){
            int x = q.front().first.first, y = q.front().first.second;
            int exDir = q.front().second.first, dirCount = q.front().second.second;
            q.pop();
            
            for(int i=0;i<4;i++){
                int cx = x+dx[i], cy = y+dy[i];
                int tmpCount = dirCount;
                if(chk(cx,cy) && map[cx][cy] != '*'){
                    if (exDir == -1){
                        q.push({{cx, cy},{i,0}});
                        visit[cx][cy] = 0;
                    } else {
                        if(i != exDir) tmpCount++;
                        if(visit[cx][cy] >= tmpCount){
                            visit[cx][cy] = tmpCount;
                            q.push({{cx,cy}, {i, tmpCount}});
                        }
                    }
                }
            }
        }
    }
    
    return visit[raser[1].first][raser[1].second];
}

int main() {
    cin >> w >> h;
    
    vector<pair<int,int>> raser;
    
    for (int i=0;i<h;i++){
        for (int j=0;j<w; j++){
            cin >> map[i][j];
            if(map[i][j] == 'C'){
                raser.push_back({i, j});
            }
            visit[i][j] = 10000;
        }
    }
    
    cout << bfs(raser) << endl;
    
    return 0;
}
