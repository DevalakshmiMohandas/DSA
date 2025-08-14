#include<stdio.h>
struct poly
{
    int coeff;
    int exp;
}poly[10],poly2[10],poly3[10];

int main()
{
    int n,m,i=1,j=1,k=1;
    printf("Enter the number of terms of first polynomial");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("Enter Co-efficient");
        scanf("%d",&poly[i].coeff);
        printf("Enter Exponent");
        scanf("%d",&poly[i].exp);

    }
     printf("Enter the number of terms of second polynomial: ");
    scanf("%d", &m);
    for (j = 0; j < m; j++) {
        printf("Enter coefficient %d: ", j + 1);
        scanf("%d", &poly2[j].coeff);
        printf("Enter exponent %d: ", j + 1);
        scanf("%d", &poly2[j].exp);
    }
     i = 0; j = 0; k = 0;

    while (i < n && j < m) {
        if (poly[i].exp == poly2[j].exp) {
            poly3[k].coeff = poly[i].coeff + poly2[j].coeff;
            poly3[k].exp = poly[i].exp;
            i++; j++; k++;
        } else if (poly[i].exp > poly2[j].exp) {
            poly3[k].coeff = poly[i].coeff;
            poly3[k].exp = poly[i].exp;
            i++; k++;
        } else{
            poly3[k].coeff = poly2[j].coeff;
            poly3[k].exp = poly2[j].exp;
            j++; k++;
        }
    }
    
    while(i<=n)
    {
        poly3[k].coeff=poly[i].coeff;
        poly3[k].exp=poly[i].exp;
        i++,k++;
    }
    while(j<=m)
    {
        poly3[k].coeff=poly2[j].coeff;
        poly3[k].exp=poly2[j].exp;
        j++,k++;
    }
     for(i=0;i<k;i++)
    {
        if (i < k - 1)
            printf("%d x^%d + ", poly3[i].coeff, poly3[i].exp);
        else
            printf("%d x^%d", poly3[i].coeff, poly3[i].exp);
    }
    printf("\n");

    return 0;
}

