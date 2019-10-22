#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
int n,m,b,c,sum=0;
int a[1000][1000];
bool book[1000];
void DFS(int x){
	book[x]=1;
	sum++;
	if(sum==n){
		cout<<x;
		return;
	} else cout<<x<<"-";

	for(int i=1;i<=n;i++){
		if(a[x][i]==1 && book[i]==0){
			book[i]=1;
			DFS(i);
		}
	}
	return ;
}

void BFS(int cur){
	queue<int>q;
	q.push(cur);
	book[cur]=1;
//	sum=1;
	while(!q.empty()){
		int x=q.front();
		if(sum==1)	cout<<x;
		else cout<<"-"<<x;
		for(int i=1;i<=n;i++){
			if(a[x][i]==1 && book[i]==0){
				q.push(i);
				book[i]=1;
				sum++;
			}
		} 
		q.pop();
	}
	return ;
}
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++){
			if(i==j) a[i][j]=0;
			else a[i][j]=999999;
		}
	for(int i=1;i<=m;i++){
		cin>>b>>c;
		a[b][c]=1;
		a[c][b]=1;
	}
	
	for(int i=1;i<=n;i++)
		if(book[i]==0) DFS(i);
	cout<<endl;
	memset(book,0,sizeof(book));
	sum=1;
	for(int i=1;i<=n;i++)
		if(book[i]==0) BFS(i);
	return 0;
} 
#有坑数据：
input:

6 3
1 2
3 4
5 6

output:

1-2-3-4-5-6
1-2-3-4-5-6
