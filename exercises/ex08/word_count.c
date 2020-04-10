#include <stdio.h>
#include <stdlib.h>
#include <glib.h>
#include <glib/gprintf.h>
#include <gmodule.h>

#define MAXCHAR 1000

void print_pair(char *key, int *value){
    g_printf("%s: %i\n", key, *value);
}

int main(int argc, char** argv) {
    char* filename = "jane.txt";
    char str[MAXCHAR];
    GHashTable *hashmap = g_hash_table_new(g_str_hash, g_str_equal);
 
    FILE *fp = fopen(filename, "r");
    if (fp == NULL){
        printf("Could not open file %s",filename);
        return 1;
    }

    while (fgets(str, MAXCHAR, fp) != NULL) {
        gchar *g_str = str;
        gchar** tokens = g_strsplit(g_str, " ", 100);
        int i = 0;
        while (tokens[i] != NULL) {
            int *valptr;
            int val;
            valptr = g_hash_table_lookup(hashmap, tokens[i]);
            if (valptr != NULL) {
                val = *valptr + 1;
            } else {
                val = 1;
            }
            valptr = &val;
            g_hash_table_insert(hashmap, tokens[i], valptr);
            i++;
        }
    }

    g_hash_table_foreach (hashmap, (GHFunc)print_pair, NULL);
    fclose(fp);

    return 0;
}