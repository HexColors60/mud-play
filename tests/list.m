#import "support.h"

int main() {

  NSLog(@"(list, 1, 2, 3) should be: (1, 2, 3) == %@", nsMudTestEvaluate(@[@500, @1, @2, @3]));

  NSLog(@"(lcount, (list, 1, 2, nil, 3)) should be: 3 == %@", nsMudTestEvaluate(@[@501, @[@500, @1, @2, @[@120, @"unknown"], @3]]));

  NSLog(@"(lnth, (list, 1, 2, 3), 0) should be: 1 == %@", nsMudTestEvaluate(@[@502, @[@500, @1, @2, @3], @0]));
  NSLog(@"(lnth, (list, 1, 2, 3), 1) should be: 2 == %@", nsMudTestEvaluate(@[@502, @[@500, @1, @2, @3], @1]));

  NSLog(@"ok");
}