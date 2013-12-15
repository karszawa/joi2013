#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int N;
	cin >> N;

	vector<int> D(N), A(N);
	for(int i = 0; i < N; i++) {
		cin >> D[i];
	}
	
	for(int i = 0; i < N; i++) {
		cin >> A[i];
	}

	cout << rand() << endl;
}
