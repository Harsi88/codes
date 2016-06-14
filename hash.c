#include<stdio.h>
#include<stdlib.h>

typedef struct listl{
    char *s;
    struct listl *next;
}listl;

typedef struct ht{
    int size;
    listl **tab;
}ht;

ht *myht;
int tabsize=100;

ht *createtable(int s){
    ht *newtab;
    if(s<1)return NULL;
    if((newtab=malloc(sizeof(ht)))==NULL)return NULL;
    if((newtab->tab=malloc(sizeof(list*)*s))==NULL)return NULL;
    for(i=0;i<s;++i){
    newtab->tab[i]=NULL;
    }
    newtab->size=s;
    return newtab;
}
myht = createtable(tabsize);
