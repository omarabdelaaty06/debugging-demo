#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>

long long computePrimeLike(int n) {
  long long sum = 0;

  for (int i = 2; i <= n; i++) {
    bool isPrime = true;

    for (int j = 2; j * j <= i; j++) {
      if (i % j == 0) {
        isPrime = false;
        break;
      }
    }

    if (isPrime) sum += i;
  }

  return sum;
}

int fib(int n) {
  if (n <= 1) return n;
  return fib(n - 1) + fib(n - 2);
}

int randomWork(int seed) {
  srand(seed);

  int total = 0;
  for (int i = 0; i < 200000; i++) {
    int r = rand() % 100;

    if (r % 2 == 0)
      total += r;
    else
      total -= r;
  }

  return total;
}

void mixedWorkload(int n) {
  std::cout << "Prime-like sum: " << computePrimeLike(n) << '\n';
  std::cout << "Fib result: " << fib(38) << '\n';
  std::cout << "Random work: " << randomWork(n) << '\n';
}

void heavyTask(int mode) {
  if (mode % 3 == 0) {
    mixedWorkload(5000);
  } else if (mode % 3 == 1) {
    mixedWorkload(7000);
  } else {
    mixedWorkload(9000);
  }
}

int main() {
  std::cout << "Starting heavy tasks..." << '\n';

  for (int i = 1; i <= 5; i++) {
    heavyTask(i);
  }

  std::cout << "Done." << '\n';
  return 0;
}
