#include<bits/stdc++.h>
#include "function.h"

using namespace std ;
const int MAX = 3 ; 
const vector<vector<pair<int,int>>> T = {
                                            {
                                                {1,0},{2,0}
                                            }
                                            ,
                                            {
                                                {0,1},{0,2}
                                            }
                                            ,
                                            {
                                                {1,1},{2,2}
                                            }
                                        }; 
bool inside(int x ,int y)
{
    return 1 <=x&&x<=MAX && 1<=y&&y<=MAX ; 
}
int a[MAX+5][MAX+5] ;
int check()
{
    for(int i =1;i<=3;i++)
    {
        for(int j=1;j<=3;j++)if(a[i][j])
        {
            for(auto t : T)
            {
                bool ok = 1 ; 
                for(auto [u,v]:t)
                {   
                    ok&=(a[i][j]==a[i+u][j+v]) ; 
                }
                if(ok)
                {
                    return a[i][j] ; 
                }
            }
        }
    }
    return 0 ; 
}

signed main()
{
    for(int i=1;i<=3;i++)
    {
        for(int j=1;j<=3;j++)
        {
            cout<<" . "; 
        }
        cout<<endl; 
    }
    int turn = 0 ; 
    int z = 0 ;
    while(check()==0)
    {
        ++z ; 
        if(z==10)
        {
            cout<<"DRAW"<<endl; 
            return  0 ; 
        }
        turn^=1 ; 
        if(turn==1)
        {
            int x, y; 
            while(1)
            {
                cout<<"YOUR MOVE : ";
                cin>>x>>y ;
                cout<<endl;
                if(!inside(x,y)||a[x][y])
                {
                    cout<<"illegal move "<<endl; 
                }
                else break;
            }
            a[x][y] = 1 ; 
        }
        else
        {
            vector<pair<int,int>>pos ; 
            FOR(i,1,MAX)FOR(j,1,MAX)if(a[i][j]==0)
            {
                pos.push_back(make_pair(i,j)) ; 
            }
            srand(time(0)) ; 
            random_shuffle(all(pos)) ;
            cout<<"BOT MOVE : "; 
            cout<<pos[0].first<<" "<<pos[0].second<<endl; 
            a[pos[0].first][pos[0].second] = -1 ; 
        }
        FOR(i,1,MAX)
        {
            FOR(j,1,MAX)
            {
                if(a[i][j]==0)
                {
                    cout<<" . ";
                }
                else if(a[i][j]==-1)cout<<" X " ;
                else cout<<" O " ;
            }
            cout<<endl; 
        }
    }
    if(check()==-1)cout<<"BOT WIN "<<endl; 
    else cout<<"YOU WIN "<<endl; 
    return 0 ; 
}
