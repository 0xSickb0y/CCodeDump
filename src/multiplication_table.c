int main() {
  int num;

  printf("This is a demo script for a 'multiplication table' in C.\n");

  printf("Table:\n>>> ");
  scanf("%d", &num);

  for (int i = 0; i <= 10; i++) {
    int mult = num * i;
    printf("%d x %d = %d\n", num, i, mult);
  }
}
