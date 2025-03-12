#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <string.h>
char GetLetter(int num){
    switch(num){
        case 1:
            return 'A';
            break;
        case 2:
            return 'B';
            break;
        case 3:
            return 'C';
            break;
        case 4:
            return 'D';
            break;
        case 5:
            return 'E';
            break;
        case 6:
            return 'F';
            break;
        case 7:
            return 'G';
            break;
        case 8:
            return 'H';
            break;
        case 9:
            return 'I';
            break;
        case 10:
            return 'J';
            break;
        case 11:
            return 'K';
            break;
        case 12:
            return 'L';
            break;
        case 13:
            return 'M';
            break;
        case 14:
            return 'N';
            break;
        case 15:
            return 'O';
            break;
        case 16:
            return 'P';
            break;
        case 17:
            return 'Q';
            break;
        case 18:
            return 'R';
            break;
        case 19:
            return 'S';
            break;
        case 20:
            return 'T';
            break;
        case 21:
            return 'U';
            break;
        case 22:
            return 'V';
            break;
        case 23:
            return 'W';
            break;
        case 24:
            return 'X';
            break;
        case 25:
            return 'Y';
            break;
        case 26:
            return 'Z';
            break;
        
    }
    return '0';
}

void GeneraColori(char *ColoridaIndovinare,int PaletteColori, int numColori){
    srand(time(NULL));
    int generatore;
    for(int i=0;i<numColori;i++){
        generatore=rand() % PaletteColori;
        generatore++;
        //printf("%d\n",generatore);
        *(ColoridaIndovinare+i)= GetLetter(generatore);
    }
};
void test(int NumColori,char *Colori){
    for(int i=0;i<NumColori;i++){
        printf("%c",Colori[i]);
    }
}
int Checkvittoria(char *Tentativo, char *ColoridaIndovinare, int NumColori){
    for(int i=0;i<NumColori;i++){
        if(Tentativo[i]!=ColoridaIndovinare[i])
            return 0;
    }
    return 1;
};
void PrintTabellone(char *Tabellone, int NumColori, char NumTentativi, char *ColoridaIndovinare,int v, int *ColGiustoPostoGiusto, int *ColGiustoPostoSbagliato){
    printf("\n\n\n\n");
    for(int i=0;i<NumColori+2;i++){
        printf("-:-:-");
    }
    printf("\n GPS ");
    if(v==0){
        for(int i=0;i<NumColori;i++){
            printf("| X |");
    }}
    if(v==1){
        for(int i=0;i<NumColori;i++){
            printf("| %c |",*(ColoridaIndovinare+i));
        }
    }
    printf(" GPG \n");
    for(int i=0;i<NumColori+2;i++){
        printf("-----");
    }
    printf("\n");
    for(int i=0;i<NumTentativi;i++){
        printf("[ %d ]",*(ColGiustoPostoSbagliato + i));
        for(int j=0;j<NumColori;j++){
            printf("| %c |",*(Tabellone + i * NumColori + j));
        }
        printf("[ %d ]",*(ColGiustoPostoGiusto + i));
        printf("\n");
    }

}

int GetColGiustoPostoGiusto(char *ColoridaIndovinare, char *Tentativo, int NumColori){
    int sum=0;
    for(int i=0;i<NumColori;i++){
        if(*(ColoridaIndovinare+i)== *(Tentativo+i))
            sum++;
    }
    return sum;
}
int GetColGiustoPostoSbagliato(char *ColoridaIndovinare, char *Tentativo, int NumColori){
    int sum=0;
    char CopiaTentativo[NumColori];
    char CopiaColori[NumColori];
    for(int i=0;i<NumColori;i++){
        CopiaTentativo[i]=*(ColoridaIndovinare+i);
        CopiaColori[i]=*(Tentativo+i);
        }

    for(int i=0;i<NumColori;i++){
        if(*(Tentativo+i)==*(ColoridaIndovinare+i)){
            CopiaTentativo[i]=' ';
            CopiaColori[i]=' ';
        }
    }
    for(int i=0;i<NumColori;i++){
        for(int j=0;j<NumColori;j++){
            if(CopiaTentativo[i]==CopiaColori[j] && CopiaTentativo[i]!=' ' && CopiaColori[j]!=' '){
                CopiaTentativo[i]=' ';
                CopiaColori[j]=' ';
                sum++;
            }
    }
    }
return sum;}

int main(void) {
    int PaletteColori=0; //Colori disponibili da usare
    int NumColori=0; //numero di colori da indovinare
    int NumTentativi=0;
    while(PaletteColori<1 || PaletteColori>26){
        printf("Quanti colori possibili da usare (max 26)?\n");
        scanf("%d",&PaletteColori);}
    
    printf("Quanti Colori da indovinare?\n");
    scanf("%d",&NumColori);
    printf("Quanti Tentativi?\n");
    scanf("%d",&NumTentativi);

    char ColoridaIndovinare[NumColori]; //colori efferrivamente da indovinare
    GeneraColori(ColoridaIndovinare,PaletteColori,NumColori);
    //test(NumColori, ColoridaIndovinare);

    char Tabellone[NumTentativi][NumColori];
    int ColGiustoPostoGiusto[NumTentativi];
    int ColGiustoPostoSbagliato[NumTentativi];

    for(int i=0;i<NumTentativi;i++){
        ColGiustoPostoGiusto[i]=0;
        ColGiustoPostoSbagliato[i]=0;
        for(int j=0;j<NumColori;j++){
            Tabellone[i][j]='*';
        }
    }
    
    char input;
    char *PtrTabellone = &Tabellone[0][0];
    PrintTabellone(PtrTabellone,NumColori,NumTentativi,ColoridaIndovinare,0,ColGiustoPostoGiusto,ColGiustoPostoSbagliato);
    int NumTentativo=0;
    char Tentativo[NumColori];
    while(NumTentativo<=NumTentativi){
        printf("Inserire la Combinazione %d\n",NumColori);
        for(int i=0;i<NumColori;i++){
            printf("%d :",i);
            scanf(" %c",&input);
            Tentativo[i]=toupper(input);
        }
        printf("numtentativo: %d\n",NumTentativo);
        for(int j=0;j<NumColori;j++){
                Tabellone[NumTentativi-NumTentativo-1][j]=Tentativo[j];
            }

        ColGiustoPostoGiusto[NumTentativi-NumTentativo-1]=GetColGiustoPostoGiusto(ColoridaIndovinare,Tentativo,NumColori);
        ColGiustoPostoSbagliato[NumTentativi-NumTentativo-1]=GetColGiustoPostoSbagliato(ColoridaIndovinare,Tentativo,NumColori);
        PrintTabellone(PtrTabellone,NumColori,NumTentativi,ColoridaIndovinare,0,ColGiustoPostoGiusto,ColGiustoPostoSbagliato);
        if(Checkvittoria(Tentativo, ColoridaIndovinare, NumColori)==1){
            PrintTabellone(PtrTabellone,NumColori,NumTentativi,ColoridaIndovinare,1,ColGiustoPostoGiusto,ColGiustoPostoSbagliato);
            printf("Hai vinto");
            return 0;
        }

        NumTentativo++;
    }
    test(NumColori, ColoridaIndovinare);
    printf("Hai perso!");
    
    

}