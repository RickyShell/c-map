#include<iostream>
using namespace std;
int g[10001][10001],path[10001];
int n,k,t=0;
void dfs(int i) {
	if(t>k) exit(0);
	for(int j=1; j<=n; j++) {
		if(g[i][j]) {
			path[t++]=i;
			g[i][j]=g[j][i]=0;
			dfs(j);
			g[i][j]=g[j][i]=1;
			t--;
		}
	}
	return;
}
int main() {
	cin>>n>>k;
	for(int i=1; i<=k; i++) {
		int x,y;
		cin>>x>>y;
		g[x][y]=1;
		//g[y][x]=1;
	}
	for(int i=1; i<=n; i++) {
		int s=0;
		for(int j=1; j<=n; j++) {
			if(g[i][j]==1) s++;
		}
		if(s%2==1) {
			cout<<"no circle"<<endl;
			return 0;
		}
	}
	cout<<"circle";
//	dfs(1);
//	cout<<"1 ";
//	for(int i=k-1; i>=0; i--) cout<<path[i]<<" ";
//	cout<<1;
	return 0;
}
