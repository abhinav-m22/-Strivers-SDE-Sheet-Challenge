#include <bits/stdc++.h> 
using namespace std;
bool wordBreak(vector < string > & arr, int n, string & target) {
    int i = 0 ;
    while(i<n){
        if(target.find(arr[i])!=target.npos){
            target.erase(target.find(arr[i]) , arr[i].size());
        }
        else{
            i++;
        }
    }
    if(target.size()==0) return 1;
    else return 0;
}