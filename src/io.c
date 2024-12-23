#include <stdio.h>
#include <stdbool.h>

#include "../include/colors.h"
#include "../include/calculations.h"

void printSchemes() {
  printf("Scheme 1: \n");
  printf("*---[  R  ]---[  L  ]---*\n");
  printf("  |                    |\n");
  printf("  |                    |\n");
  printf("  ------[  C  ]---------\n");

  printf("Scheme 2: \n");
  printf("*---[  R  ]---[  C  ]---*\n");
  printf("  |                    |\n");
  printf("  |                    |\n");
  printf("  ------[  L  ]---------\n");

  printf("Scheme 3: \n");
  printf("*---[  R2  ]---[  C  ]---*\n");
  printf("  |                    |\n");
  printf(" ----                  |\n");
  printf(" |R1|                  |\n");
  printf(" ----                  |\n");
  printf("  |                    |\n");
  printf("*-------[  L  ]---------\n");

  printf("Scheme 4: \n");
  printf("*---[  R2  ]-------------*\n");
  printf("  |                    |\n");
  printf(" ----                  |\n");
  printf(" |R1|                  |\n");
  printf(" ----                  |\n");
  printf("  |                    |\n");
  printf(" ----                  |\n");
  printf(" |C |                  |\n");
  printf(" ----                  |\n");
  printf("*-------[  L  ]-----------\n");
}

unsigned getUserChoice(const char *message, const int min, const int max) {
  unsigned choice = 0;
  bool isValid = false;
  do {
    printf("%s [%d - %d]: ", message, min, max);
    isValid = scanf("%u", &choice);

    if (!isValid) {
      printf(RED"Invalid input. Try again.\n"RESET);
    }
    if (choice < min || choice > max) {
      printf(RED"Enter a number between %d and %d!\n"RESET, min, max);
      isValid = false;
    }
  } while (!isValid);
  return choice;
}

double getDoubleFromUser(const char *message, const double min, const double max) {
  double result = 0;
  bool isValid = false;
  do {
    printf("%s [%lf - %lf]: ", message, min, max);
    isValid = scanf("%lf", &result);
    while (getchar() != '\n');
    if (!isValid) {
      printf(RED"Invalid input. Try again.\n"RESET);
    }
    if (result < min || result > max) {
      printf(RED"Enter a number between %lf and %lf!\n"RESET, min, max);
      isValid = false;
    }
  } while (!isValid);
  return result;
}

void printComplexResult(const Complex result, const double f, const int i) {
  printf("f%d = %lf: %e + i * %e\n", i + 1, f, result.real, result.imaginary);
}
