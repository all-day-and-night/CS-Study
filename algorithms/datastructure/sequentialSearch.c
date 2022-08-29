#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define LENGTH 100

char **array;
int founded;

int main() {
    int n;
    char *word;
    word = (char*)malloc(sizeof(char)*LENGTH);
    scanf("%d %s", &n, word);
    array = (char**)malloc(sizeof(char*)*LENGTH);
    for(int i=0; i<n ; i++){
        array[i] = (char*)malloc(sizeof(char)*LENGTH);
        scanf("%s", array[i]);
    }
    for(int i=0; i<n; i++){
        if(!strcmp(word, array[i])) {
            printf("%dst element.\n", (i+1));
            founded++;
        }
    }
    if(!founded) printf("couldn't find the elements.");
    else{
        printf("%d elements is here. by sequential search\n", founded);
    }
    return 0;
}