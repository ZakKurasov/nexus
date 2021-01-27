#include <stdio.h>

typedef struct database_query_result database_query_result_t;
typedef struct database_query_row database_query_row_t;

typedef struct database_driver
{
    const char* name;

    void* (*spawn_context_impl)();
    int (*connect_impl)(void* ctx, const char* uri);
    int (*query_impl)(void* ctx, const char* query, database_query_result_t* result);
}
database_driver_t;

int database_driver_sqlite_query(void* ctx, const char* query, database_query_result_t* result)
{
    return 0;
}

database_driver_t g_database_drivers[] = {
    {
        .name = "sqlite3",
        .query_impl = database_driver_sqlite_query
    }
};

typedef struct database_connection
{
    database_driver_t* driver;
    void* driver_context;
}
database_connection_t;

int database_connection_connect(database_connection_t* conn, const char* driver, const char* uri)
{
    return 0;
}
int database_connection_query(database_connection_t* conn, const char* query, database_query_result_t* result)
{
    return conn->driver->query_impl(conn->driver_context, query, result);
}

int main() {
    printf("Hello, World!\n");
    return 0;
}
