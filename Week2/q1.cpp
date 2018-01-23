#include <bits/stdc++.h>
#include <mpi.h>

using namespace std;

int main(int argc,char*argv[])
{
	MPI_Init(&argc,&argv);
	int r,size;
	char s[100];
	MPI_Comm_rank(MPI_COMM_WORLD,&r);
	MPI_Status status;
	if(r==0)
	{
		printf("Enter a string: ");
		cin>>s;
		size=strlen(s);
		MPI_Ssend(&size,1,MPI_INT,1,0,MPI_COMM_WORLD);
		MPI_Ssend(s,strlen(s),MPI_CHAR,1,1,MPI_COMM_WORLD);
		MPI_Recv(s,strlen(s),MPI_CHAR,1,2,MPI_COMM_WORLD,&status);
		printf("Case change: %s\n",s);			
	}
	else if(r==1)
	{
		MPI_Recv(&size,1,MPI_INT,0,0,MPI_COMM_WORLD,&status);
		MPI_Recv(s,size,MPI_CHAR,0,1,MPI_COMM_WORLD,&status);
		int l=strlen(s);
		for(int i=0;i<l;i++)
		{
			if(s[i]>=65 && s[i]<=90)
				s[i]+=32;
			else if(s[i]>=97 && s[i]<=122)
				s[i]-=32;
		}
		MPI_Ssend(s,size,MPI_CHAR,0,2,MPI_COMM_WORLD);
	}
	MPI_Finalize();
	return 0;
}

