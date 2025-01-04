//C++ 
#include <bits/stdc++.h> 
#define max_n 1000001
using namespace std;
int n;
pair<int,int> p[max_n];
pair<int,int> q[max_n];

bool check (pair<int,int> p, pair<int,int> q){
    if(p.first > q.second) return true;
    return false;
}

int main() 
{ 
    cin >> n;
    for(int i= 0; i<n;i++){
        cin >> p[i].first >> p[i].second;
    }
    auto comp = [] (pair<int,int> x, pair<int,int> y) {
        return  x.second < y.second;
    };
    sort(p, p+n, comp);
    q[0] = p[0];
    int res =1;
    for(int i =1; i<n;i++){
        
        if(check(p[i],q[res-1])){
            q[res]= p[i];
            res++;
        }
    }
    cout << res;
}

