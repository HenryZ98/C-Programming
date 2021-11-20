#include <stdlib.h>
#include <stdio.h>

size_t maxSeq(int * array, size_t n);

int main() {
  int array1[] = {1,1,1,2};
  int array2[] = {0};
  int array3[] = {1,-3,4,5,11};
  int array4[] = {-1,-2,3};
  int array5[] = {2,4,3,6,10,15,-1,7,8,2};
  int array6[] = {1,2,3,2};

  if (maxSeq(NULL, 0)){
    exit(EXIT_FAILURE);
  }
  if (maxSeq(array1, 4) != 2) {
    exit(EXIT_FAILURE);
  }
  if (maxSeq(array2, 1) != 1) {
    exit(EXIT_FAILURE);
  }
  if (maxSeq(array3, 5) != 4) {
    exit(EXIT_FAILURE);
  }
  if (maxSeq(array4, 3) != 2) {
    exit(EXIT_FAILURE);
  }
  if (maxSeq(array5, 10) != 4) {
    exit(EXIT_FAILURE);
  }
  if (maxSeq(array6, 4) != 3) {
    exit(EXIT_FAILURE);
  }
  if (maxSeq(array6, 0)) {
    exit(EXIT_FAILURE);
  }
  return EXIT_SUCCESS;
}
