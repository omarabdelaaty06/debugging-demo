#include <cstdio>
#include <cstdlib>
#include <cstring>

char* buf;

int sum_to_n(int num) {
  int i, sum = 0;
  for (i = 1; i <= num; i++) sum += i;
  return sum;
}

void printSum() {
  char line[10];
  printf("Enter a number: ");
  fgets(line, 10, stdin);

  if (line != NULL) strtok(line, "\n");

  buf = (char*)malloc(64);
  sprintf(buf, "sum=%d", sum_to_n(atoi(line)));
  printf("%s\n", buf);
  free(buf);
}

int main() {
  printSum();
  return 0;
}
