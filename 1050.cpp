#include<iostream>

using namespace std;

int field[100][100];


int max_sum(int n, int *arr){
	int result=0;
	int b=0;
	for(int i=0;i<n;i++){
		if(b>0) b+=arr[i];
		else b=arr[i];
		
		if(b>result) result=b;
	}
	return result;
}

int max_sum2(int m, int n){
	int result=0;
	int *b=new int[n];
    for(int i=0;i<m;i++){
		//init
		memset(b,0,sizeof(int)*n);

		for(int j=i;j<m;j++){
			for(int k=0;k<n;k++) b[k]+=field[j][k];
			int max=max_sum(n,b);
			if(max>result) result=max;
		}
	}
	delete b;
	return result;
}

int main(){
	int n;
	cin >> n;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin >> field[i][j];
		}
	}
	//dp
	cout << max_sum2(n,n) << endl;
}