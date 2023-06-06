#include <iostream>
#include <vector>
template<typename Iter>
Iter Unique(Iter first, Iter last) {
  if (first == last)
    return first;
  Iter res = first;
  while (++first != last)
    if (*res != *first)
      if (++res != first)
        *res = *first;
  res++;
  return res;
}

int main() {
  std::vector<int> v{1, 2, 1, 1, 3, 3, 3, 3, 4, 5, 4};
  auto res = Unique(v.begin(), v.end());
  for (auto it = v.begin(); it != res; it++) {
    std::cout << *it << " ";
  }
  return 0;
}
