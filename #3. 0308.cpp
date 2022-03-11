/* 14002 */

#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int arr[1000];
int arr2[1000];

int main(){
    int n;
    
    cin >> n;
    
    int maxlength=0, maxidx=0;
    for(int i=0;i<n;i++){
        cin >> arr[i];
        
        int m = 0;
        for(int j=0;j<=i;j++){
            if(arr[i] > arr[j]){
                m = max(arr2[j], m);
            }
        }
        arr2[i] = m + 1;
        
        if(arr2[i] > maxlength){
            maxlength = arr2[i];
            maxidx = i;
        }
    }
    
    cout << maxlength << endl;
    
    vector<int> arr3;
    int tmplength = maxlength;
    for(int i=maxidx;i>=0;i--){
        if(arr2[i] == tmplength){
            arr3.push_back(arr[i]);
            tmplength--;
        }
    }
    
    for(int i=arr3.size()-1;i>=0;i--){
        cout << arr3[i] << " ";
    }
    cout << endl;
}

