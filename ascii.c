#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>

void writ(char character);

void printTick() {
  if (write(STDOUT_FILENO, "'", 1) == -1)
    perror("printtick");
}

void octal(int o) {
   if (o >= 8) {
    octal(0/8);
    o %= 8;
  }
  o += '0';
  if (write(STDOUT_FILENO, &o, sizeof(o)) == -1)
    perror("octal");

}

void hex(int h) {
  char hex[16] = "0123456789ABCDEF";
  writ(hex[(h/16)%16]);
  writ(hex[h%16]);
}

void binary(int b) {

  int tmp, rem;
  tmp = b / 2;
  rem = b % 2;
  if (tmp > 0) 
    binary(tmp);
  rem += '0';
  writ(rem);
}

void writ(char character) {
  if(write(STDOUT_FILENO, &character, 1) == -1)
    perror("write");
}

void printNum(int num) {
  if (num >= 10) {
    printNum(num/10);
    num %= 10;
  }
  num += '0';
  if(write(STDOUT_FILENO, &num, sizeof(num)) == -1)
    perror("printNum");
}
int main(int argc, char *argv[]) {
  char ascii[128];
  int col = 0;
  int prefix, increment = 0; 

  for (int i = 0; i <=127; i++)
    ascii[i] = i;

  for (int i = 0; i <= 127; i++) {

    if (argv[1] == NULL)
      printNum(prefix);
    else if (strcmp(argv[1], "-b") ==0)
      binary(prefix);
    else if (strcmp(argv[1], "-h") ==0)
      hex(prefix);
    else if (strcmp(argv[1], "-o") ==0)
      octal(prefix);

    writ(':');
    writ(' ');
    printTick();
    if (prefix <= 31 || prefix == 127)
      writ('.');
    else
      writ(ascii[prefix]);
    printTick();
    writ(' ');
    col++;
    prefix += 32;
      if (col == 4) {
      writ('\n');
      col = 0;
      increment++;
      prefix = increment;
    }
  }

  return 0;
}
