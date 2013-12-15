#include <iostream>
#include <string>
#include <bitset>
using namespace std;


int N;
string R;
int memo[2048][8];
const int MOD = 10007;


bool attend(char who, int s)
{
	if(who == 'J') return s & (1 << 0);
	if(who == 'O') return s & (1 << 1);
	if(who == 'I') return s & (1 << 2);

	return false;
}

int rec(int day, int prev)
{
	if(memo[day][prev] != -1) return memo[day][prev];
	
	if(day == N) return 1;

	int ret = 0;
	for(int now = 1; now < 8; now++) {
		if((prev & now) && attend(R[day], now)) {
			ret = (ret + rec(day+1, now)) % MOD;
		}
	}

	return memo[day][prev] = ret;
}


int main()
{
	memset(memo, -1, sizeof memo);
	
	cin >> N >> R;
	cout << rec(0, 1) << endl;
}

