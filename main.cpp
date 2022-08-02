#include <iostream>
#include <string.h>
/*Se numește șir vocalic asociat unui șir de caractere format din litere mici ale alfabetului englez
un șir egal cu acesta, dacă el este format numai din vocale, sau un șir obținut din acesta prin
eliminarea tuturor consoanelor sale. Se consideră vocale literele a, e, i, o, u.
Exemplu: șirul ui este șir vocalic asociat unor șiruri ca nuci, frunzis sau ui, iar șirul vid este
șir vocalic asociat unor șiruri ca brr sau mr.
Subprogramul vocalic are doi parametri:
• s, prin care primește un șir de cel mult 100 de caractere, numai litere mici ale alfabetului englez;
• sv, prin care furnizează șirul vocalic asociat șirului primit prin parametrul s.
Scrieți un program Pascal/C/C++ care citește de la tastatură un text format din maximum 100 de
caractere, în care cuvintele sunt formate din litere mici ale alfabetului englez și sunt separate prin
câte un spațiu. Programul afișează pe ecran mesajul DA, dacă există cel puțin o pereche de
cuvinte din text care au asociat același șir vocalic, sau mesajul NU în caz contrar. Programul
cuprinde definiția completă a subprogramului precizat mai sus, precum și apeluri utile ale acestuia.
Exemplu: dacă se citește textul
        in livada de nuci soarele picteaza des stele de aur prin frunzis
se afișează pe ecran mesajul DA*/
using namespace std;

void vocalic(const char s[101], char *sv)
{
    char v[]="aeoiu";
    int l=strlen(s);
    strcpy(sv,s);
    int i=0;
    while(i<strlen(sv))
    {
        if((strchr(v,sv[i])!=0)&&(strchr(" ",sv[i])==0))
            strcpy(sv+i, sv+i+1);
        else
            i++;
    }
}
int idem(char *c)
{
    char *p, cuv[101][35];
    int nrc=0;
    p=strtok(c," ");
    while(p)
    {
        strcpy(cuv[nrc],p);
        p=strtok(NULL, " ");
        nrc++;
    }
    for(int i=0; i<nrc;i++)
        for(int j=i+1; j<=nrc;j++)
            if((i!=j)&&strcmp(cuv[i],cuv[j])==0)
                return 1;
    return 0;
}
int main()
{
    char sir[101], sv[101];
    cin.getline(sir,101);
    vocalic(sir,sv);
    if (idem(sv))
        cout<<"DA";
    else
        cout<<"NU";
    return 0;
}
