#include<bits/stdc++.h>
using namespace std;
int main() {
	int c, cnt = 0;
	while((c = getchar())!='@')
	{
		if(c == '(') cnt++;
		else if(c == ')') cnt--;
		if(cnt == -1) break;
	}
	if(cnt == 0) cout << "YES" << endl;
	else cout << "NO" << endl;
	return 0;
}