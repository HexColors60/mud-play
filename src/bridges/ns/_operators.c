// auto-generated: operators import - begin
#import "../../operators/arithmetics.c"
#import "../../operators/string.c"
#import "../../bridges/ns/operators/ns.m"
// auto-generated: operators import - end

mud_object_t * _mud_expr_evaluate(mud_expr_t * expr) {
  mud_object_t * ret;
  mud_expr_evaluator_t * evaluator = mud_expr_evaluator_init(expr);
  // printf("%p\n", evaluator);
  // mud_object_t ** args = expr->args;
  switch (expr->oper) {
// auto-generated: operators switch - begin
    case MUD_OP_ARITHMETIC_ADDING:
      ret = _mud_op_arithmetic_adding_evaluate(evaluator);
      break;
    case MUD_OP_STRING_CONCAT:
      ret = _mud_op_string_concat_evaluate(evaluator);
      break;
    case MUD_OP_STRING_FORMAT:
      ret = _mud_op_string_format_evaluate(evaluator);
      break;
// auto-generated: operators switch - end
    default:
      mud_error(@"Unknown operator: %lu", expr->oper);
      ret = mud_nil_init();
      break;
  }

  mud_expr_evaluator_free(evaluator);
  return ret;
}
