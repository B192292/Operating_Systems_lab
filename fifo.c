#include<stdio.h>
int pagefault(int a[], int frame[], int n, int no) 
{
    int i, j, avail, count = 0, k;
    for (i = 0; i < no; i++)
     {
        frame[i] = -1;
     }
    j = 0;
    for (i = 0; i < n; i++) 
    {
        avail = 0;
        for (k = 0; k < no; k++)  
        if (frame[k] == a[i]) 
                avail = 1;  
        if (avail == 0) 
        {
            frame[j] = a[i];
            j = (j + 1) % no;
            count++;  
        }
    }
    return count;
}
int  main() 
{
    int n, i,  no, fault;
    printf("\nENTER THE NUMBER OF PAGES:\n");
    scanf("%d", & n);
    int a[n];
    printf("ENTER THE PAGE NUMBER :\n");
    for (i = 0; i < n; i++)
        scanf("%d", & a[i]);

    printf("ENTER THE NUMBER OF FRAMES :");
    scanf("%d", & no);
    int frame[no];
    fault = pagefault(a, frame, n, no);
    printf("Page Fault Is %d", fault);
}
   
