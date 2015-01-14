#import "support.m"

int main() {

  NSDictionary * json = openAndParseJson(@"fixtures/test03.json");

  // [concat, "Hell", "o", " world! ", 2014]
  NSLog(@"t01e should be: Hello world! 2014 = %@", nsMudTestEvaluate([json objectForKey: @"01"]));

  // [format, "%s %s %lf", "PI", "is", 3.1415926535]
  NSLog(@"t02e should be: PI is 3.14159275 你好 = %@", nsMudTestEvaluate([json objectForKey: @"02"]));

  // [format, "%s %s %lf", "PI", "is", 3.1415926535]
  NSLog(@"t03e should be: %@", nsMudTestEvaluate([json objectForKey: @"03"]));

  // [format, "format with no arguments"]
  NSLog(@"t04e should be: %@", nsMudTestEvaluate([json objectForKey: @"04"]));

  // [format, 1024]
  NSLog(@"t05e should: 1024 = %@", nsMudTestEvaluate([json objectForKey: @"05"]));

  // [strlen, "Hello world! 你好世界！"]
  NSLog(@"t06e should: 28 = %@", nsMudTestEvaluate([json objectForKey: @"06"]));

  // [strstr, "Hello world! 你好世界！", "world"]
  NSLog(@"t07e should: 6 = %@", nsMudTestEvaluate([json objectForKey: @"07"]));

  // [strstr, "Hello world! 你好世界！", "你好"]
  NSLog(@"t08e should: 13 = %@", nsMudTestEvaluate([json objectForKey: @"08"]));

  // [strstr, "Hello world! 你好世界！", "404"]
  NSLog(@"t09e should: <null> = %@", nsMudTestEvaluate([json objectForKey: @"09"]));


  NSLog(@"ok");
}