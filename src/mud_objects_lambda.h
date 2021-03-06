typedef struct mud_lambda_s mud_lambda_t;
struct mud_lambda_s {
  size_t argc;
  char ** args_names;
  mud_object_t * block;
};


mud_lambda_t * mud_lambda_alloc();
void mud_lambda_free(mud_lambda_t * lambda);

void _mud_lambda_set_args_names(mud_lambda_t * lambda, size_t argc, char ** args_names);

mud_object_t * mud_lambda_apply(mud_lambda_t * lambda, mud_scope_t * scope, mud_gc_stack_t * stack, mud_object_t ** args, size_t argc);

mud_object_t * _mud_lambda_object_apply(mud_object_t * obj, mud_scope_t * scope, mud_gc_stack_t * stack, mud_object_t ** args, size_t argc);