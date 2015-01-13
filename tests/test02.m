#import "support.m"

int main() {

  NSDictionary * json = openAndParseJson(@"fixtures/test02.json");

  // [+, 0.9, "49.1", [+, 10, 25, 15]]
  NSLog(@"t01e should be: 100 ==  %@", nsMudTestEvaluate([json objectForKey: @"01"]));

  // [-, "100", 200, -50, [-, 51]]
  NSLog(@"t02e should: 1 == %@", nsMudTestEvaluate([json objectForKey: @"02"]));


  NSLog(@"ok");
}