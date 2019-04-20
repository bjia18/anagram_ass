#include <stdio.h>
#include "dictionary.h"
#include <string.h>
#include <ctype.h>

int sort_func(const void *a, const void *b){
    return *(char*)a-*(char*)b;
}

int main(){
    DNode *dict[DEFAULT_HASH_SIZE];
    for (int i=0;i<DEFAULT_HASH_SIZE;i++){
        dict[i]=NULL;
    }
    FILE *pt=fopen("words.txt","r");
    char buf[30];
    while (fscanf(pt, "%s", buf)!=EOF){
        char *key=copystr(buf);
        qsort(key, strlen(key), sizeof(char), sort_func);
        set(dict, DEFAULT_HASH_SIZE, key, buf);
        free(key);
    }
    int count=0;
    DNode *terms;
    for (int i=0;i<DEFAULT_HASH_SIZE;i++){
        if (dict[i]!=NULL){
            terms=get(dict, DEFAULT_HASH_SIZE, dict[i]->key);
            VNode *head=(terms->values)->next;
            if (head!=NULL){
                printf("anagrams of %s: \n",(terms->values)->value);
                while (head){
                    printf("%s\n",head->value);
                    head=head->next;
                }
                count++;
            }
        }
    }
    printf("total anagram lists= %d\n", count);
    free_dictionary(dict, DEFAULT_HASH_SIZE);
    fclose(pt);
    return 0;

}