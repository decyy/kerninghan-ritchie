#include <stdio.h>

#define OUT 0
#define IN 1

#define LOWER 0
#define UPPER 300
#define STEP 20

void f_conv(int lower, int upper, int step, int reverse) {

  printf("%3s   %s\n", "Fahrenheit", "Celsius");

  if (reverse) {
    for (int i = upper; i >= lower; i -= step) {
      float celsius = (5.0f / 9.0f) * (i - 32.0f);

      printf("| %3d\t | \t %3.0f | \n", i, celsius);
    }
  } else {

    for (int i = lower; i <= upper; i += step) {
      float celsius = (5.0f / 9.0f) * (i - 32.0f);

      printf("| %3d\t | \t %3.0f | \n", i, celsius);
    }
  }
}

int count_chars() {
  double lines;
  double chars;
  double blanks;
  double tabs;

  for (chars = 0; getchar() != EOF; chars++) {
    switch (getchar()) {
    case '\n':
      printf("Lines: %lg \n", lines);
      lines++;
    case '\t':
      printf("Tabs: %lg \n", tabs);
      tabs++;
    case ' ':
      printf("Blanks: %lg \n", blanks);
      blanks++;
    }

    chars++;
    printf("Chars: %lg \n", chars);
  }

  return chars;
}

void minimize() {
  int c;
  int prev = 0;

  while ((c = getchar()) != EOF) {

    if (c == ' ' && prev == ' ') {
      continue;
    }

    putchar(c);
    prev = c;
  }
}

void showChars() {
  int current = getchar();

  while (current != EOF) {
    switch (current) {
    case '\n':
      putchar('n');
      break;
    case '\t':
      putchar('t');
      break;
    case ' ':
      putchar('/');
      break;
    default:
      putchar(current);
    }

    current = getchar();
  }
}

int count_words() {
  int cw = 0;
  int curr = getchar();

  int state = 0;

  while (curr != EOF) {
    if (curr == '\n' || curr == ' ' || curr == '\t') {
      state = OUT;
    } else if (state == OUT) {
      state = IN;
      cw++;
      printf("\n");
    }

    putchar(curr);
    curr = getchar();
  }

  return 1;
}

int main() { count_words(); }
