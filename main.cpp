#include <vector>
#include <iostream>

#include "sequence.h"

int main() {
  std::cout << "Please provide intervals..." << std::endl;

  char t = 'c';
  int a;
  int b;
  Sequence s;

  while (t != 'q') {
    std::cout << "Enter small point: " << std::endl;
    std::cin >> a;
    std::cout << "Enter large point" << std::endl;
    std::cin >> b;

    Interval interval(a, b);
    s.InsertInterval(interval);

    std::cout << "Enter q to exit; anything else to continue..." << std::endl;
    std::cin >> t;
  }

  std::vector<Interval> intervals = s.GetIntervals();
  for (std::vector<Interval>::iterator iter = intervals.begin(); iter != intervals.end(); ++iter) {
    std::cout << "[" << iter->GetSmallPoint() << ", " << iter->GetLargePoint() << "]" << std::endl;
  }

  return -1;
}