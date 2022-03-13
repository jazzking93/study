/* 20058 */
#include <iostream>
#include <vector>
using namespace std;

struct info {
    int x,y,per;
};

int n;
int map[500][500];

int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};

info dust[4][9] = {
    {{-2,0,5},{-1,-1,10},{-1,1,10},{0,-2,2},{0,-1,7},{0,1,7},{0,2,2},{1,-1,1},{1,1,1}},
    {{0,2,5},{-1,1,10},{1,1,10},{-1,0,7},{1,0,7},{-2,0,2},{2,0,2},{-1,-1,1},{1,-1,1}},
    {{2,0,5},{1,-1,10},{1,1,10},{0,-1,7},{0,1,7},{0,-2,2},{0,2,2},{-1,-1,1},{-1,1,1}},
    {{0,-2,5},{-1,-1,10},{1,-1,10},{-1,0,7},{1,0,7},{-2,0,2},{2,0,2},{-1,1,1},{1,1,1}}
};

bool chk(int x, int y){
    return x>=0 && x<n && y>=0 && y<n;
}

int solve(int center){
    int tx = center, ty = center;
    int origin = 1;
    int dir = 3;
    int result = 0;
    
    int flg=0, count=origin;
    int outflg = 1;
    
    while(outflg){
        while(count--){
            tx += dx[dir]; ty += dy[dir];
            // dust
            int Dustorigin = map[tx][ty];
            for(int i=0;i<9;i++){
                int cx = tx + dust[dir][i].x, cy = ty + dust[dir][i].y, cdust = Dustorigin*dust[dir][i].per/100;
                if(chk(cx, cy)){
                    map[cx][cy] += cdust;
                } else {
                    result += cdust;
                }
               map[tx][ty] -= cdust;
            }
            if(chk(tx+dx[dir], ty+dy[dir])){
                map[tx+dx[dir]][ty+dy[dir]] += map[tx][ty];
            } else {
                result += map[tx][ty];
            }
            map[tx][ty] = 0;
            
            // out
            if(tx==0 && ty==0){
                outflg=0; break;
            }
        }
        
        if(flg+1 == 2) { flg = 0; origin++; }
        else           { flg += 1; }
        if(dir-1 < 0)  { dir = 3; }
        else           { dir -= 1; }
        count = origin;
    } // tx == ty == 0
    
    return result;
}

int main(){
    cin >> n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> map[i][j];
        }
    }
    
    int result = solve(n/2);
    cout << result << endl;
    
    return 0;
}
