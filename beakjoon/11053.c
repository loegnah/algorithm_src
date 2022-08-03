#include <stdio.h>

int main()
{
	int n,i,j,mn,ret=0;
	int arr[1000];
	int bbLen[1000];
	
	scanf("%d",&n);
	for(i=0; i<n; ++i) 
	{
		mn = 0;
		scanf("%d",&arr[i]);
		for(j=0; j<i; ++j) 
		{
			if(arr[i] > arr[j] && mn < bbLen[j]) mn = bbLen[j];
		}
		bbLen[i] = mn + 1;
		ret = ret > bbLen[i] ? ret : bbLen[i];
	}
	printf("%d",ret);
}
