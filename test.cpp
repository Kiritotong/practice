#include <bits/stdc++.h>
#define ms(a,b) memset(a,b,sizeof(a));
using namespace std;
typedef long long ll;
const int maxn=35;
//head-tongren//
const int mv[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
int book[maxn][maxn],w_x,w_y;
ll n,m,cs;
char mp[maxn][maxn];
struct tim{
    int x,y;
    int step;
};
int bfs(int s_x,int s_y){
    queue<tim>box;
    box.push(tim{s_x,s_y,0});
    while(!box.empty()){
        tim temp=box.front();
        box.pop();
        temp.step++;
        for(int i=0;i<4;i++){
            int x=temp.x+mv[i][0],y=temp.y+mv[i][1];
            if(x>=0&&x<n&&y>=0&&y<m&&book[x][y]==0&&mp[x][y]!='#'){
                if(mp[x][y]=='E'&&max(abs(x-w_x),abs(y-w_y))>=temp.step) return temp.step;
                if(max(abs(x-w_x),abs(y-w_y))<=temp.step) continue;
                box.push(tim{x,y,temp.step});
                book[x][y]=1;
            }
        }
    }
    return -1;
}
int main()
{
    cin>>cs;
    while(cs--){
        ms(mp,'#');
        cin>>n>>m;
        int s_x,s_y;
        for(int i=0;i<n;i++){
            scanf("%s",mp[i]);
            for(int j=0;j<m;j++){
                if(mp[i][j]=='S') {s_x=i;s_y=j;}
                if(mp[i][j]=='*') {w_x=i;w_y=j;}
            }
        }
        ll res=bfs(s_x,s_y);
        if(res>=0) cout<<res<<endl;
        else cout<<"T_T"<<endl;
        ms(book,0);
    }
    return 0;
}
