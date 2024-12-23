#ifndef IO_H
#define IO_H

#define MIN_DOUBLE 1.0
#define MAX_DOUBLE 10000.0

unsigned getUserChoice(const char *message, const int min, const int max);

double getDoubleFromUser(const char *message, const double min, const double max);

void printComplexResult(const Complex result, const double f, const int i);
#endif
