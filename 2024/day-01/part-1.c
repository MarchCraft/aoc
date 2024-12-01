#include <stdio.h>
#include <stdlib.h>

int main() {
  FILE *f = fopen("input.txt", "r");

  char line[100];

  if (f == NULL) {
    printf("Error opening file\n");
    return 1;
  }

  int lines = 0;
  while (fgets(line, sizeof(line), f)) {
    lines++;
  }

  fseek(f, 0, SEEK_SET);

  // create two arrays to store the int values
  int *ptr_left = malloc(sizeof(int) * lines);
  int *ptr_right = malloc(sizeof(int) * lines);

  int i = 0;

  while (fscanf(f, "%d %d", &ptr_left[i], &ptr_right[i]) != EOF) {
    i++;
  }

  for (int i = 0; i < lines; i++) {
    for (int j = 0; j < lines - 1; j++) {
      if (ptr_right[j] > ptr_right[j + 1]) {
        int temp = ptr_right[j];
        ptr_right[j] = ptr_right[j + 1];
        ptr_right[j + 1] = temp;
      }
    }
  }

  for (int i = 0; i < lines; i++) {
    for (int j = 0; j < lines - 1; j++) {
      if (ptr_left[j] > ptr_left[j + 1]) {
        int temp = ptr_left[j];
        ptr_left[j] = ptr_left[j + 1];
        ptr_left[j + 1] = temp;
      }
    }
  }

  int sum = 0;

  for (int i = 0; i < lines; i++) {
    sum += abs(ptr_left[i] - ptr_right[i]);
  }

  printf("Sum: %d\n", sum);

  return 0;
}
