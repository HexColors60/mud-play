typedef struct mud_scope_s mud_scope_t;
typedef struct mud_scope_vars_s mud_scope_vars_t;

struct mud_scope_s {
  mud_scope_t *         prev;
  mud_scope_vars_t *    vars;
};

struct mud_scope_vars_s {
    const char *    name;
    mud_object_t *  value;
    mud_scope_t *   belongs_to;
    UT_hash_handle  hh;
};



mud_scope_t * mud_scope_init();
void mud_scope_free(mud_scope_t * scope);

mud_scope_t * mud_scope_push(mud_scope_t * scope);

mud_object_t * mud_scope_get(mud_scope_t * scope, const char * name);
void mud_scope_set(mud_scope_t * scope, const char * name, mud_object_t * value);