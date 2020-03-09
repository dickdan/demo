#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<fstream>
using namespace std;

int a[10000][10000];// 图 
int d[10000];// 表示顶点加入生成树T集合时当前最小边的权值 
bool vis[10000];// 用于判断该节点是否已加入最小生成树的T集合 
int n, m, w = 0;// n,m,w分别为顶点数，边数，最小生成树的权值 

// prim算法 
void prim(){
	int x = 0, i, j, k; 
	memset(d, 0x3f, sizeof(d));
	memset(vis, 0, sizeof(vis));
	d[1] = 0; // 在V1的时候权为0 
	for(i = 1; i < n; i++){// 大循环n-1次  每次找出一个点加入T 
		for(j = 1; j <= n; j++){// 遍历所有节点 
			if(!vis[j] && (x == 0 || d[j] < d[x])) // 如果此节点未加入T集合是最小权值边 
				x = j;                         // 记下此节点 
		}
		vis[x] = 1;// 就将该节点加入到要求的最小生成树T集合里  
		for(k = 1; k <= n; k++)
		{
			if(!vis[k])// 新加了一个点，就维护该点到还没有加入T集合的点的距离  
				d[k] = min(d[k], a[x][k]);// 取距离生成树
		}
	}
}

int main(){
    int x, y, z;
	cin >> n >> m;
	memset(a, 0x3f, sizeof(a));
	for(int i = 1; i <= n; i++) a[i][i]=0;
	for(int i = 1; i <= m; i++){
		cin >> x >> y >> z;
		a[x][y] = a[y][x] = z;
	}
	prim();
	// 从第二个节点到第n个节点累加最短边的权值 
	for(int i = 2; i <= n; i++)
	w += d[i];
	cout << w << endl;
	return 0;
}

// demo
