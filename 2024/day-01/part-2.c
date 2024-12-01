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

  int similarity = 0;

  for (int i = 0; i < lines; i++) {
    int x = ptr_right[i];
    int count = 0;
    for (int j = 0; j < lines; j++) {
      if (ptr_left[j] == x) {
        count++;
      }
    }
    printf("Value %d is contained %d times in ptr_left\n", x, count);
    similarity += x * count;
  }

  printf("Similarity: %d\n", similarity);

  return 0;
}
