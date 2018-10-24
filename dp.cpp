

#include<bits/stdc++.h>
#define R 3
#define C 3
using namespace std;

int minInitialPoints(int points[][C])
{
	int dp[R][C];
	int m = R, n =C;
	for(int i =0;i<m;i++)
	{
		for(int j =0;j<n;j++)
			dp[i][j] = -1;
	}
	dp[m-1][n-1] = points[m-1][n-1] > 0? 1: abs(points[m-1][n-1]) + 1;
	printf("m-1,n-1 == %d\n",dp[m-1][n-1] );
	for(int i = m-2;i>=0;i--)
		dp[i][n-1]=max(dp[i+1][n-1] - points[i][n-1],1);
	for(int j = n-2;j>=0;j--)
		dp[m-1][j]=max(dp[m-1][j+1] - points[m-1][j],1);
	printf("Staritng now \n");
	for(int i =0;i<m;i++)
	{
		for(int j =0;j<n;j++)
			printf("%d ",dp[i][j]);
		printf("\n");
	}
	for(int i =m-2;i>=0;i--)
	{
		for(int j =n-2;j>=0;j--)
		{
			int min_points_on_exit = min(dp[i+1][j],dp[i][j+1]);
			dp[i][j] = max(min_points_on_exit - points[i][j],1);
		}
	}
	printf("Staritng now \n");
	for(int i =0;i<m;i++)
	{
		for(int j =0;j<n;j++)
			printf("%d ",dp[i][j]);
		printf("\n");
	}
	return dp[0][0];
}


int main()
{
	int points[R][C] = {{-2,-3,3},{-5,-10,1},{10,30,-5}};
	cout<< "Minimum initial points reqd: "<< minInitialPoints(points);
	return 0;
}
