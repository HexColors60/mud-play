#import "support.h"

int main() {

  NSLog(@"(list, 1, 2, 3) should be: (1, 2, 3) == %@", nsMudTestEvaluate(@[@500, @1, @2, @3]));

  NSLog(@"(lcount, (list, 1, 2, nil, 3)) should be: 3 == %@", nsMudTestEvaluate(@[@501, @[@500, @1, @2, @[@120, @"unknown"], @3]]));

  NSLog(@"(lnth, (list, 1, 2, 3), 0) should be: 1 == %@", nsMudTestEvaluate(@[@502, @[@500, @1, @2, @3], @0]));
  NSLog(@"(lnth, (list, 1, 2, 3), 1) should be: 2 == %@", nsMudTestEvaluate(@[@502, @[@500, @1, @2, @3], @1]));

  NSLog(@"(append, (list, 1, 2, 3), 4, nil, 5, 6) should be: (1, 2, 3, 4, 5, 6) == %@", nsMudTestEvaluate(@[@503, @[@500, @1, @2, @3], @4, @[@120, @"ud"], @5, @6]));

  NSLog(@"(prepend, (list, 4, 5, 6), 1, nil, 2, 3) should be: (1, 2, 3, 4, 5, 6) == %@", nsMudTestEvaluate(@[@504, @[@500, @4, @5, @6], @1, @[@120, @"ud"], @2, @3]));

  NSLog(@"(push, (list, 1, 2, 3), 4) should be: (1, 2, 3, 4) == %@", nsMudTestEvaluate(@[@505, @[@500, @1, @2, @3], @4]));

  NSLog(@"(push, (list, 1, 2, 3), 1.5, 1) should be: (1, 1.5, 2, 3) == %@", nsMudTestEvaluate(@[@505, @[@500, @1, @2, @3], @1.5, @1]));

  NSLog(@"(push, (list, 1, 2, 3), 0, 0) should be: (0, 1, 2, 3) == %@", nsMudTestEvaluate(@[@505, @[@500, @1, @2, @3], @0, @0]));

  NSLog(@"ok");
}