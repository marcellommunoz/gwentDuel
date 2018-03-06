#include <stdio.h>
#include <stdlib.h>

struct unit{
    char cod;
    int dmg;
    int danoTotal;
};

int main(){
    struct unit x, y;
    printf("\t----CALCULATION OF DUEL IN GWENT----\n");
    x.cod = 'A';
    printf("UNIT A:\n");
    scanf("%d", &(x.dmg));
    maxDuelGwent(x);
    return 0;
}

void maxDuelGwent(struct unit x){
    struct unit y;
    y.cod = 'Y';
    y.dmg = x.dmg;
    while(duelGwent(x, y) == 0){
        y.dmg++;
    }
    printf("\n\nUNIT WON WITH MOST POWER %d\n\n", y.dmg-1);
}

int duelGwent(struct unit x, struct unit y){
    int hits = 0;
    printf("\n\t----UNIT BEFORE DUEL----\n");
    printf("%c - %d\n%c - %d\n", x.cod, x.dmg, y.cod, y.dmg);
    printf("\n\t----LOG----\n");
    while(x.dmg > 0 && y.dmg > 0){
        printf("\n\t--ROUND %d--\n", hits+1);
        printf("unit %c hits %c\n", x.cod, y.cod);
        y.dmg = y.dmg - x.dmg;
        if(y.dmg > 0){
            printf("survives with %d\n", y.dmg);
            printf("unit %c hits %c\n", y.cod, x.cod);
            x.dmg = x.dmg - y.dmg;
            if(x.dmg > 0){
                printf("survives with %d\n", x.dmg);
            }
            else{
                printf("unit %c dies\n", x.cod);
            }
        }else{
            printf("unit %c dies\n", y.cod);
        }
        printf("%c - %d\n%c - %d\n", x.cod, x.dmg, y.cod, y.dmg);
        hits++;
    }
    printf("\n\t----RESULT----\n");
    if(x.dmg > 0){
        printf("unit %c won\n\n", x.cod);
        return 0;
    }
    else{
        printf("unit %c won\n\n", y.cod);
        return 1;
    }
}
