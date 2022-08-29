#include<stdio.h>
#include<string.h>

char * parent = "ABCDEFG";
char * pattern = "EF";

int main () {
    int parentSize = strlen(parent);
    int patternSize = strlen(pattern);
    for(int i = 0; i <= parentSize - patternSize; i++){
        int found =1;
        for(int j=0; j<patternSize ; j++){
            if(parent[i+j] != pattern[j]) {
                found = 0;
                break;
            }  
        }
        if(found) {
            printf("I found the pattern at %d index", i+1);
        }
    }
    system("pause");
    return 0;
}
