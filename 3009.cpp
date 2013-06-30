#include<iostream>

using namespace std;

int w, h;
int field[21][21];
int preans;
int ans;

int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

void rec(int n, int nowx, int nowy){
	if(n >= ans) return;
	int afterx, aftery;

	for(int i=0; i<4; i++){
		// try all angles
		afterx = nowx + dx[i];
		aftery = nowy + dy[i];
		if(afterx < 0 || afterx >= w) continue;
		if(aftery < 0 || aftery >= h) continue;
		if(field[aftery][afterx] == 1) continue;

		// ok if you are already at the goal
		while(1){
			if(field[aftery][afterx] == 3){
				ans = n;
				return;
			}

			// not at the goal, keep trying
			afterx += dx[i];
			aftery += dy[i];

			// break if outside
			if(afterx < 0 || afterx >= w) break;
			if(aftery < 0 || aftery >= h) break;

			if(field[aftery][afterx] == 1){
				field[aftery][afterx] = 0;
				rec(n+1, afterx-dx[i], aftery-dy[i]);
				field[aftery][afterx] = 1;
				break;
			}
		}
	}
}



int main(){
	while ( cin >> w >> h ){
		if( w == 0 && h == 0) break;
		int startx, starty;

		// input
		for(int y=0; y<h; y++){
			for(int x=0; x<w; x++){
				cin >> field[y][x];
				if( field[y][x] == 2){
					startx=x;
					starty=y;
				}
			}
		}

		preans=11;
		ans=11;
		rec(1, startx, starty);
		if(ans > 10) ans = -1;
			cout << ans << endl;
	}

	return 0;

}