#include <database.h>
#include <stddef.h>
#include <stdio.h>
static const char *table_name = "class table";
static const char *table_file = "./data/class_data.dat";
const char *header_name[] = {"name", "No.Stu", "master"};
static int header_len[] = {15, 7, 15};

typedef struct {
    char name[20];
    int NoStu;
    char master[20];
} table_data;

#include "table_unit.x"

static void printData(void *__data) {
    table_data *data = (table_data *)(__data);
    char frm[100];
    sprintf(frm, "%%%ds|%%%dd|%%%ds|", 
           header_len[0], header_len[1],
            header_len[2], header_len[3]);
    printf(frm, data->name, data->NoStu, data->master);
    printf("\n");
    return;
}

static void scanData(void *__data) {
    table_data *data = (table_data *)(__data);
    scanf("%s%d%s", 
          data->name, &(data->NoStu), 
          data->master);
    return;
}
