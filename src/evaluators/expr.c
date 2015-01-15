mud_expr_evaluator_t * mud_expr_evaluator_init(mud_expr_t * expr) {
  mud_expr_evaluator_t * evaluator = (mud_expr_evaluator_t *)malloc(sizeof(mud_expr_evaluator_t));
  
  size_t args_size = expr->argc * sizeof(mud_object_t *);
  evaluator->args = (mud_object_t **)malloc(args_size);
  memset(evaluator->args, 0, args_size);
  evaluator->orgs = expr->args;
  // for (unsigned i = 0; i < expr->argc; i++) {
  //   evaluator->args[i] = mud_evaluate(expr->args[i]);
  // }
  evaluator->argc = expr->argc;

  evaluator->pool = mud_object_casting_pool_init();
  return evaluator;
}

void mud_expr_evaluator_free(mud_expr_evaluator_t * evaluator) {
  free(evaluator->args);
  evaluator->args = NULL;
  evaluator->orgs = NULL;
  mud_object_casting_pool_free(evaluator->pool);
  evaluator->pool = NULL;
  evaluator->argc = 0;
  free(evaluator);
}

mud_object_t * _mud_expr_evaluator_get(mud_expr_evaluator_t * evaluator, unsigned i) {
  if ( evaluator->argc > i ) {
    // return evaluator->args[i];
    if ( !evaluator->args[i] ) {
      evaluator->args[i] = mud_evaluate(evaluator->orgs[i]);
    }
    return evaluator->args[i];
  } else {
    return mud_nil_init();
  }
}