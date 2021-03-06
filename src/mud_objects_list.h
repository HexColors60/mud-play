#define MUD_LIST_ALLOC_SIZE 8

typedef struct mud_list_s mud_list_t;
struct mud_list_s {
  mud_object_t **       objects;
  size_t                count;
  size_t                size;
};

typedef struct mud_list_sort_by_s mud_list_sort_by_t;
struct mud_list_sort_by_s {
  mud_object_t *        object;
  void *                _ptr;
  mud_int_t             _int;
  mud_float_t           _float;
};

mud_list_t * mud_list_alloc();
mud_list_t * mud_list_alloc_with_size(size_t size);
void mud_list_free(mud_list_t * list);

mud_list_t * _mud_list_init_with_args(mud_object_t ** args, size_t count);
mud_object_t * _mud_object_list_init_with_args(mud_gc_stack_t * stack, mud_object_t ** args, size_t count);

mud_boolean_t _mud_list_check(mud_object_t * object);
void _mud_list_resize(mud_list_t * list);

void mud_list_append(mud_list_t * list, mud_object_t * item);
void mud_list_prepend(mud_list_t * list, mud_object_t * item);
void mud_list_push(mud_list_t * list, mud_object_t * item, mud_int_t pos);
void mud_list_replace(mud_list_t * list, mud_object_t * item, mud_int_t pos);
void mud_list_remove(mud_list_t * list, mud_int_t pos);

void mud_list_flatten_to(mud_list_t * new_list, mud_list_t * cur_list, mud_boolean_t shallow, mud_boolean_t first_level);

mud_int_t mud_list_find(mud_expr_evaluator_t * evaluator, mud_list_t * list, mud_object_t * to_find);

mud_list_t * mud_list_alloc_uniq(mud_list_t * list, mud_expr_evaluator_t * evaluator);

mud_list_t * mud_list_alloc_intersection(mud_expr_evaluator_t * evaluator, mud_list_t * a_list, mud_list_t * b_list);
mud_list_t * mud_list_alloc_difference(mud_expr_evaluator_t * evaluator, mud_list_t * a_list, mud_list_t * b_list);
mud_list_t * mud_list_alloc_concat(mud_expr_evaluator_t * evaluator, mud_list_t * a_list, mud_list_t * b_list);
mud_list_t * mud_list_alloc_union(mud_expr_evaluator_t * evaluator, mud_list_t * a_list, mud_list_t * b_list);

extern mud_object_t *                _mud_list_sort_lambda;
extern mud_expr_evaluator_t *        _mud_list_sort_evaluator;
extern mud_object_t **               _mud_list_sort_args;
extern mud_scope_t *                 _mud_list_sort_scope;
extern mud_gc_stack_t *              _mud_list_sort_stack;

int _mud_list_sort_by_compare_lambda(const void * a, const void * b);

int _mud_list_sort_by_compare_int(const void * a, const void * b);
int _mud_list_sort_by_compare_float(const void * a, const void * b);
int _mud_list_sort_by_compare_str(const void * a, const void * b);
int _mud_list_sort_by_compare_ptr(const void * a, const void * b);

mud_list_sort_by_t * mud_list_sort_by_alloc(mud_expr_evaluator_t * evaluator, mud_object_t * object, mud_object_type_e sort_by_type);
void mud_list_sort_bies_sort(mud_list_sort_by_t ** sort_bies, size_t count, mud_object_type_e sort_by_type);

mud_int_t _mud_list_prepare_index(mud_list_t * list, mud_int_t i);