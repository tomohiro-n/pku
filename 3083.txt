#include<iostream>
#include<vector>

using namespace std;
typedef pair<int,int> pt;

char field[40][40]; 
int dx[] = {0,1,0,-1}; 
int dy[] = {-1,0,1,0};
int w,h;
int endx, endy;
int depth;

void rec(int dir,int nextdir, int x, int y){
	if(x == endx && y == endy) return;
	for(int i=(dir+nextdir+4)%4;;i=(i+4-nextdir)%4){
		int nextx = x+dx[i];
		int nexty = y+dy[i];
		// outside
		if(nextx < 0 || nextx >=w) continue;
		if(nexty < 0 || nexty >=h) continue;
		// wall
		if(field[nextx][nexty] == '#') continue;

		// this way is possible to move on
		// and try all angles
		depth++;
		rec(i,nextdir,nextx,nexty);
		return;

	}
} 


int bfs(int x, int y, vector<vector<bool> >& memo) {
	vector<pt> cur(1,pt(x,y)), next;
	for (int step = 1; !cur.empty(); step++) {
		for (int i = 0; i < cur.size(); i++) {
			//cout<<step<<" "<<cur.size()<<endl;
			if(cur[i].first == endx && cur[i].second == endy) return step;
			if(memo[cur[i].first][cur[i].second]) continue;
			memo[cur[i].first][cur[i].second] = true;
			for (int d = 0; d < 4; d++) {
				int nextx = cur[i].first+dx[d];
				int nexty = cur[i].second+dy[d];
				// outside
				if(nextx < 0 || nextx >=w) continue;
				if(nexty < 0 || nexty >=h) continue;
				// wall
				if(field[nextx][nexty] == '#') continue;
				next.push_back(pt(nextx,nexty));
			}
		}
		cur.swap(next);
		next.clear();
	}
	return -1;
}
	
int main(){ 
        int n; 
        cin >> n; 

        for(int i=0;i<n;i++){ 
                int startx,starty; 
                cin >> w >> h; 
                for(int j=0;j<h;j++){ 
                        for(int k=0;k<w;k++){ 
                                cin >> field[k][j]; 
                                if(field[k][j] == 'S'){ 
                                        startx = k; 
                                        starty = j; 
                                } 
                                if(field[k][j] == 'E'){ 
                                        endx = k; 
                                        endy = j; 
                                } 
                        } 
                } 

				int left,right,min;

				depth = 1;
				rec(0,-1,startx,starty);
				//cerr<<"left"<<endl;
				left = depth;
				depth = 1;
				rec(0,1,startx,starty);
				//cerr<<"right"<<endl;
				right = depth;
				depth = 1;
				vector<vector<bool> > memo(w,vector<bool>(h));
				min = bfs(startx,starty,memo);
				//cerr<<"bfs"<<endl;

				cout << left << " " << right << " " << min << endl;

        } 
}