#include <iostream>
#include <vector>
using namespace std;
#define max 100
int main() {
	int vertexnum=0,edgenum=0;
	int i=0,j=0,count=0;	
	vector<int>order;							//数组order用于储存拓扑排序序列 
	int edge[max][max];
	int visit[max];
	cout<<"请输入顶点数和边数"<<endl;
	cin>>vertexnum>>edgenum;		
	for(i=0;i<vertexnum;i++){						//初始化 
		for(j=0;j<vertexnum;j++)
			edge[i][j]=0;	
		visit[i]=0;
	}
	while(edgenum--)						//将边输入进去 
	{
		cout<<"请输入顶点i与j（i表示始点，j表示终点）:"<<endl;
		cin>>i>>j;
		edge[i][j]=1;
	}
	cout<<"以每个顶点为出度的邻接矩阵表示为："<<endl; 
	cout<<'\t';
	for(i=0;i<vertexnum;i++)						//输出初始化后的邻接矩阵  
		cout<<i<<'\t';
	cout<<endl;
	for(i=0;i<vertexnum;i++){			
		cout<<i<<'\t';
		for(j=0;j<vertexnum;j++)
		{
			cout<<edge[i][j]<<'\t';	
		}
		cout<<endl;
	}
	cout<<endl;/* 
	cout<<"以每个顶点为入度的邻接矩阵表示为："<<endl;
	cout<<'\t';
	for(i=0;i<vertexnum;i++)						//输出初始化后的邻接矩阵 （邻接矩阵每一行代表以一个顶点为出度，它与其它顶点的关系） 
		cout<<i<<'\t';
	cout<<endl;
	for(i=0;i<vertexnum;i++){			
		cout<<i<<'\t';
		for(j=0;j<vertexnum;j++)
		{
			cout<<edge[j][i]<<'\t';	
		}
		cout<<endl;
	}*/ 
	int targetVertex,check,judge=0;
	for(i=0;i<vertexnum;i++)						//大循环，检查所有输入的顶点 
	{	
		for(targetVertex=0;targetVertex<vertexnum;targetVertex++)	
		{
			for(j=0;j<vertexnum;j++)
			{
				if(targetVertex==j)				//若碰到自身，则跳过（自身和自身间不存在关系） 
					continue;
				if(visit[targetVertex]||edge[j][targetVertex])	//若k为已输出顶点或有以k为入度的边存在 
				{
					judge=1;				// 将检查值设为1，方便后面直接跳过 
					break;
				}
			}	
			if(judge)						//若碰上judge为1的情况（即上面的情况），跳过此次循环（因为已经处理过或不满足入度为1的条件） 
			{	
				judge=0;					//并初始化judge值，方便下次判断 
				continue;
			}
			else							//否则即为未输出且入度为零的顶点 
			{
				order.push_back(targetVertex);			//加入拓扑排序数组 
				count++;
				visit[targetVertex]=1;				//设置为已输出 
				break;						//跳出 
			}
		}
		for(check=0;check<vertexnum;check++)	//将所有以k顶点为出度的相关边设为0（即删除k）	
			edge[targetVertex][check]=0;
		judge=0;							//判断值初始化 
	}
	if(count!=vertexnum)
		cout<<"图中存在环，其它顶点的拓扑排序为："<<endl;
	else
		cout<<"顶点的拓扑排序为："<<endl;
	for(i=0;i<order.size();i++)					//输出拓扑排序  
	{
		cout<<order[i]<<'\t';
	}
	return 0;
} 

