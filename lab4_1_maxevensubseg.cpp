//C++ 
#include <bits/stdc++.h> 

using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    vector<long long> chan(n);
    vector<long long> le(n);
    for(int i = 0;i<n;i++){
        cin >> a[i];
        chan[i] = LONG_MIN;
        le[i]= LONG_MIN;
    }

    if(a[0] %2 ==0){chan[0]= a[0];}
    else{
        le[0]= a[0];
    }
    for(int i = 1; i<n;i++){
        if(a[i] %2 ==0){
            if(chan[i-1]!= LONG_MIN){
                if(chan[i-1]> 0){
                    chan[i]= a[i]+chan[i-1];
                }
                else {chan[i]=a[i];}
            }else {chan[i]=a[i];}
            if(le[i-1]!= LONG_MIN){
                le[i]= a[i]+le[i-1];
            }
        }
        
        else{
            if(le[i-1]!= LONG_MIN){
                if(le[i-1]> 0){
                    chan[i]= a[i]+le[i-1];
                }
                else le[i]=a[i];
            }
            else {le[i]=a[i];}
            if(chan[i-1]!= LONG_MIN){
                le[i]= a[i]+chan[i-1];
            }
        }
    }
    long long ans = LONG_MIN;
    for(int i =0; i<n; i++){
        if((chan[i] != LONG_MIN) && (ans < chan[i])) ans = chan[i];
    }
    if(ans == LONG_MIN){
        cout << "NOT_FOUND";
    }
    else{cout << ans;}
    return 0;
}

