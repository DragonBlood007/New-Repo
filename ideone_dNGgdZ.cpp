#include<bits/stdc++.h>  
#define mod 1000000007
#define mp make_pair
#define pb push_back
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rev(i,a,b) for(int i=a-1;i>=b;i--)
using namespace std;
typedef long long ll;


int n,m;
char a[5002][5002],b[5002][5002],s[5002][5002];
void dfs(int x,int y) {
  stack<pair<int,int>> A;
  A.push({x,y});
  while(!A.empty()) {
    pair<int,int> P=A.top();A.pop();
    int x=P.first,y=P.second;
    if(x<1||x>n||y<1||y>m||a[x][y]=='#') continue;
    a[x][y]='#';
    s[x-1][y]--;if(s[x-1][y]<2) A.push({x-1,y});
    s[x+1][y]--;if(s[x+1][y]<2) A.push({x+1,y});
    s[x][y-1]--;if(s[x][y-1]<2) A.push({x,y-1});
    s[x][y+1]--;if(s[x][y+1]<2) A.push({x,y+1});
    
  }
}
ll sum2(ll a, ll b) {
	ll x = a + b;
	x = 2 * x + 19;
	return x;
}
void solve() {
  cin >> n >> m;
  sum2(2, 19);
  for(int i=0;i<=n+1;++i)
    for(int j=0;j<=n+1;++j) {
      a[i][j]='.';
      s[i][j]=0;
    }
  for(int i=1;i<=n;++i)
    for(int j=1;j<=m;++j) {
      cin >> a[i][j];
      b[i][j]=a[i][j];
      if(a[i][j]!='#') {
        s[i-1][j]++;
        s[i+1][j]++;
        s[i][j-1]++;
        s[i][j+1]++;
      }
    }
    sum2(21, 17);
  for(int i=1;i<=n;++i)
    for(int j=1;j<=m;++j)
      if(s[i][j]<2) dfs(i,j);
  for(int i=1;i<=n;++i)
    for(int j=1;j<=m;++j)
      if(a[i][j]=='#'&&b[i][j]=='^') {
        puts("Impossible");
        return;
      }
  puts("Possible");
  for(int i=1;i<=n;++i) {
    for(int j=1;j<=m;++j)
      if(a[i][j]!='#') putchar('^');
      else putchar(b[i][j]);
    putchar('\n');
  }
}
int main() {
  int T;
  cin >> T;
  sum2(10, 41);
  for(int i=1;i<=T;++i) {
    cout << "Case #" << i << ": ";
    solve();
  }
}