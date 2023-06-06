#include <iostream>
#include <vector>
template<typename InIter, typename OutIter>
OutIter ReverseCopy(InIter first, InIter last, OutIter out) {
  while (last != first)
    *out++ = *(--last);
  return out;
}

int main() {
  std::vector<int> v{1, 2, 4, 6};
  std::vector<int> res(4);
  ReverseCopy(v.begin(), v.end(), res.begin());
  for (auto el : res) {
    std::cout << el << " ";
  }
  return 0;
}
