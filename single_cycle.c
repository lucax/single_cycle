#include <stdio.h>

int main(int argc, char ** argv)
{
        int n           = 0;
        int m           = 0;
        int a           = 1;
        int b           = 1;
        int index       = 1;
        int loop        = 0;
        int i           = 1;
        int j           = 0;
        char number[16] = "\0";

        printf("\nCopyright (C) PAN Qian-Hua\n\n");

        printf("Enter the number of teams or players:");
        gets(number);

        for(i = 0; i < 16; i++) {
                if(number[i] == '\0') {
                        break;
                }
                if(number[i] < '0' || number[i] > '9') {
                        printf("%d", i);
                        printf("\nERROR: there is non-digit character.\n");
                        return 1;
                }
                j++;
        }
        
        for(i = 0; i < j; i++) {
                n = 10 * n + (number[i] - 0x30);
        }
        
        if(n % 2 == 0) {
                m = n;
        } else {
                m = n + 1;
        }
        
        for(i = 1; i <= (m - 1) * (m / 2); i++) {
                if(a >= m) {
                        a = 1;
                }
                if(index > m / 2) {
                        index = 1;
                }
                if(index == 1){
                        loop++;
                        if(i == 1) {
                                b=m;
                        } else {
                                b=a;
                        }
                        printf("\nRound");
                        printf("%d", loop);
                        printf(":\n");
                        
                        if(((i - 1) / (m / 2)) % 2 == 0) {
                                printf("%d", a);
                                printf("<>");
                                printf("%d\n", m);
                        } else {
                                printf("%d", m);
                                printf("<>");
                                printf("%d\n", a);
                        }
                } else if(index > 1 && index <= m / 2) {
                        if(b > 1) {
                                b--;
                        } else {
                                b = m - 1;
                        }
                        printf("%d", a);
                        printf("<>");
                        printf("%d\n", b);
                }
                index++;
                a++;
        }

        printf("\nPress ENTER to exit.");
        gets(number);
        printf(":-)\n");
        return 0;
}
