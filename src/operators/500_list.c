/*
  list
    - list:   500
    - lcount: 501
    - lnth:   502
*/

mud_boolean_t _mud_list_check(mud_object_t * object) {
  return object->type == MUD_OBJ_TYPE_LIST;
}

mud_object_t * _mud_op_list_list_evaluate(mud_expr_evaluator_t * evaluator) {
// Enum: 500
  mud_object_t * ret = mud_object_alloc(MUD_OBJ_TYPE_LIST);
  ret->ptr = mud_list_init();
  for ( unsigned i = 0; i < ME_ARGC; i++ ) {
    mud_object_t * arg = ME_ARG(i);
    if ( arg->type != MUD_OBJ_TYPE_NIL ) {
      mud_list_append((mud_list_t *)ret->ptr, (mud_object_t *)ME_ARG(i));
    }
  }
  return ret;
}

mud_object_t * _mud_op_list_count_evaluate(mud_expr_evaluator_t * evaluator) {
// Enum: 501
  mud_object_t * list = ME_ARG(0);
  if ( _mud_list_check(list) ) {
    return mud_int_init( ( (mud_list_t *) list->ptr )->count );
  } else {
    return mud_int_init(0);
  }
}

mud_object_t * _mud_op_list_nth_evaluate(mud_expr_evaluator_t * evaluator) {
// Enum: 502
  mud_object_t * list = ME_ARG(0);
  return ( ( mud_list_t * ) list->ptr)->objects[ME_ARG_INT(1)];
}
