/*小明想要亲自修复在他的一个小牧场周围的围栏。他测量栅栏并发现他需要N根木板，每根的长度为整数L_{i}。
于是，他神奇地买了一根足够长的木板，长度为所需的N根木板的长度的总和，他决定将这根木板切成所需的N根木板。
（小明在切割木板时不会产生木屑，不需考虑切割时损耗的长度）
小明切割木板时使用的是一种特殊的方式，这种方式在将一根长度为x的模板切为两根时，需要消耗x个单位的能量。
小明拥有无尽的能量，但现在提倡节约能量，所以作为榜样，他决定尽可能节约能量。显然，总共需要切割N-1次。
问题是，每次应该怎么切呢？请编程计算最少需要消耗的能量总和。
输入格式：
第一行: 整数N，表示所需木板的数量。
第2到N+1行: 每行为一个整数，表示一块木板的长度。
输出格式：
一个整数，表示最少需要消耗的能量总和。
输入样例：
3
8
5
8
输出样例：
34*/
#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
using namespace std;
int n;
priority_queue<long long,vector<long long>,greater<long long>> p;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		p.push(x);
	}
	long long t=0;
	while(p.size()!=1){
		long long a=p.top();p.pop();
		long long b=p.top();p.pop();
		t+=a+b;
		p.push(a+b);
	}
	cout<<t;
}
