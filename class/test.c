#include<stdio.h>
int main(){
    char s[200];
    // scanf("%s", &s);
    // printf("%s", s);

    fgets(s, sizeof(s), stdin);
    printf("Your name is %s", s);
}

