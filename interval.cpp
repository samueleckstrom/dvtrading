#include "interval.h"

Interval::Interval(int a, int b) {
  smallPoint = a;
  largePoint = b;
}

int Interval::GetSmallPoint() {
  return smallPoint;
}

int Interval::GetLargePoint() {
  return largePoint;
}