/* To clear nth bit of a number
input : 13
bit position to clear : 0
Output : 12*/


#include <stdio.h>

int main()
{
    int num, n, bitStatus;
    printf("Enter any number: ");
    scanf("%d", &num);

    /* Input bit position you want to clear */
    printf("Enter nth bit to clear (0-31): ");
    scanf("%d", &n);

    bitStatus = num & (~(1<<n));

    printf("bit is %d", bitStatus);

    return 0;
}