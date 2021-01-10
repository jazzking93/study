#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

// left, right, up, down
int dx[4] = { 0,0,1,-1 };
int dy[4] = { -1,1,0,0 };

// visit[rotate][row][column]
int visit[4][20][20];

bool chkKey(vector<vector<int>> key, vector<vector<int>> lock) {
    for (int i = 0; i < lock.size(); i++) {
        for (int j = 0; j < lock.size(); j++) {
            if (key[i][j] == 0 && lock[i][j] == 0) {
                return false;
            }
        }
    }
    return true;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    bool answer = true;

    int len_lock = lock.size();
    int len_key = key.size();

    vector<vector<int>> originKey(len_lock, vector<int>(len_lock));
    for (int i = 0; i < len_key; i++) {
        for (int j = 0; j < len_key; j++) {
            originKey[i][j] = key[i][j];
        }
    }

    queue<vector<vector<int>>> q;
    q.push(originKey);
    visit[0][0][0] = 1;
    
    while (q.empty()) {
        int qs = q.size();
        while (qs--) {
            vector<vector<int>> tmpKey = q.front();
            q.pop();

            // check
            if (chkKey(tmpKey, lock)) {
                return true;
            }

            // 2중 for문으로 1. rotate, 2. row, column add 방식 구현.

        }
    }

    return false;
}


int main() {
    vector<vector<int>> key = { {0,0,0},{1,0,0},{0,1,1} };
    vector<vector<int>> lock = { {1,1,1},{1,1,0},{1,0,1} };

    cout << solution(key, lock) << endl;

    return 0;
}
