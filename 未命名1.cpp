#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<fstream>
using namespace std;

int a[10000][10000];// ͼ 
int d[10000];// ��ʾ�������������T����ʱ��ǰ��С�ߵ�Ȩֵ 
bool vis[10000];// �����жϸýڵ��Ƿ��Ѽ�����С��������T���� 
int n, m, w = 0;// n,m,w�ֱ�Ϊ����������������С��������Ȩֵ 

// prim�㷨 
void prim(){
	int x = 0, i, j, k; 
	memset(d, 0x3f, sizeof(d));
	memset(vis, 0, sizeof(vis));
	d[1] = 0; // ��V1��ʱ��ȨΪ0 
	for(i = 1; i < n; i++){// ��ѭ��n-1��  ÿ���ҳ�һ�������T 
		for(j = 1; j <= n; j++){// �������нڵ� 
			if(!vis[j] && (x == 0 || d[j] < d[x])) // ����˽ڵ�δ����T��������СȨֵ�� 
				x = j;                         // ���´˽ڵ� 
		}
		vis[x] = 1;// �ͽ��ýڵ���뵽Ҫ�����С������T������  
		for(k = 1; k <= n; k++)
		{
			if(!vis[k])// �¼���һ���㣬��ά���õ㵽��û�м���T���ϵĵ�ľ���  
				d[k] = min(d[k], a[x][k]);// ȡ����������
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
	// �ӵڶ����ڵ㵽��n���ڵ��ۼ���̱ߵ�Ȩֵ 
	for(int i = 2; i <= n; i++)
	w += d[i];
	cout << w << endl;
	return 0;
}
