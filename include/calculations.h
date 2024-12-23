#ifndef CALCULATIONS_H
#define CALCULATIONS_H

typedef struct {
  double real;
  double imaginary;
} Complex;

typedef struct {
  double a;
  double b;
  double c;
  double d;
} SubstitutionStruct;

double calculateResonanceFrequency(double l, double c);

Complex calculateComplex(SubstitutionStruct substitution);

Complex calculateSchemeA(const double r1, const double l, const double c, const double omega);

Complex calculateSchemeB(const double r1, const double l, const double c, double omega);

Complex calculateSchemeC(const double r1, const double r2, const double l, const double c, double omega);

Complex calculateSchemeD(const double r1, const double r2, const double l, const double c, double omega);

void calculate(const double fmin, const double fmax, const double r1, const double r2, const double l, const double c,
               double step, unsigned scheme);
#endif
