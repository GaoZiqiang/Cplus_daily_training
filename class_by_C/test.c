#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct book{
    int id;
    char * name;
    int hash;
};


typedef struct bookCreate {
    int (*hashcode)(const void *name);
    void *(*bookInit)(int id, const void *name);

} bookCreate;

int hashcode(const void *name) {

    if(strcmp(name, "c++")){
        return 100;
    }else if(strcmp(name, "python")){
        return 90;
    }else if(strcmp(name, "plsql")){
        return 80;
    }

    return 60;
};

void *bookInit(int id, const void *name) {

    int hash = hashcode(name);

    struct book * b = NULL;
    b = (struct book *)malloc(sizeof(*b));
    b->id = id;
    b->name = name;
    b->hash = hash;

    return b;

}

int main(){

    char *name = "plsql";
    bookCreate bc = {.hashcode=hashcode,.bookInit=bookInit};
    int hash = bc.hashcode(name);

    printf("hash=%d \n",hash);

    struct book *b = bc.bookInit(18,name);
    printf("b.id=%d,b.hash=%d,b.name=%s \n",b->id,b->hash,b->name);


    return 1;

}

