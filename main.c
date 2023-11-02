#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void hostToNetwork (int *ip, int *mask, char ipbin[][9], char maskbin[][9], char ipReseauBin[][9]);
int POW(int x, int y);
void DecimalToBinary(int x, char *bin);
void BinaryToDecimal(int *ipReseau, char ipResBin[][9]);


int main()
{
    int ip[4] = {192,168,1,13};
    char ipbin[4][9];
    int mask[4] = {255,255,255,0};
    char maskbin[4][9];
    char ipReseauBin[4][9];
    int ipReseau[4] = {0,0,0,0};
    int i;

    hostToNetwork(ip,mask, ipbin, maskbin, ipReseauBin);

    printf("IP bin : \n");
    for (i = 0; i < 4 ; i++)
    {
        printf("%s ", ipbin[i]);
    }
    printf("\n\n");
    printf("Mask bin : \n");

    for (i = 0; i < 4 ; i++)
    {
        printf("%s ", maskbin[i]);
    }
    printf("\n\n");

    printf("Ip Réseau bin : \n");
    for (i = 0; i < 4 ; i++)
    {
        printf("%s ", ipReseauBin[i]);
    }
    printf("\n\n");

    BinaryToDecimal(ipReseau, ipReseauBin);

    printf("Ip Réseau : \n");
    for (i = 0; i < 4 ; i++)
    {
        printf("%d ", ipReseau[i]);
    }
    printf("\n\n");

    return 0;
}

void hostToNetwork (int *ip, int *mask, char ipbin[][9], char maskbin[][9], char ipReseauBin[][9])
{
    int  i,j;

    for(i = 0; i < 4; i++)
    {
        DecimalToBinary(ip[i], ipbin[i]);
        DecimalToBinary(mask[i], maskbin[i]);
    }

    for (i = 0; i < 4; i++)
    {
        for(j=0; j < 8; j++)
        {
            if (ipbin[i][j] == '1' && maskbin[i][j] == '1')
            {
                ipReseauBin[i][j] = '1';
            }
            else
            {
                ipReseauBin[i][j] = '0';
            }
        }
        ipReseauBin[i][8] = '\0';
    }
}

void DecimalToBinary(int x, char *bin)     // Fill an array with binary and return the length of the binary number
{
    int i;

    for (i = 7; i >= 0; i--)
    {
        bin[i] = (x % 2) + '0';
        x /= 2;
    }
    bin[8] = '\0';

}

void BinaryToDecimal(int *ipReseau, char ipResBin[][9])
{
    int i,j;

    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 8; j++)
        {
            if (ipResBin[i][j] == '1')
            {
                ipReseau[i] += POW(2, 7-j);
            }
        }
    }
}

int POW(int x, int y)
{
    int i;
    int f = x;         // f est le multiplicateur
    for(i=1;i<y;i++)
    {
        x *= f;
    }

    return x;
}
