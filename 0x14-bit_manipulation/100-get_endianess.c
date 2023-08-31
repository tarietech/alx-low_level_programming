#include <stdio.h>

unsigned char check_endianness() {
  unsigned int number = 1;
  char byte;

  /* Get the first byte of the integer. */
  memcpy(&byte, &number, sizeof(byte));

  return byte;
}

int main() {
  unsigned char endianness = check_endianness();

  if (endianness) {
    printf("The machine is big-endian.\n");
  } else {
    printf("The machine is little-endian.\n");
  }

  return 0;
}
