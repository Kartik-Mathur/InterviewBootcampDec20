#include <iostream>
using namespace std;

int main(){
	
	int n;
	cin>>n;

	for(int i = 0 ; i*i <= n ; i++){
		for(int j = i ; j*j <= n ; j++){
			for(int k = j ; k*k <= n ; k++){
				for(int l = k ; l*l <= n ; l++){
					if(i*i + j*j + k*k + l*l == n){
						cout<<i<<" "<<j<<" "<<k<<" "<<l<<endl;
					}
				}
			}
		}
	}

	
	return 0;
}