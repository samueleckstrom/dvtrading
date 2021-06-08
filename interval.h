class Interval {
  public:
    Interval(int a, int b);
    int GetSmallPoint();
    int GetLargePoint();

  private:
    int smallPoint;
    int largePoint;
};