// SubArrayWithSumLessK
#include <iostream>
using namespace std;

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif

	int n;
	cin>>n;
	int *a = new int[n];
	int ans = 0;
	for(int i = 0 ; i < n ; i++){
		cin>>a[i];
	}

	for(int i = 0 ; i < 32 ; i++){
		int cnt = 0; // keep a cnt of nonset bits
		for(int j = 0 ; j < n ; j++){
			if((a[j]&(1<<i)) == 0){
				cnt++;
			}
		}
		// n-cnt : set bits
		// how many pairs can we have : (n-cnt)*cnt
		ans=ans + cnt*(n-cnt)*2;
	}

	cout<<ans;
	cout<<endl;
	return 0;
}