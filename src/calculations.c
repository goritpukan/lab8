#include <math.h>
#include <stdio.h>

#include "../include/calculations.h"
#include "../include/io.h"

double calculateResonanceFrequency(double l, double c) {
  return 1.0 / (2.0 * M_PI * sqrt(l * c));
}

Complex calculateComplex(SubstitutionStruct substitution) {
  Complex result = {};
  double denominator = pow(substitution.c, 2.0) + pow(substitution.d, 2.0);
  result.real = (substitution.a * substitution.c + substitution.b * substitution.d) / denominator;
  result.imaginary = (substitution.b * substitution.c - substitution.a * substitution.d) / denominator;
  return result;
}

Complex calculateSchemeA(const double r1, const double l, const double c, const double omega) {
  SubstitutionStruct substitution = {};

  substitution.a = l / c;
  substitution.b = -r1 / (omega * c);
  substitution.c = r1;
  substitution.d = omega * l - 1.0 / (omega * c);

  return calculateComplex(substitution);
}

Complex calculateSchemeB(const double r1, const double l, const double c, double omega) {
  SubstitutionStruct substitution = {};

  substitution.a = l / c;
  substitution.b = r1 / (omega * c);
  substitution.c = r1;
  substitution.d = omega * l - 1.0 / (omega * c);

  return calculateComplex(substitution);
}

Complex calculateSchemeC(const double r1, const double r2, const double l, const double c, double omega) {
  SubstitutionStruct substitution = {};

  substitution.a = r1 * r2;
  substitution.b = r1 * (omega * l - 1.0 / (omega * c));
  substitution.c = r1 + r2;
  substitution.d = omega * l - 1.0 / (omega * c);

  return calculateComplex(substitution);
}

Complex calculateSchemeD(const double r1, const double r2, const double l, const double c, double omega) {
  SubstitutionStruct substitution = {};

  substitution.a = r1 * r2 + l / c;
  substitution.b = omega * l * r1 - r2 / (omega * c);
  substitution.c = r1 + r2;
  substitution.d = omega * l - 1.0 / (omega * c);

  return calculateComplex(substitution);
}

void calculate(const double fmin, const double fmax, const double r1, const double r2, const double l, const double c,
               double step, unsigned scheme) {
  double f = fmin;
  int i = 0;
  do {
    const double omega = 2.0 * M_PI * f;
    switch (scheme) {
      case 1:
        printComplexResult(calculateSchemeA(r1, l, c, omega), f, i);
        break;
      case 2:
        printComplexResult(calculateSchemeB(r1, l, c, omega), f, i);
        break;
      case 3:
        printComplexResult(calculateSchemeC(r1, r2, l, c, omega), f, i);
        break;
      case 4:
        printComplexResult(calculateSchemeD(r1, r2, l, c, omega), f, i);
        break;
      default:
        printf("Invalid scheme\n");
    }
    i++;
    f += step;
  } while (f <= fmax);
}
