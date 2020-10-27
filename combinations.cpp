/**
 * Iterate all combinations.
 */
#include <iostream>
#include <vector>

using namespace std;

bool next(vector<int> &comb, int total_elem_cnt) {
  int comb_sz = static_cast<int>(comb.size());
  int i = comb_sz - 1;
  while (i >= 0 && comb[i] >= total_elem_cnt - comb_sz + i) {
    --i;
  }
  if (i < 0) {
    return false;
  }
  int elem = ++comb[i];
  for (++i; i < comb_sz; ++i) {
    comb[i] = ++elem;
  }
  return true;
}

int main() {
  const int total_elem_cnt = 5;
  const int comb_sz = 3;

  vector<int> comb;
  comb.reserve(comb_sz);
  for (int i = 0; i < comb_sz; ++i) {
    comb.push_back(i);
  }

  int comb_cnt = 0;
  do {
    cout << ++comb_cnt << ":";
    for (auto elem : comb) {
      cout << " " << elem;
    }
    cout << endl;
  } while(next(comb, total_elem_cnt));

  return 0;
}

/* OUTPUT

1: 0 1 2
2: 0 1 3
3: 0 1 4
4: 0 2 3
5: 0 2 4
6: 0 3 4
7: 1 2 3
8: 1 2 4
9: 1 3 4
10: 2 3 4

*/
