#include <stdio.h>

#include "include/calculations.h"
#include "include/colors.h"
#include "include/io.h"

int main(void) {
  char restart = 0;
  do {
    printSchemes();
    unsigned schemeChoice = 0;
    double r1 = 0.0, r2 = 0.0, l = 0.0, c = 0.0, fmin = 0.0, fmax = 0.0, step = 0.0;
    schemeChoice = getUserChoice("Choose scheme", 1, 4);

    r1 = getDoubleFromUser("Enter R1(Ohm)",MIN_DOUBLE, MAX_DOUBLE);
    if (schemeChoice == 3 || schemeChoice == 4) {
      r2 = getDoubleFromUser("Enter R2(Ohm)",MIN_DOUBLE, MAX_DOUBLE);
    }
    l = getDoubleFromUser("Enter L(mH)", MIN_DOUBLE, MAX_DOUBLE);
    c = getDoubleFromUser("Enter C(μF)", MIN_DOUBLE, MAX_DOUBLE);
    step = getDoubleFromUser("Enter step", MIN_DOUBLE, MAX_DOUBLE);

    fmin = getDoubleFromUser("Enter fmin", MIN_DOUBLE, MAX_DOUBLE - 1);
    fmax = getDoubleFromUser("Enter fmax", fmin, MAX_DOUBLE);

    printf("Resonance frequency = %lf\n", calculateResonanceFrequency(l, c));

    calculate(fmin, fmax, r1, r2, l, c, step, schemeChoice);

    printf(GREEN"Print \'r\' to restart or press enter to exit!\n"RESET);
    scanf("%c", &restart);
    while (getchar() != '\n');
  } while (restart == 'r');

  return 0;
}
