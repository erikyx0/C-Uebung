#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct Student{
    struct student *next;
    char vorname[30];
    char nachname[30];
    char geburtstag[11];
    int matrikelnummer;
    char studiengang[20];
    bool semester;  // 1 = Sommer und 0 = Winter
}student;

typedef struct{
    student *head;
    int amount;
}list;

void ausgabeStudent(student *stud);
void studengangWechel(student *stud, char *neuerStudengang);
student *neuesEnde(
    list *head,
    char vorname[30],
    char nachname[30],
    char geburtstag[11],
    int matrikelnummer,
    char studiengang[20],
    bool semester);

int main(void){
    list students;
    student *s1 = calloc(1, sizeof(student));
    s1->next = NULL;
    strcpy(s1->vorname, "Ben");
    strcpy(s1->nachname, "Weckend");
    strcpy(s1->geburtstag, "03.02.2003");
    strcpy(s1->studiengang, "Robotik");
    s1->matrikelnummer = 67551;
    s1->semester = 0;

    students.head = s1;
    students.amount = 1;
    neuesEnde(students, "Tom", "Weckend", "08.06.1962", 12345, "Auto", 0);

    student *s = students.head;
    for(int i=0; i<=students.amount; i++){
        ausgabeStudent(s);
        s = s->next;
    }
    return 0;
}

void ausgabeStudent(student *stud){
    char semest[7];
    if(stud->semester) strcpy(semest, "sommer");
    else strcpy(semest, "winter");
    printf("\nName: %s %s \nStudiengang: %s \nMatrikelnummer: %d \nGeburststag: %s \nSemesterbeginn: %s \n\n", stud->vorname, stud->nachname, stud->studiengang, stud->matrikelnummer, stud->geburtstag, semest);
}

void studengangWechel(student *stud, char *neuerStudengang){
    ausgabeStudent(stud);
    strcpy(stud->studiengang, neuerStudengang);
    ausgabeStudent(stud);
}

student *neuesEnde(
    list head,
    char vorname[30],
    char nachname[30],
    char geburtstag[11],
    int matrikelnummer,
    char studiengang[20],
    bool semester){
        student *neu = calloc(1, sizeof(student));
        strcpy(neu->vorname, vorname);
        strcpy(neu->nachname, nachname);
        strcpy(neu->geburtstag, geburtstag);
        strcpy(neu->studiengang, studiengang);
        neu->matrikelnummer = matrikelnummer;
        neu->semester = semester;

        student *kopf = head.head;
        if(head.amount == 0) return neu;
        else{while(kopf->next != NULL) kopf = kopf->next;}
        kopf->next = neu;
        neu->next = NULL;
        return head.head;
}
