#include <iostream> 
#include <vector>
#include <set>
#include <utility>
#include <fstream>
using namespace std;
#define INF 3333300001
#define MAX 300000


vector <pair <int, long long> > peaks[MAX];
set <pair <long long, int> > min_paths;

int main() {
	ifstream in("input.txt");
	ofstream out1("output.txt");
	long n, m;
	in >> n;
	in >> m;
	for (int i = 0; i<m; i++) {
		int from, to, len;
		in >> from;
		in >> to;
		in >> len;
		from, to;
		peaks[to-1].push_back(make_pair(from, len));
		peaks[from-1].push_back(make_pair(to, len));
	}
	long long* len = new long long[n];
	for (int i = 0; i<n; i++) len[i] = INF;
	int curry = 0;
	len[curry] = 0;
	min_paths.insert(make_pair(len[curry], curry));
	while (!min_paths.empty()) {
		int v = min_paths.begin()->second;
		min_paths.erase(min_paths.begin());
		for (int i = 0; i<peaks[v].size(); i++) {
			int oklend = peaks[v][i].first, durant = peaks[v][i].second;
			if (len[v] + durant < len[oklend - 1]) {
				min_paths.erase(make_pair(len[oklend - 1],oklend - 1));
				len[oklend - 1] = len[v] + durant;
				min_paths.insert(make_pair(len[oklend - 1], oklend - 1));
			}
		}
	}
	if (len[n-1] == INF) {
		out1 << "0";
		return 0;
	}
	cout << len[n - 1] << endl; 
	out1 << len[n - 1] << endl;
	in.close();
	out1.close();
	return 0;
}
