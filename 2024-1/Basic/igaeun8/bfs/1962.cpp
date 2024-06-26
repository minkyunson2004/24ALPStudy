#include <iostream>
#include <utility>
#include <queue>

using namespace std;

int main(){
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int board[501][501];
	bool vis[501][501]; 
	
	queue<pair<int,int> > Q;
	int n,m;

	cin >> n >> m;
	
	int dx[4] = {1,0,-1,0};
	int dy[4] = {0,1,0,-1};
	
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			cin >> board[i][j];	
		}		
	}
	
	int area = 0; // 그림의 넓이 
	int max = 0; 
	int num = 0; // 그림의 개수 
	
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			
			if(vis[i][j] || board[i][j]==0)
				continue;
				
			vis[i][j] = 1;
			Q.push({i,j});
			area = 0;
			num++;        // 그림의 개수는 새로운 시작점 횟수
			
			while(!Q.empty()){
				pair<int,int> cur = Q.front();
				Q.pop();
				
				area++;    // 그림의 넓이는 pop하는 횟수
				
				for(int dir=0; dir<4; dir++){
					int nx = cur.first + dx[dir];
					int ny = cur.second + dy[dir];
					
					if(nx < 0 || nx >= n || ny < 0 || ny >=m)
						continue;
						
					if(vis[nx][ny] || board[nx][ny]==0)
						continue;
					
					vis[nx][ny]=1;
					Q.push({nx,ny});
				}
				
				if(max < area)
					max = area;
				
			}
		}
	}
	
	cout << num << "\n" << max;
	
	return 0; 

}
