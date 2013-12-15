#include <iostream>
using namespace std;


int main()
{
	int W, H, N;
	cin >> W >> H >> N;

	int cost = 0, x = 1, y = 1;
	cin >> x >> y;
	for(int i = 0; i < N-1; i++) {
		int X, Y;
		cin >> X >> Y;

		if((y <= Y && x <= X) || (y >= Y && x >= X)) cost += max(abs(X - x), abs(Y - y));
		else cost += abs(Y - y) + abs(X - x);

		x = X; y = Y;
	}

	cout << cost << endl;
}
