#include <iostream>
#include <vector>
using namespace std;


int main()
{
	int N, M;
	cin >> N >> M;

	vector<int> expenses(N);
	for(int i = 0; i < N; i++) {
		cin >> expenses[i];
	}

	vector<int> votes(N, 0);
	for(int i = 0; i < M; i++) {
		int expense;
		cin >> expense;

		for(int j = 0; ; j++) {
			if(expenses[j] <= expense) {
				votes[j]++;
				break;
			}
		}
	}

	int best = 1, vote = votes[0];
	for(int i = 1; i < N; i++) {
		if(vote < votes[i]) {
			vote = votes[i];
			best = i+1;
		}
	}
	
	cout << best << endl;
}
