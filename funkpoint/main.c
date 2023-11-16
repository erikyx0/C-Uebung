#include <stdio.h>
int Arraysize(int NUmarr[]);
void sortNumbers(int arr[], int size, int (*compare)(int, int));


int main(int argc , char **argv){
    int NUMarr[] = {1, 2, 3, 4, 5, 6, 7, 7};
    
    int NUMsize = Arraysize(NUMarr);
    int (*NUMcompaire)(int, int) = NUMcompairison();

    sortNumbers(NUMarr, NUMsize, NUMcompaire){

    }

    return 0;
}

int Arraysize(int NUmarr[]){
    int size = 0;
    for (int i=0; NUmarr[i] != 0; i++){
        size++;
    }
    return size;
}
int (*NUMcompairison())(int, int){

}
void sortNumbers(int arr[], int size, int (*compare)(int, int)){


}