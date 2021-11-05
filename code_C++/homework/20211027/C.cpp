#include <bits/stdc++.h>

using namespace std;

const int MAX_SIZE = 10;

int main() {
	int i, j, m, n;
	int mat[MAX_SIZE+2][MAX_SIZE];

	cout << "Please input m, n:";
	cin >> m >> n;
	cout << "Input array:\n";
	for (i = 0; i < m; i++)
		for(j = 0; j < n; j++)
			cin >> mat[i][j];

	for(i = m - 1; i >= 0; i--){
		for(j = 0; j < n; j++){
			mat[i + 1][j] = mat[i][j];
		}
	}

	memcpy(mat[0], mat[m], sizeof mat[0]);

	cout << "New array:\n";
	for(i = 0; i < m; i++){
		for(j = 0; j < n; j++)
			cout << mat[i][j] << '\t';
		cout<<endl;
	}
	return 0;
}
