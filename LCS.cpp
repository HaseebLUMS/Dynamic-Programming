#include <iostream>

using namespace std;

int LCS(string a, string b, int na, int nb);
int max(int a, int b){return a > b ? a : b;}
int memo[100][100];

int main() {
	for(int i = 0; i < 100; i++){for(int j = 0; j < 100; j++){memo[i][j] = -1;}}
	string a = "ABCDGHIJDJDJDJD";
	string b = "AEDFHRKHKHKHJD";
	cout << LCS(a, b, a.size()-1, b.size()-1) << endl;
	return 0;
}

int LCS(string a, string b, int na, int nb) {
	na += 1; nb += 1;
	int m[na+1][nb+1];
	
	for(int i = 0; i < nb+1; i++){m[0][i] = 0;}
	for(int i = 0; i < na+1; i++){m[i][0] = 0;}

	for(int i = 1; i < na+1; i++)
	{
		for(int j = 1; j < nb+1; j++)
		{
			if(a[i-1] == b[j-1]){m[i][j] = 1 + m[i-1][j-1];}
			else{
				m[i][j] = max(m[i-1][j], m[i][j-1]);
			}
		}
	}
	return m[na][nb];
}