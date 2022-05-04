#include <stdio.h>
#include <windows.h>
#define MAXSIZE 1250  
#define    OK      1  
#define    ERROR   0  
#define    TRUE    1  
#define    FLASE   0  
typedef    int     Status;
typedef    int     ElemType;

typedef struct{
	int   i, j;       //该非零元的行下标和列下标  
	ElemType e;       //非零元对应的值  
}Triple;

typedef struct{
	Triple   data[MAXSIZE + 1];       //非零元三元组表，data[0]未用  
	int      mu, nu, tu;            //矩阵的行数，列数，非零元个数  
}TSMatrix;

Status FastTransposeSMatrix(TSMatrix M, TSMatrix &T)              //快速转置  
{                                                      //采用三元组顺序表存储表示，求稀疏矩阵M的转置矩阵T  
	T.mu = M.nu;
	T.nu = M.mu;
	T.tu = M.tu;
	if (T.tu)
	{
		int col;
		int num[100], cpot[100];
		for (col = 1; col <= M.nu; ++col)
			num[col] = 0;                 //num数组的初始化  
		for (int t = 1; t <= M.tu; ++t)
			++num[M.data[t].j];         //求M中每一列含有的非零元个数  
		cpot[1] = 1;
		for (col = 2; col <= M.nu; ++col)
			cpot[col] = cpot[col - 1] + num[col - 1];         //求cpot向量  
		int q;
		for (int p = 1; p <= M.tu; ++p)
		{
			col = M.data[p].j;
			q = cpot[col];
			T.data[q].i = M.data[p].j;
			T.data[q].j = M.data[p].i;
			T.data[q].e = M.data[p].e;
			++cpot[col];
		}//for  
	}//if  
	return OK;
}//FastTransposeSMatrix  

Status main()
{
	TSMatrix M;
	TSMatrix T;
	printf("请输入原矩阵：\n");
	printf("行数、列数： ");
	scanf("%d%d", &M.mu, &M.nu);
	printf("元素总数： ");
	scanf("%d", &M.tu);
	printf("输入各个对应压缩值：\n");
	for (int i = 1; i <= M.tu; ++i)
		scanf("%d%d%d", &M.data[i].i, &M.data[i].j, &M.data[i].e);

	FastTransposeSMatrix(M, T);

	printf("转置后行数、列数、元素总数非别为：\n%d     %d     %d\n\n", T.mu, T.nu, T.tu);
	printf("值为：\n");
	for (int t = 1; t <= T.tu; ++t)
		printf("%d     %d     %d\n", T.data[t].i, T.data[t].j, T.data[t].e);
	system("pause");
	return OK;
}

