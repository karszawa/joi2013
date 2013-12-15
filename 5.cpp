#include <iostream>
#include <vector>
#include <queue>
using namespace std;


struct P { int point, taxi, d, cost; P(int p=0, int t=0, int d=0, int c=0) : point(p), taxi(t), d(d), cost(c) {} };


int main()
{
	int N, K;
	cin >> N >> K;

	vector<int> C(N), R(N);
	for(int i = 0; i < N; i++) {
		cin >> C[i] >> R[i];
	}

	vector<vector<int> > edges(N);
	for(int i = 0; i < K; i++) {
		int A, B;
		cin >> A >> B;
		edges[A-1].push_back(B-1);
		edges[B-1].push_back(A-1);
	}

	vector<vector<int> > D(N, vector<int>(N, 1<<30));
	// D[i][j] := i番目の町でタクシーjに乗っている時の最小コスト
	queue<P> que;
	for(que.push(P(0, 0, R[0], C[0])); !que.empty(); que.pop()) {
		int point = que.front().point;
		int taxi = que.front().taxi;
		int d = que.front().d;
		int cost = que.front().cost;

		if(D[point][taxi] <= cost) continue;
		D[point][taxi] = cost;

		que.push(P(point, point, R[point], cost + C[point]));
		
		if(d > 0) {
			for(int i = 0; i < edges[point].size(); i++) {
				que.push(P(edges[point][i], taxi, d-1, cost));
			}
		}
	}

	int best = 1<<30;
	for(int i = 0; i < N; i++) {
		best = min(best, D[N-1][i]);
	}

	cout << best << endl;
}
