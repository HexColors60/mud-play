typedef enum {
// auto-generated: operators enum - begin
  MUD_OP_BASE_QUOTE = 100,
  MUD_OP_BASE_EVAL = 101,
  MUD_OP_BASE_EXPR = 102,
  MUD_OP_BASE_EARGS = 103,
  MUD_OP_COND_IF = 111,
  MUD_OP_COND_WHEN = 112,
  MUD_OP_COND_UNLESS = 113,
  MUD_OP_SCOPE_GET = 120,
  MUD_OP_SCOPE_SET = 121,
  MUD_OP_SCOPE_ARG = 122,
  MUD_OP_SCOPE_ARGC = 123,
  MUD_OP_LAMBDA_LAMBDA = 130,
  MUD_OP_LAMBDA_APPLY = 131,
  MUD_OP_BOOLEAN_NOT = 190,
  MUD_OP_BOOLEAN_AND = 191,
  MUD_OP_BOOLEAN_OR = 192,
  MUD_OP_ARITHMETIC_ADDING = 200,
  MUD_OP_ARITHMETIC_SUBTRACTING = 201,
  MUD_OP_ARITHMETIC_MULTIPLYING = 202,
  MUD_OP_ARITHMETIC_DIVIDING = 203,
  MUD_OP_ARITHMETIC_REMAINDER = 204,
  MUD_OP_INT_ROUND = 210,
  MUD_OP_INT_FLOOR = 211,
  MUD_OP_INT_CEIL = 212,
  MUD_OP_INT_RAND = 213,
  MUD_OP_FLOAT_POW = 205,
  MUD_OP_FLOAT_ABS = 206,
  MUD_OP_FLOAT_LOG = 207,
  MUD_OP_FLOAT_EXP = 208,
  MUD_OP_FLOAT_COS = 220,
  MUD_OP_FLOAT_SIN = 221,
  MUD_OP_FLOAT_TAN = 222,
  MUD_OP_FLOAT_ACOS = 223,
  MUD_OP_FLOAT_ASIN = 224,
  MUD_OP_FLOAT_ATAN = 225,
  MUD_OP_FLOAT_ATAN2 = 226,
  MUD_OP_FLOAT_LOG10 = 227,
  MUD_OP_FLOAT_LOG1P = 228,
  MUD_OP_FLOAT_LOG2 = 229,
  MUD_OP_COMPARE_EQ_TO = 290,
  MUD_OP_COMPARE_NOT_EQ_TO = 291,
  MUD_OP_COMPARE_GT = 292,
  MUD_OP_COMPARE_LT = 293,
  MUD_OP_COMPARE_GT_OR_EQ = 294,
  MUD_OP_COMPARE_LT_OR_EQ = 295,
  MUD_OP_STRING_CONCAT = 300,
  MUD_OP_STRING_FORMAT = 301,
  MUD_OP_STRING_STRLEN_BYTE = 302,
  MUD_OP_STRING_STRSTR_BYTE = 303,
  MUD_OP_STRING_SUBSTR_BYTE = 304,
  MUD_OP_STRING_STRLEN = 305,
  MUD_OP_STRING_STRSTR = 306,
  MUD_OP_STRING_SUBSTR = 307,
  MUD_OP_STRING_STRREP = 308,
  MUD_OP_STRING_JOIN = 309,
  MUD_OP_REGEX_REGEX = 310,
  MUD_OP_REGEX_TEST = 311,
  MUD_OP_REGEX_MATCH = 312,
  MUD_OP_REGEX_MATCH_ALL = 313,
  MUD_OP_REGEX_REP_ALL = 314,
  MUD_OP_LIST_LIST = 500,
  MUD_OP_LIST_COUNT = 501,
  MUD_OP_LIST_NTH = 502,
  MUD_OP_LIST_APPEND = 503,
  MUD_OP_LIST_PREPEND = 504,
  MUD_OP_LIST_PUSH = 505,
  MUD_OP_LIST_REPLACE = 506,
  MUD_OP_LIST_REMOVE = 507,
  MUD_OP_LIST_FIND = 508,
  MUD_OP_LIST_STR = 509,
  MUD_OP_LIST_REVERSE = 510,
  MUD_OP_LIST_FLATTEN = 511,
  MUD_OP_LIST_UNIQ = 512,
  MUD_OP_LIST_INTERSECTION = 513,
  MUD_OP_LIST_DIFFERENCE = 514,
  MUD_OP_LIST_CONCAT = 515,
  MUD_OP_LIST_UNION = 516,
  MUD_OP_LIST_HEAD = 517,
  MUD_OP_LIST_TAIL = 518,
  MUD_OP_LIST_SLICE = 519,
  MUD_OP_LIST_EACH = 520,
  MUD_OP_LIST_MAP = 521,
  MUD_OP_LIST_REDUCE = 522,
  MUD_OP_LIST_FILTER = 523,
  MUD_OP_LIST_REJECT = 524,
  MUD_OP_LIST_SORT_BY = 525,
  MUD_OP_LIST_SORT = 526,
  MUD_OP_LIST_ALL = 527,
  MUD_OP_LIST_ANY = 528,
  MUD_OP_HASH_TABLE_HT = 600,
  MUD_OP_HASH_TABLE_COUNT = 601,
  MUD_OP_HASH_TABLE_GET = 602,
  MUD_OP_HASH_TABLE_SET = 603,
  MUD_OP_NS_INFO = 1200
// auto-generated: operators enum - end
} mud_operator_e;
