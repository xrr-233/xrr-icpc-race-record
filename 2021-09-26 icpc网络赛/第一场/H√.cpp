#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
vector <vector <int> > point;
vector <vector <int> > face;
map <int, int> pid_to_vid;
map <int, int> vid_to_pid;
map <pair<int, int>, bool> M;
bool cmp(int a,int b)
{
	return vid_to_pid[a]<vid_to_pid[b];
}
int main() {
	int n, m;
	int id, type;
	double xt, yt, zt;
	int x, y, z;
	cin >> n >> m;
	point.resize(n);
	face.resize(n);
	for (int i = 1; i <= n; i++) {
		cin >> id >> xt >> yt >> zt;
		pid_to_vid[id] = i;
		vid_to_pid[i] = id;
	}
	for (int i = 0; i < m; i++) {
		cin >> id >> type;
		if(type == 102) {
			cin >> x >> y;
			if(M[make_pair(x, y)] == 0) {
				point[pid_to_vid[x] - 1].push_back(pid_to_vid[y]);
				M[make_pair(x, y)] = 1;
			}
			if(M[make_pair(y, x)] == 0) {			
				point[pid_to_vid[y] - 1].push_back(pid_to_vid[x]);
				M[make_pair(y, x)] = 1;
			}
			face[pid_to_vid[x] - 1].push_back(id);
			face[pid_to_vid[y] - 1].push_back(id);
		}
		else {
			cin >> x >> y >> z;
			if(M[make_pair(x, y)] == 0) {
				point[pid_to_vid[x] - 1].push_back(pid_to_vid[y]);
				M[make_pair(x, y)] = 1;
			}
			if(M[make_pair(y, x)] == 0) {
				point[pid_to_vid[y] - 1].push_back(pid_to_vid[x]);
				M[make_pair(y, x)] = 1;
			}
			if(M[make_pair(x, z)] == 0) {
				point[pid_to_vid[x] - 1].push_back(pid_to_vid[z]);
				M[make_pair(x, z)] = 1;
			}
			if(M[make_pair(y, z)] == 0) {
				point[pid_to_vid[y] - 1].push_back(pid_to_vid[z]);
				M[make_pair(y, z)] = 1;
			}
			if(M[make_pair(z, x)] == 0) {
				point[pid_to_vid[z] - 1].push_back(pid_to_vid[x]);
				M[make_pair(z, x)] = 1;
			}
			if(M[make_pair(z, y)] == 0) {
				point[pid_to_vid[z] - 1].push_back(pid_to_vid[y]);
				M[make_pair(z, y)] = 1;
			}
			face[pid_to_vid[x] - 1].push_back(id);
			face[pid_to_vid[y] - 1].push_back(id);
			face[pid_to_vid[z] - 1].push_back(id);
		}
	}
	int l, p, len;
	cin >> l;
	for (int i = 0; i < l; i++) {
		cin >> p;
		cout << p << endl;
		if(pid_to_vid[p] == 0) {
			cout << "[]" << endl;
			cout << "[]" << endl;
		}
		else {
			cout << '[';
			sort(point[pid_to_vid[p] - 1].begin(),point[pid_to_vid[p] - 1].end(),cmp); 
			len = point[pid_to_vid[p] - 1].size();
			for(int j = 0; j < len; j++) {
				cout << vid_to_pid[point[pid_to_vid[p] - 1][j]];
				if(j != len - 1)
					cout << ',';
			}
			cout << ']' << endl;
			cout << '[';
			sort(face[pid_to_vid[p] - 1].begin(), face[pid_to_vid[p] - 1].end());
			len = face[pid_to_vid[p] - 1].size();
			for(int j = 0; j < len; j++) {
				cout << face[pid_to_vid[p] - 1][j];
				if(j != len - 1)
					cout << ',';
			}
			cout << ']' << endl;
		}
	}
	return 0;
}
/*
8 6
1 0.0 1.1 0.0
5 1.5e1 2.1e1 0.0
3 2.3 0.1 0.0
4 3.0 1.8 0.0
2 3.4 0.2 0.0
6 4.2 2.3 0.0
7 5.5 -0.1 0.0
8 6.1 1.9 0.0
1 203 1 5 3
2 203 5 3 4
3 203 3 4 2
4 203 4 2 6
5 203 2 6 7
6 102 2 8
*/
