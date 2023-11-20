#include <stdio.h>
#define M_PI 3.14159263

double earth(int r){
    double density = 5.51;
    double volume = (double)(4/3)* M_PI * (double) (r^3);
    return volume * density;
}
double venus(int r){
    double density = 5.24;
    double volume = (double)(4/3)* M_PI * (double) (r^3);
    return volume * density;
}
double mars(int r){
    double density = 3.93;
    double volume = (double)(4/3)* M_PI * (double) (r^3);
    return volume * density;
}


double (*planet())(int){
    int ch=0;
    printf("Which planet?: earth(1), venus(2), mars(3): ");
    scanf("%d", &ch);
    switch (ch)
    {
    case 1: return earth; break;
    case 2: return venus; break;
    case 3: return mars; break;    
    default: return NULL; break;
    }
} 
int main(){
    int r=0;
    printf("radius: "); scanf("%d", &r);
    double (*planetchoice)(int) = planet();

    printf("%lf\n",planetchoice(r));
    return 0;
}