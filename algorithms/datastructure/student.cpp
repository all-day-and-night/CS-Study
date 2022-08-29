#include<iostream>
#include<cstdlib>
#include<cstring>

typedef struct {
    char name[20];
    int score;
} Student;

int main(void) { int n, sum = 0; FILE *fp; fp = fopen("input.txt", "r"); fscanf(fp, "%d", &n); Student *students = (Student*)malloc(sizeof(Student) * n); for (int i = 0; i < n; i++) { fscanf(fp, "%s %d", &((students + i)->name), &((students + i)->score)); } for (int i = 0; i < n; i++) { sum += (students + i)->score; } free(students); fclose(fp); printf("점수 평균: %.2f\n", (double)sum / n); system("pause"); return 0; }
/*
int main() {
    int n, sum =0;
    FILE * fp;
    fp = fopen("input.txt", "r");
    fscanf(fp, "%d", &n);
    Student * students = (Student*)malloc(sizeof(Student)*n);
    for(int i=0; i<n ; i++){
        fscanf(fp, "%s %d", &((students+i)->name), &((students)->score));
        printf("이름 : %s\n, 성적 : %d\n",(students+i)->name, (students+i)->score);
    }
    for(int i=0; i<n; i++){
        sum += (students+i)->score;
    }
    free(students);
    fclose(fp);
    printf("성적 평균: %.2f \n", (double)sum/n);
    return 0;
}*/