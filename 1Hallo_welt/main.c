#include <stdio.h>
#include <string.h>

int main(){
    int x=0, y=0;
    char bname[] = "root";
    char bnametry[] = "";
    char pname[] = "tool";
    char pnametry[] = "";

    do {
        printf("Username: "); scanf("%s", &bnametry);
        while(getchar() != '\n');
        printf("Passwort: "); scanf("%s", &pnametry);
        while(getchar() != '\n');

        if (strcmp(pname, pnametry) == 1){
            printf("Wrong password\n");
        }
        if (strcmp(bname, bnametry) == 1){
            printf("Wrong username\n");
        }
        
    }while(strcmp(bname, bnametry) == 0 && strcmp(pname, pnametry) == 0);

    printf("Wellcome: %s\n", bnametry);

    return 0;
}