#include <stdio.h>
#include <stdlib.h>

char *dosya_oku();
char *icerik_ozeti();

int main()
{
    char *dosya_icerigi = dosya_oku();

    if (dosya_icerigi == NULL)
    {
        printf("Dosyanin Okunmasinda Hata Yasandi.\n");
        return 1;
    }

    char *p = icerik_ozeti(dosya_icerigi);
    printf("1)-> Dosya Icerigi :\n------------------------------------------------\n%s\n", dosya_icerigi);
    printf("------------------------------------------------\n\n");

    if(p == "bos") printf("---> Kodun Icerik Ozeti \t     : BOS \n");

    else {
    printf("---> Kodun Icerik Ozeti \t     : %s \n",p);
        int n = zamanKarmasikligiBul(p);

        if(n == 50)     printf("2)-> Kodun Big O Zaman Karmasikligi  : O(nlogn)\n");

        else if(n == 0) printf("2)-> Kodun Big O Zaman Karmasikligi  : O(1)\n");

        else            printf("2)-> Kodun Big O Zaman Karmasikligi  : O(n^%d)\n", n);
    }
    free(dosya_icerigi);
    free(p);

    return 0;
}

zamanKarmasikligiBul(char dizi[1500])
{
    int f = 0;
    int n = 0;
    int a = 0;
    int k = 0;
    int c = 0;
    int w = 0;
    int temp = 0;
    int m = 0;

    for(int i = 1; dizi[i] != '\0'; i++){

        if(dizi[i] == 'f' && dizi[i+1] == '*') {f++; m++;}
        else if(dizi[i] == 'f') {f++; temp++;}
        else if(dizi[i] == 'w') {w++; temp++;}
        else if(dizi[i] == '+')  a++;
        else if(dizi[i] == '-')  k++;
        if(dizi[i] == '*') c++;
        if(k == a && a !=0 && k !=0) {
            a=0;
            k=0;
            c=0;
            f=0;
            if(temp>=n) {n=temp; temp=0;}
        }
        if(w != 0 && a==k && a !=0 && k !=0) {
            a=0;
            k=0;
            c=0;
            f=0;
            if(temp>=n) {n=temp; temp=0;}
        }

    }

if(m==1 && n==1){
    int m2 = 50;
    return m2;
}
else if(n == 0){
    return n;
}
else{
    return n;
}
}

char *icerik_ozeti(char dizi[1600])
{
    char *p2 = malloc(sizeof(char) * (100+1));
    int j = 0;
    for(int i = 0; dizi[i] != '\0'; i++){
        if(dizi[i] == 'f' && dizi[i+1] == 'o' && dizi[i+2] == 'r'){
            //printf("for\n");
            p2[j] = 'f';
            j++;
        }
        if(dizi[i] == 'w' && dizi[i+1] == 'h' && dizi[i+2] == 'i' && dizi[i+3] == 'l' && dizi[i+4] == 'e'){
            //printf("for\n");
            p2[j] = 'w';
            j++;
        }
        else if(dizi[i] == '*' && dizi[i+1] == '2') {
            //printf("* \n");
            p2[j] = '*';
            j++;
        }
        else if(dizi[i] == '/' && dizi[i+1] == '2') {
            //printf("* \n");
            p2[j] = '/';
            j++;
        }
        else if(dizi[i] == '{') {
            //printf("+ \n");
            p2[j] = '+';
            j++;
        }
        else if(dizi[i] == '}') {
            //printf("- \n");
            p2[j] = '-';
            j++;
        }
    }
    p2[j] = '\0';

if(p2[0] != '+') return "bos";

else             return p2;
}

char *dosya_oku()
{
    FILE *fp;

    fp = fopen("kod.txt", "r");

    if (fp == NULL)
        return NULL;

    fseek(fp, 0, 2);
    int length = ftell(fp);
    fseek(fp, 0, 0);

    char *dizi = malloc(sizeof(char) * (length+1));

    char ch;

    int d = 0;

    while ((ch = fgetc(fp)) != EOF) {
        dizi[d] = ch;
        d++;
    }

    dizi[d] = '\0';

    return dizi;
}
