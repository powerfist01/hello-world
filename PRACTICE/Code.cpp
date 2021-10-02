#pragma comment(linker, "/STACK:102400000,102400000") 
#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <bitset>
#include <list>
#include <stdexcept>
#include <functional>
#include <utility>
#include <ctime>
#include <random>
#include <cassert>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 4e1 + 10;
int sum[N][N][N];
char s1[N*N*N], s2[N*N*N];
int ans[N];
int getsum(int ax, int ay, int az, int bx, int by, int bz)
{
	return sum[bx][by][bz]
		- sum[ax - 1][by][bz] - sum[bx][ay - 1][bz] - sum[bx][by][az - 1]
		+ sum[ax - 1][ay - 1][bz] + sum[ax - 1][by][az - 1] + sum[bx][ay - 1][az - 1]
		- sum[ax - 1][ay - 1][az - 1];
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		int n, K;
		scanf("%d%d", &n, &K);
		scanf("%s%s", s1, s2);
		int o = 0;
		MEM(ans, 0);
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				for (int k = 1; k <= n; k++)
				{
					sum[i][j][k] = 0;
					sum[i][j][k] = (s1[o] == s2[o]) - getsum(i, j, k, i, j, k);
					int minv = min({ i,j,k });
					for (int t = 0; t < minv; t++)
					{
						int tot = getsum(i - t, j - t, k - t, i, j, k);
						int all = (t + 1)*(t + 1)*(t + 1);
						if (tot * 100 >= all * K)
						{
							ans[t + 1]++;
						}
					}
					o++;
				}
			}
		}
		int s = -1;
		for (int i = 1; i <= n; i++)
		{
			if (ans[i])
				s = i;
		}
		if (s == -1) printf("%d\n", s);
		else printf("%d %d\n", s, ans[s]);
	}

	return 0;
}
