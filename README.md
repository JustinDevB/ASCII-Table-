# ASCII-Table-

An ASCII table printed out by only using C Sytem Calls such as write, no printf is used

ascii.c (5pts):
This program should print an ASCII table that prints the ASCII characters
from 0 to 127 in 4 separate columns.  Each character should be preceded by
its value, which should be printed in decimal by default. The program should
accept a command line switch to modify the output of the ASCII values to
alternatively print it in binary (-b option), hexadecimal (-h option) or
octal (-o option).

Non-printable ASCII characters should be printed as a dot (.).
Example output:

    0: '.'        32: ' '         64: '@'         96: '`'
    1: '.'        33: '!'         65: 'A'         97: 'a'
    2: '.'        34: '"'         66: 'B'         98: 'b'
