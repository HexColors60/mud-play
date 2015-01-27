/*
  list
    - list:      500
    - lcount:    501
    - lnth:      502
    - lappend:   503
    - lprepend:  504
    - lpush:     505
    - lreplace:  506
    - lremove:   507
    - lfind:     508
*/

mud_int_t _mud_list_prepare_index(mud_list_t * list, mud_int_t i) {
  if ( i < 0 ) {
    i = list->count + i;
  }
  return i;
}

mud_object_t * _mud_op_list_list_evaluate(mud_expr_evaluator_t * evaluator) {
// Enum: 500
  mud_object_t * ret = mud_object_alloc(MUD_OBJ_TYPE_LIST);
  ret->ptr = mud_list_alloc();
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
  mud_object_t * org = ME_ARG(0);
  mud_list_t * list = (mud_list_t *)org->ptr;
  mud_int_t i = ME_ARG_INT(1);
  if ( i < ME_ARGC ) {
    return list->objects[_mud_list_prepare_index(list, i)];
  } else {
    return mud_nil_init();
  }
}

mud_object_t * _mud_op_list_append_evaluate(mud_expr_evaluator_t * evaluator) {
// Enum: 503
  mud_object_t * list = ME_ARG(0);
  for ( unsigned i = 1; i < ME_ARGC; i++ ) {
    mud_object_t * arg = ME_ARG(i);
    if ( arg->type != MUD_OBJ_TYPE_NIL ) {
      mud_list_append((mud_list_t *)list->ptr, arg);
    }
  }
  return list;
}

mud_object_t * _mud_op_list_prepend_evaluate(mud_expr_evaluator_t * evaluator) {
// Enum: 504
  mud_object_t * list = ME_ARG(0);
  for ( unsigned i = ME_ARGC; i > 0; i-- ) {
    mud_object_t * arg = ME_ARG(i);
    if ( arg->type != MUD_OBJ_TYPE_NIL ) {
      mud_list_prepend((mud_list_t *)list->ptr, arg);
    }
  }
  return list;
}

mud_object_t * _mud_op_list_push_evaluate(mud_expr_evaluator_t * evaluator) {
// Enum: 505
  mud_object_t * org = ME_ARG(0);
  mud_list_t * list = (mud_list_t *)org->ptr;
  mud_int_t pos;
  if ( ME_ARGC > 2 ) {
    pos = _mud_list_prepare_index(list, ME_ARG_INT(2));
  } else {
    pos = list->count;
  }
  mud_list_push(list, (mud_object_t *)ME_ARG(1), pos);
  return org;
}

mud_object_t * _mud_op_list_replace_evaluate(mud_expr_evaluator_t * evaluator) {
// Enum: 506
  mud_object_t * ret = ME_ARG(0);
  mud_object_t * rep = ME_ARG(1);
  mud_list_t * list = (mud_list_t *)ret->ptr;
  if ( ME_ARGC > 2 ) {
    mud_list_replace(list, rep, _mud_list_prepare_index(list, ME_ARG_INT(2)));
  } else {
    for ( unsigned i = 0; i < list->count; i++ ) {
      mud_list_replace(list, rep, i);
    }
  }
  return ret;
}

mud_object_t * _mud_op_list_remove_evaluate(mud_expr_evaluator_t * evaluator) {
// Enum: 507
  mud_object_t * ret = ME_ARG(0);
  mud_list_t * list = (mud_list_t *)ret->ptr;
  mud_list_remove(list, _mud_list_prepare_index(list, ME_ARG_INT(1)));
  return ret;
}

mud_object_t * _mud_op_list_find_evaluate(mud_expr_evaluator_t * evaluator) {
// Enum: 508
  mud_object_t * obj = ME_ARG(0);
  mud_int_t pos = mud_list_find((mud_list_t *)obj->ptr, evaluator->pool, ME_ARG(1));
  if ( pos == -1 ) {
    return mud_nil_init();
  } else {
    return mud_int_init(pos);
  }
}

