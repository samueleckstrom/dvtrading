Hello!

To run the algorithm >>
$ make app
$ ./app
// enter values at your leisure

To make the tests >>
$ make test
$ ./test
// you may have to download google tests... hopefully linking will work fine

To remove the object files >>
$ make clean

My algorithm has an O(n) runtime complexity. For each insert, there is the potential to run through the entire
vector before an insert occurs.

In my opinion, a very easy place to improve would be to use a binary search in order to reduce the 
insertion run time complexity. For instance, a binary search would have an O(log(n)) runtime
complexity instead of the O(n) time complexity. In addition, I could make the interval and sequence objects more
flexible. For instance, the interval class currently assumes that the first int entered is strictly smaller than
the second int entered. I could make a check to ensure that this is the case AND make it so the order of any
two integers does not matter.