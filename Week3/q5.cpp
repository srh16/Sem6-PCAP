#include <bits/stdc++.h>
#include <mpi.h>
#define MIN(x,y) (x)>(y)?y:x

using namespace std;

int main(int argc,char*argv[])
{
	MPI_Init(&argc,&argv);
	int r,size,l1,l2;
	MPI_Comm_rank(MPI_COMM_WORLD,&r);
	MPI_Comm_size(MPI_COMM_WORLD,&size);
	MPI_Status status;
	char s1[100], s2[100],rs1[100], rs2[100];
	char ns[200];
	if(r==0)
	{
		printf("Enter the string 1: ");
		cin>>s1;
		printf("Enter the string 2: ");
		cin>>s2;
		l1=strlen(s1)/size;
		l2=strlen(s2)/size;
	}
	MPI_Bcast(&l1,1,MPI_INT,0,MPI_COMM_WORLD);
	MPI_Bcast(&l2,1,MPI_INT,0,MPI_COMM_WORLD);
	MPI_Scatter(s1, l1, MPI_CHAR, rs1, l1, MPI_CHAR, 0, MPI_COMM_WORLD);
	MPI_Scatter(s2, l2, MPI_CHAR, rs2, l2, MPI_CHAR, 0, MPI_COMM_WORLD);
	char concstr[100];
	int i=0,j=0,k=0;
	while(i<l1 && j<l2)
	{
		concstr[k++]=rs1[i++];
		concstr[k++]=rs2[j++];
	}	
	printf("%d %s\n",r,concstr);
	MPI_Gather(concstr, l1+l2, MPI_CHAR, ns, l1+l2, MPI_CHAR, 0, MPI_COMM_WORLD);
	if(r==0)
		ns[(l1+l2)*size]='\0',printf("String is = %s\n",ns);
	MPI_Finalize();
	return 0;
}

