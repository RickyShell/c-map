
#include<iostream>
#include<cstring>
using namespace std;
#define MAXV 1001
int degrees[MAXV + 1];
int UFS[MAXV+1];//并查集
int Find_UFS(int x) {
	if (UFS[x] == -1) return x;
	else return Find_UFS(UFS[x]);
}
int main() {
	int n, e, i, j, x, y,x1,y1;
	while (cin >> n) {
		if (!n) break;//输入0表示结束
		memset(UFS, -1, sizeof(UFS));//并查集的查找属性标记为-1
		memset(degrees, 0, sizeof(degrees));
		cin >> e;
		for (i = 1; i <= e; i++) {
			cin >> x >> y;
			x1 = Find_UFS(x);
			y1 = Find_UFS(y);
			if (x1!=y1) UFS[x1] = y1;
			degrees[x]++;
			degrees[y]++;
		}
		int mark = 1;
		int c = 0;
		for (i = 1; i <= n; i++) {
			if(degrees[i]%2) {
				mark = 0;
				break;
			}
			if (Find_UFS(i) == i) c++;//联通子图的个数为1，则整个图联通
			if (c > 1) {
				mark = 0;
				break;
			}
		}
		cout << mark << endl;
	}
	return 0;
}
