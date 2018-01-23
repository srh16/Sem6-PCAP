#include <bits/stdc++.h>
#include <mpi.h>

using namespace std;

int main(int argc,char*argv[])
{
	MPI_Init(&argc,&argv);
	printf("Multiplication of MxN and NxP matrix\nEnter M, N and P sequentially\n");
	int m,n,p;
	cin>>m>>n>>p;
	int m1[m][n],m2[n][p],res[m][p];
	for(int i=0;i<m;i++)
		for(int j=0;j<p;j++)
			res[i][j]=0;
	printf("Enter matrix 1:\n");
	for(int i=0;i<m;i++)
		for(int j=0;j<n;j++)
			cin>>m1[i][j];
	printf("Enter matrix 2:\n");
	for(int i=0;i<n;i++)
		for(int j=0;j<p;j++)
			cin>>m2[i][j];
	for(int i=0;i<m;i++)
		for(int j=0;j<p;j++)
			for(int k=0;k<n;k++)
				res[i][j]+=m1[i][k]*m2[k][j];
	printf("Resultant matrix is:\n");
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<p;j++)
			cout<<res[i][j]<<" ";
		cout<<endl;
	}
	MPI_Finalize();
	return 0;
}
