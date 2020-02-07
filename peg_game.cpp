#include <iostream>
#include <vector>
#include <map>
using namespace std;

map<pair< vector< vector<int> >, bool>, int> memo;

bool out_bound(int i, int j) {
	if (i < 0 || j < 0 || i > 4 || j > i) return true;
	return false;
}

int dx[6] = {-1, -1, 0, 0, 1, 1};
int dy[6] = {-1, 0, 1, -1, 1, 0};

int get_score(vector< vector<int> > &board, bool max_player) {

	if (memo[{board, max_player}] > 0) return memo[{board, max_player}];

	int temp;
	int best_score = 1 << 29;
	if (max_player) best_score = - (1 << 29);
	bool jump_found = false;

	for (int i = 0; i < 5; ++i)
	 {
	 	for (int j = 0; j <= i; ++j)
	 	{
	 		if (board[i][j] == 0) continue;

	 		for (int k = 0; k < 6; ++k)
	 		{
	 			int ni = i + dx[k];
	 			int nj = j + dy[k];

	 			int nni = i + 2 * dx[k];
	 			int nnj = j + 2 * dy[k];

	 			if (out_bound(nni, nnj)) continue;
	 			if (board[ni][nj] == 0 || board[nni][nnj] != 0) continue;

	 			jump_found = true;
	 			temp = board[ni][nj];
	 			board[nni][nnj] = board[i][j];
	 			board[i][j] = 0;
	 			board[ni][nj] = 0;

	 			if (max_player) best_score = max(best_score, temp * board[nni][nnj] + get_score(board, !max_player));
	 			else best_score = min(best_score, - temp * board[nni][nnj] + get_score(board, !max_player));

	 			board[i][j] = board[nni][nnj];
	 			board[nni][nnj] = 0;
	 			board[ni][nj] = temp;
	 		}
	 	}
	}

	if (!jump_found) return 0;

	memo[{board, max_player}] = best_score;

	return best_score;
}

int main(int argc, char const *argv[])
{
	std::vector< vector<int> > v(5);

	for (int i = 0; i < 5; ++i)
	{
		v[i].resize(i + 1);
		for (int j = 0; j <= i; ++j)
		{
			cin >> v[i][j];
		}
	}

	int ans = get_score(v, true);
	cout << ans;
	return 0;
}










