#include<string>
#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>


using namespace std;
typedef pair<int, int> pairs;
char field[100][50];

int n, m;

struct cmp{
public:
	//cmp(){};
	bool operator() (const pairs &lhs, const pairs &rhs){
		if(lhs.second == rhs.second) return lhs.first < lhs.first;
		else return lhs.second < rhs.second;
	}
};


int calc(int linenum){
	int result=0;
	int temp=0;
	for(int i=0; i<n-1; i++){
		for(int j=i+1;j<n;j++){
			if(field[linenum][i] > field[linenum][j]) result++;
		}
	}
	return result;
}

int main(){
	cin >> n >> m;
	for(int i=0;i<m;i++){
		for(int j=0;j<n; j++){
			cin >> field[i][j];
		}
	}
	vector<pairs> result;	
	for(int i=0; i<m; i++) result.push_back(pairs(i,calc(i)));
	sort(result.begin(), result.end(), cmp());
	for(int i=0; i<m; i++){
		for(int j=0; j<n; j++){
			cout << field[result[i].first][j];
		}
		cout << endl;
	}
	result.clear();
	//for(int i=0; i<m; i++) cout << field[result[i].first] << endl;

	return 0;
}