#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;
int set[60];
int myRank[60];

int c[60][60];
int b[60][60];
int d[60][60];

struct edge
{
	int u,v,c;
	bool s;
	edge():u(0),v(0),c(0),s(0){}
	edge(int _u,int _v, int _c):u(_u),v(_v),c(_c),s(0){}
};

bool cmp1(const edge& e1, const edge& e2)
{
	return e1.c<e2.c;
}

bool cmp2(const edge& e1, const edge& e2)
{
	return e1.c>e2.c;
}


int find(int x) {
	if (x != set[x]) {
		set[x] = find(set[x]);
		return set[x];
	}
	else
		return set[x];
}

void link(int x, int y) {
	if (myRank[x] > myRank[y]) {
		set[y] = x;
	}
	else {
		set[x] = y;
		if (myRank[x] == myRank[y])
			myRank[y]++;
	}
}
void merge(int x, int y) {
	link(find(x), find(y));
}

int main() {
	int n;
	cin >> n;
	while (n != 0) {
		for (int i = 0; i<n; i++) {
			set[i] = i;
			myRank[i] = 0;
		}
		memset(c, 0, sizeof(c));
		memset(b, 0, sizeof(b));
		memset(d, 0, sizeof(d));
		string line;
		getline(cin, line);
		for (int i = 0; i<n; i++) {
			getline(cin, line);
			for (int j = 0; j<n; j++) {
				if (line[j] == '1') {
					c[i][j] = 1;
				}
			}
		}
		for (int i = 0; i<n; i++) {
			for (int j = 0; j<n; j++) {
				cin >> b[i][j];
			}
		}
		for (int i = 0; i<n; i++) {
			for (int j = 0; j<n; j++) 
				cin>>d[i][j];
			
		}
		vector<edge> build,destroy;
		for (int i = 0; i<n; i++) {
			for (int j = 0; j<i; j++) {
				build.push_back(edge(i, j, b[i][j]));
			}
		}
		sort(build.begin(),build.end(),cmp1);

		for (int i = 0; i<n; i++) {
			for (int j = 0; j<i; j++) {
				if (c[i][j] != 0) {
					destroy.push_back(edge(i, j, d[i][j]));
				}
			}
		}
		sort(destroy.begin(),destroy.end(), cmp2);


		for (int i = 0; i<destroy.size(); i++) {
			int u = find(destroy[i].u);
			int v = find(destroy[i].v);

			if (u != v) {
				destroy[i].s = 1;
				merge(u, v);
			}
		}
		for (int i = 0; i<build.size(); i++) {
			int u = find(build[i].u);
			int v = find(build[i].v);

			if (u != v) {
				build[i].s = 1;
				merge(u,v);
			}
		}


		int sum = 0;
		for (auto e: destroy) {
			if (!e.s)
				sum += e.c;
		}
		for (auto e: build) {
			if (e.s) {
				sum += e.c;
			}
		}
		cout << sum << endl;
		cin >> n;
	}
	return 0;
}