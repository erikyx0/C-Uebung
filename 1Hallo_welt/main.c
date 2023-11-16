#include <stdio.h>
#include <string.h>

int main(){
    char bname[] = "root";
    char bnametry[100];
    char pname[] = "tool";
    char pnametry[100];
    int result, result2;
    
    do {
        
        int x=0;
        printf("Username: "); scanf("%s", &bnametry);
        while(getchar() != '\n');
        printf("Passwort: "); scanf("%s", &pnametry);
        while(getchar() != '\n');

        result = strcmp(pname, pnametry);
        result2 = strcmp(bname, bnametry);


        if (result2 == 1){
            printf("Wrong password\n");
            x++;
        }
        if (result  == 1){
            printf("Wrong username\n");
            x++;
        }
        if (x!=0) printf("Try again!\n"); 
        
    }while(result2 == 1 || result == 1);

    printf("Wellcome: %s\n", bnametry);

    return 0;
}