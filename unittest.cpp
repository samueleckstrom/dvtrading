#include "gtest/gtest.h"

#include "sequence.h"

class IntervalsTest : public ::testing::Test {
  protected:
    void SetUp() override {
      
    }
};

TEST_F(IntervalsTest, CheckCreation) {
  Sequence s;
  Interval i1(-20, -14);
  s.AddIntervalToBack(i1);
  Interval i2(-5, 5);
  s.AddIntervalToBack(i2);
  Interval i3(25, 30);
  s.AddIntervalToBack(i3);

  std::vector<Interval> intervals = s.GetIntervals();
  EXPECT_EQ(intervals.size(), 3);
}

TEST_F(IntervalsTest, CheckInsertion) {
  Sequence s;
  Interval i1(-20, -14);
  s.AddIntervalToBack(i1);
  Interval i2(-5, 5);
  s.AddIntervalToBack(i2);
  Interval i3(25, 30);
  s.AddIntervalToBack(i3);

  Interval i4(6, 24);
  s.InsertInterval(i4);

  std::vector<Interval> intervals = s.GetIntervals();
  EXPECT_EQ(intervals.size(), 4);
  EXPECT_EQ(intervals[0].GetSmallPoint(), -20);
  EXPECT_EQ(intervals[0].GetLargePoint(), -14);

  EXPECT_EQ(intervals[1].GetSmallPoint(), -5);
  EXPECT_EQ(intervals[1].GetLargePoint(), 5);

  EXPECT_EQ(intervals[2].GetSmallPoint(), 6);
  EXPECT_EQ(intervals[2].GetLargePoint(), 24);

  EXPECT_EQ(intervals[3].GetSmallPoint(), 25);
  EXPECT_EQ(intervals[3].GetLargePoint(), 30);

  Interval i5(-13, -6);
  s.InsertInterval(i5);
  intervals = s.GetIntervals();
  EXPECT_EQ(intervals.size(), 5);
  EXPECT_EQ(intervals[0].GetSmallPoint(), -20);
  EXPECT_EQ(intervals[0].GetLargePoint(), -14);
  
  EXPECT_EQ(intervals[1].GetSmallPoint(), -13);
  EXPECT_EQ(intervals[1].GetLargePoint(), -6);

  EXPECT_EQ(intervals[2].GetSmallPoint(), -5);
  EXPECT_EQ(intervals[2].GetLargePoint(), 5);

  EXPECT_EQ(intervals[3].GetSmallPoint(), 6);
  EXPECT_EQ(intervals[3].GetLargePoint(), 24);

  EXPECT_EQ(intervals[4].GetSmallPoint(), 25);
  EXPECT_EQ(intervals[4].GetLargePoint(), 30);
}

TEST_F(IntervalsTest, CheckEdgeCases) {
  Sequence s;
  Interval i1(-20, -14);
  s.AddIntervalToBack(i1);
  Interval i2(-5, 5);
  s.AddIntervalToBack(i2);
  Interval i3(25, 30);
  s.AddIntervalToBack(i3);

  Interval i4(-30, -21);
  s.InsertInterval(i4);

  std::vector<Interval> intervals = s.GetIntervals();
  EXPECT_EQ(intervals.size(), 4);
  EXPECT_EQ(intervals[0].GetSmallPoint(), -30);
  EXPECT_EQ(intervals[0].GetLargePoint(), -21);

  EXPECT_EQ(intervals[1].GetSmallPoint(), -20);
  EXPECT_EQ(intervals[1].GetLargePoint(), -14);

  EXPECT_EQ(intervals[2].GetSmallPoint(), -5);
  EXPECT_EQ(intervals[2].GetLargePoint(), 5);

  EXPECT_EQ(intervals[3].GetSmallPoint(), 25);
  EXPECT_EQ(intervals[3].GetLargePoint(), 30);

  Interval i5(31, 40);
  s.InsertInterval(i5);
  intervals = s.GetIntervals();
  EXPECT_EQ(intervals.size(), 5);
  EXPECT_EQ(intervals[0].GetSmallPoint(), -30);
  EXPECT_EQ(intervals[0].GetLargePoint(), -21);

  EXPECT_EQ(intervals[1].GetSmallPoint(), -20);
  EXPECT_EQ(intervals[1].GetLargePoint(), -14);

  EXPECT_EQ(intervals[2].GetSmallPoint(), -5);
  EXPECT_EQ(intervals[2].GetLargePoint(), 5);

  EXPECT_EQ(intervals[3].GetSmallPoint(), 25);
  EXPECT_EQ(intervals[3].GetLargePoint(), 30);

  EXPECT_EQ(intervals[4].GetSmallPoint(), 31);
  EXPECT_EQ(intervals[4].GetLargePoint(), 40);
}

TEST_F(IntervalsTest, EmptyInsert) {
  Sequence s;
  Interval i1(-20, -14);
  s.InsertInterval(i1);

  std::vector<Interval> intervals = s.GetIntervals();
  EXPECT_EQ(intervals.size(), 1);

  EXPECT_EQ(intervals[0].GetSmallPoint(), -20);
  EXPECT_EQ(intervals[0].GetLargePoint(), -14);
}