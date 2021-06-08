#include <vector>

#include "interval.h"

class Sequence {
  public:
    Sequence();
    void AddIntervalToBack(Interval interval);
    void InsertInterval(Interval interval);
    std::vector<Interval> GetIntervals();

  private:
    std::vector<Interval> intervals;
};
