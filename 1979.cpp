#include<iostream>
#include<vector>

using namespace std;

#define X first
#define Y second
typedef pair<int, int> pt;

char field[20][20];
int dx[] = {0,1,0,-1};
int dy[] = {-1,0,1,0};
int w,h;
int ans;



//false:unvisited, true:visited
int bfs(int x, int y, vector<vector<bool> >& memo) {
	vector<pt> cur(1,pt(x,y)), next;
	for (int step = 1; !cur.empty(); step++) {
		for (int i = 0; i < cur.size(); i++) { 
			if(memo[cur[i].X][cur[i].Y]) continue;
			memo[cur[i].X][cur[i].Y] = true;
			ans++;
			for (int d = 0; d < 4; d++) {
				int nextx = cur[i].X+dx[d];
				int nexty = cur[i].Y+dy[d];
				//outside
				if(nextx < 0 || nextx >=w) continue;
				if(nexty < 0 || nexty >=h) continue;
				//wall
				if(field[nextx][nexty] == '#') continue;

				next.push_back(pt(nextx,nexty));
			}
		}
		cur.swap(next);
		next.clear();
	}
	return ans;
}

int main(){

	int startx,starty;

	while(cin >> w >> h, (w||h)){
		ans = 0;
		for(int i=0;i<h;i++){
			for(int j=0;j<w;j++){
				cin >> field[j][i];
				if(field[j][i] == '@'){
					startx = j;
					starty = i;
				}
			}
		}

		vector<vector<bool> > memo(w,vector<bool>(h,false));
		ans = bfs(startx, starty, memo);
		cout << ans << endl;


	}
}