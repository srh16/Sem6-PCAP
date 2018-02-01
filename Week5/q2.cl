__kernel void one_comp (__global string *A, __global string *B) 
{
	int i = get_global_id(0);
	string bin = A[i],tmp="";
	for(int j=0;j<bin.length();j++)
	{
		if(bin[j]=='1')
			tmp.append('0');
		else if(bin[j]=='0')
			tmp.append('1');
	}
	B[i] = ones;
}
