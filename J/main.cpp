#include <iostream>
#include <deque>
template<typename T, typename Container = std::deque<T>>
class Queue {
 private:
  Container cont;

 public:
  Queue() = default;
  T front() const {
    T temp = cont.front();
    return temp;
  }
  T &front() {
    return cont.front();
  }
  void pop() {
    cont.pop_front();
  }
  void push(T value) {
    cont.push_back(value);
  }
  size_t size() {
    return cont.size();
  }
  bool empty() {
    return size() == 0;
  }
  bool operator==(Queue other) {
    auto a = *this;
    if (a.size() != other.size())
      return false;
    while (!a.empty()) {
      auto b = a.front();
      auto c = other.front();
      if (b != c)
        return false;
      a.pop();
      other.pop();
    }
    return true;
  }
  bool operator!=(Queue other) {
    auto a = *this;
    return !(a == other);
  }
};

int main() {
  Queue<int> q;
  q.push(5);
  q.push(3);
  q.push(3);
  Queue<int> q2;
  q2.push(5);
  q2.push(3);
  q2.push(2);
  std::cout << (q != q2);
  return 0;
}
