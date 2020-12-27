#include <iostream>
#include <iomanip>
using namespace std;
#define ll long long
double a[100001];

double dp[3001][3001];

double solve(ll n, ll h){
	// base case
	if(h == 0) return 1;
	if(n == 0) return 0;

	if(dp[n][h]>-0.9) return dp[n][h];

	// recursive case	
	return dp[n][h] = a[n]*solve(n-1,h-1)+(1-a[n])*solve(n-1,h);
}


int main(){
	ll n;
	cin>>n;
	for(ll i = 1 ; i <= n ; i ++) cin>>a[i];
	memset(dp,-1,sizeof dp);

	cout<<fixed<<setprecision(10)<<solve(n,(n+1)/2)<<endl;
	return 0;
}