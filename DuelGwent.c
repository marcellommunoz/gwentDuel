#include <stdio.h>
#include <stdlib.h>

struct unit{
    char cod;
    int dmg;
};

double maxDuelGwent(struct unit x, int terminal);
int duelGwent(struct unit x, struct unit y, int terminal);

int main(){

    struct unit x;
    x.cod = 'X';
    //x.dmg = 10;
    //struct unit y;
    //y.cod = 'Y';
    //y.dmg = 5;
    printf("\t----CALCULATION OF DUEL IN GWENT----\n");
    double maxValue, result;
    maxValue = 0;
    int i;
    for(i = 1; i< 100000; i++){
        x.dmg = i;
        printf("UNIT %c: %d\n", x.cod, x.dmg);
        result = maxDuelGwent(x, 0);
        printf("%f\n", result);
        if(maxValue < result){
            maxValue = result;
        }
    }

    //printf("UNIT %c: %d\n", y.cod, y.dmg);
    //result = maxDuelGwent(x, 1);
    //result = duelGwent(x, y, 1);
    printf("\t---RESULT---\nMOST VALUE: %f", maxValue);
    return 0;
}

double maxDuelGwent(struct unit x, int terminal){
    struct unit y;
    int terminalDuel = 0;
    y.cod = 'Y';
    y.dmg = x.dmg;
    if(terminal == 2){
        terminalDuel = 1;
    }
    while(duelGwent(x, y, terminal) == 0){
        y.dmg++;
    }
    if(terminal == 2){
        printf("\n\nUNIT WON WITH MOST POWER %d\n\n", y.dmg-1);
    }
    double a, b;
    a = y.dmg-1;
    b = x.dmg;
    double result = (a/b);
    return result;
}

int duelGwent(struct unit x, struct unit y, int terminal){
    int hits = 0;
    if(terminal == 1){
        printf("\n\t----UNIT BEFORE DUEL----\n");
        printf("%c - %d\n%c - %d\n", x.cod, x.dmg, y.cod, y.dmg);
        printf("\n\t----LOG----\n");
    }
    while(x.dmg > 0 && y.dmg > 0){
        if(terminal == 1){
            printf("\n\t--ROUND %d--\n", hits+1);
            printf("unit %c hits %c\n", x.cod, y.cod);
        }
        y.dmg = y.dmg - x.dmg;
        if(y.dmg > 0){
            if(terminal == 1){
                printf("survives with %d\n", y.dmg);
                printf("unit %c hits %c\n", y.cod, x.cod);
            }
            x.dmg = x.dmg - y.dmg;
            if(x.dmg > 0 && terminal == 1){
                printf("survives with %d\n", x.dmg);
            }
            else if(terminal == 1){
                printf("unit %c dies\n", x.cod);
            }
        }else if (terminal == 1){
            printf("unit %c dies\n", y.cod);
        }
        if (terminal == 1){
            printf("%c - %d\n%c - %d\n", x.cod, x.dmg, y.cod, y.dmg);
        }
        hits++;
    }
    if (terminal == 1){
        printf("\n\t----RESULT----\n");
    }
    if(x.dmg > 0){
        if (terminal == 1){
            printf("unit %c won\n\n", x.cod);
        }
        return 0;
    }
    else{
        if (terminal == 1){
            printf("unit %c won\n\n", y.cod);
        }
        return 1;
    }
}
