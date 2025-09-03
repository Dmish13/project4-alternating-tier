// Daniel Misherky
// U93099650
// This program categorizes students bades on scores into three tiers
// if the score is closest to 30 they are tier 1, if the score is closest to 75 they are tier 2, if the score is closest to 120 they are tier 3
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

void assign_tier(int *points, int *tier, int n); // initializes function to caterogrize students into tiers

int main()
{
    int n, *p; // n is number of students, p is pointer to access array of points
    printf("Enter number of students: ");
    scanf("%d", &n); // user input for number of students
    int *points = malloc(n*sizeof(int)); // array of student points
    printf("Enter points for each student: ");
    for(p=&points[0]; p<&points[n]; p++)
    {
        scanf("%d", p); // user inputs the points for the students
    }
    int *tier = malloc(n*sizeof(int)); // initialize array for tier
    assign_tier(points, tier, n); // calls function to assign tiers
    printf("Tier 1: student "); // prints out the students in each tier
    for(int i = 0; i <n; i++)
    {
        if(tier[i] == 1)
        {
            printf("%d ", i+1); // i+1 used since student number is 1 more than index position
        }
    }
    printf("\nTier 2: student ");
    for(int i = 0; i <n; i++)
    {
        if(tier[i] == 2)
        {
            printf("%d ", i+1);
        }
    }
    printf("\nTier 3: student ");
    for(int i = 0; i <n; i++)
    {
        if(tier[i] == 3)
        {
            printf("%d ", i+1);
        }
    }
    return 0;
}

void assign_tier(int *points, int *tier, int n)
{
    int *p, *i; // p is pointer to access array of points, i is pointer to access array of tier
    i = tier;
    for(p=points; p<points+n; p++) // for loop goes through array of points using pointers
    {
        if(abs((*p)- 30)< abs((*p)-75) && abs((*p)-30)<abs((*p)-120)) // if points is closest to 30, student is in tier 1
        {
            *i = 1;
        }
        else if(abs((*p)-75)< abs((*p)- 30) && abs((*p)-75)<abs((*p)-120)) // if points is closses to 75, student is in tier 2
        {
            *i = 2;
        }
        else // if points is closest to 120, student is in tier 3
        {
            *i = 3;
        }
        i++; // updates pointer to next position in array of tiers
    }

}