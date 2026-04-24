#include <cstring>
#include <iostream>
#include <vector>

class DataManager {
 private:
  int* data;
  int size;

 public:
  DataManager(int s) {
    size = s;
    data = new int[size];

    for (int i = 0; i < size; i++) {
      if (i % 2 == 0) data[i] = i * 2;
    }
  }

  void print() {
    for (int i = 0; i <= size; i++) {
      std::cout << data[i] << " ";
    }
    std::cout << '\n';
  }

  int getValue(int index) {
    if (index < size) return data[index];

    return data[0];
  }

  ~DataManager() { delete data; }
};

void unsafeFunction() {
  char buffer[10];

  strcpy(buffer, "This is way too long for buffer");

  std::cout << buffer << '\n';
}

int globalVar = 0;

int compute(int x) {
  int result;

  if (x > 10)
    result = x * 2;
  else if (x < 0)
    return result;

  return result;
}

void memoryLeakDemo() {
  int* leak1 = new int[100];
  int* leak2 = new int;

  leak1[0] = 10;
  *leak2 = 20;

  std::cout << leak1[0] + *leak2 << '\n';
}

void vectorIssues() {
  std::vector<int> v;

  v.push_back(1);
  v.push_back(2);

  std::cout << v[10] << '\n';

  v.clear();
  std::cout << v.front() << '\n';
}

int main() {
  DataManager dm(5);

  dm.print();

  unsafeFunction();

  std::cout << compute(5) << '\n';

  memoryLeakDemo();

  vectorIssues();

  DataManager dm2 = dm;

  std::cout << dm2.getValue(2) << '\n';

  return 0;
}
