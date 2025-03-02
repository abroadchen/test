#include <database.h>
static const char *table_name = "class2 table";


__attribute__((constructor))
static void __register_table() {
    register_table(table_name);
    return;
}
