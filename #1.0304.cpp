/* 1655 */
#include <iostream>
#include <queue>
using namespace std;

int main(){
    priority_queue<int, vector<int>, less<int>> maxq;
    priority_queue<int, vector<int>, greater<int>> minq;
    
    int n, v;
    cin >> n;
    
    vector<int> nums;
    for(int i=0;i<n;i++){
        cin >> v;
        nums.push_back(v);
    }
    
    
    for (int i=0;i<n;i++){
        v = nums[i];
        
        if(maxq.size()==0){
            maxq.push(v);
        } else {
            if(maxq.size() > minq.size()){
                minq.push(v);
            } else {
                maxq.push(v);
            }
            if(maxq.top() > minq.top()){
                int tmpMinq = minq.top(), tmpMaxq = maxq.top();
                minq.pop(); maxq.pop();
                minq.push(tmpMaxq); maxq.push(tmpMinq);
            }
        }
        cout << maxq.top() << "\n";
    }
    
    
}
