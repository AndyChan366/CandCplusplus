/*题目描述：
对连通图进行遍历，我们有最大生成树；对于非连通图而言，多个连通分量对应的多棵生成树就构成了整个非连通图的生成森林。
最大生成森林的定义就是在非连通图中，所有连通分量对应的最大生成树之和。
因此我们给定一个无向图 G，它可能是一个非连通图的，你的任务是找到最大生成森林。
输入：
可能有多个测试用例。第一行是测试用例数目。
对于每个测试用例，第一行包含两个整数 n，m（1<=n<=1000，0<=m<=n*（n-1）/2），其中 n 是图中的顶点数，m 是边数。
接下来的 m 行，每行有三个整数 x，y，d（0<=x，y<=n-1 和 d>0），这意味着有一个无向边（x，y），代价为 d。
输出：
对于每个测试用例，输出最大生成森林的值。
输入样例：
2
3 3
0 1 1
1 2 2
2 0 3
4 2
0 1 1
2 3 2
输出样例：
5
3
*/
#include <stdio.h>
#include <string.h>

const int graph_size = 1000;
const int infinity = 0x3fffffff;

bool component[graph_size]; // Vertices in set X
int distance[graph_size]; // Distances of vertices adjacent to X
int neighbor[graph_size]; // Nearest neighbor in set X
int cs, n, m;
int a[graph_size][graph_size];

int MSF(int source)
{
	int ret = 0;
	int w;
	for (w = 0; w < n; w++) {
		distance[w] = a[source][w];
		neighbor[w] = source;
	}
	component[source] = true; // source alone is in the set X.
	while (true) {
		int v; // Add one vertex v to X on each pass.
		int mx = -infinity;
		for (w = 0; w < n; w++)
		if (!component[w])
		if (distance[w] > mx) {
			v = w;
			mx = distance[w];
		}
		if (mx > -infinity) {
			ret += mx;
			component[v] = true;
			for (w = 0; w < n; w++)
			if (!component[w])
			if (a[v][w] > distance[w]) {
				distance[w] = a[v][w];
				neighbor[w] = v;
			}
		}
		else break; // finished a component in disconnected graph
	}
	return ret;
}

int main()
{
	int x, y, i;
	scanf("%d", &cs);
	while (cs--) {
		scanf("%d%d", &n, &m);
		for (x = 0; x < n; x++) {
			a[x][x] = 0;
			for (y = x + 1; y < n; y++)
				a[x][y] = a[y][x] = -infinity;
		}

		while (m--) {
			scanf("%d%d%d", &x, &y, &i);
			a[x][y] = a[y][x] = i;
		}

		for (i = 0; i < n; i++)
			component[i] = false;

		int ans = 0;
		for (i = 0; i < n; i++)
			if (!component[i]) ans += MSF(i);
		printf("%d\n", ans);
	}
	return 0;
}
