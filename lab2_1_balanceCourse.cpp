#include<bits/stdc++.h>
using namespace std;
const int N = 50;
const int oo = 1e9;
int m,n;
int Optload = oo;
vector<int>T[N]; //T[i] tap gvien day duoc mon i , load[t] là t?i tr?ng c?a teacher i, x[i] là giáo viên d?y môn i
int load[N]={};
int x[N] = {};
bool conflict[N][N] = {};

void input()
    {
        cin>>m>>n;
        int k;
        for (int t=1;t<=m;t++)
        {
            cin>>k;
            for (int teacher=0;teacher<k;teacher++)
            {
                int course;
                cin>>course;
                T[course].push_back(t);
            }
        }
        int u;
        cin>>u;
        for (int i=0;i<u;i++)
        {
            int x1,x2;
            cin>>x1>>x2;
            conflict[x1][x2]=conflict[x2][x1] = true;
        }
    }
void update()
{
    int maxload = -1;
    for (int i=1;i<=m;i++)
    {
        maxload = max(maxload,load[i]);
    }
    if (maxload <Optload)
    {
        Optload = maxload;
    }
}
bool check(int t, int k)
    {
        if (k==1)
            return true;
        for (int i=1;i<k;i++)
        {
            if  (x[i]==t && conflict[i][k])
                return false;
        }
        return true;
    }
void solve(int k)
    {
        if (k==n+1)
        {
            update();
        }
        for (int t:T[k])
        {
            if (check (t,k) && load[t]<Optload)
            {
                x[k]=t;
                load[t]++;

                solve(k+1);
                load[t]--;
                x[k] =0;


                }
            }
        }

int main()
{
    input();
    solve(1);
    cout<<Optload<<"\n";
}

