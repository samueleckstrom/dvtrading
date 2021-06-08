#include "sequence.h"

Sequence::Sequence() { }

void Sequence::AddIntervalToBack(Interval interval) {
 intervals.push_back(interval);
}

void Sequence::InsertInterval(Interval interval) {
  for (std::vector<Interval>::iterator iter = intervals.begin(); iter != intervals.end(); ++iter) {
    if (interval.GetLargePoint() < iter->GetSmallPoint()) {
      intervals.insert(iter, interval);
      return;
    }
  }
  intervals.push_back(interval);
}

std::vector<Interval> Sequence::GetIntervals() {
  return intervals;
}