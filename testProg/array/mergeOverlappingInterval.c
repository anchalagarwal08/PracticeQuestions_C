#include <stdio.h>
#include <stdlib.h>
#define STACK_MAX 100

typedef Stack stack;
struct Stack {
    Interval     data[STACK_MAX];
    int     size;
};
typedef Interval Interval;
struct Interval
{
    int start;
    int end;
};
 
/*bool compareInterval(Interval i1, Interval i2)
{  return (i1.start < i2.start)? true: false; }
 */
void Stack_Init(stack *S)
{
    S->size = 0;
}

int Stack_Top(stack *S)
{
    if (S->size == 0) {
        fprintf(stderr, "Error: stack empty\n");
        return -1;
    } 

    return S->data[S->size-1];
}

void Stack_Push(stack *S, Interval d)
{
    if (S->size < STACK_MAX)
        S->data[S->size++] = d;
    else
        printf("Error: stack full\n");
}

void Stack_Pop(stack *S)
{
    if (S->size == 0)
        printf("Error: stack empty\n");
    else
        S->size--;
}

void mergeIntervals(Interval* intervals)
{
//    if (intervals.size() <= 0)
 //       return;
 
    stack s;
 
  //  sort(intervals.begin(), intervals.end(), compareInterval);
 
    s.push(intervals[0]);
 
    for (int i = 1 ; i < intervals.size(); i++)
    {
        Interval top = s.top();
 
        if (top.end < intervals[i].start)
        {
            s.push( intervals[i] );
        }
        else if (top.end < intervals[i].end)
        {
            top.end = intervals[i].end;
            s.pop();
            s.push(top);
        }
    }
 
    // Print contents of stack
    cout << "\n The Merged Intervals are: ";
    while (!s.empty())
    {
        Interval t = s.top();
        cout << "[" << t.start << "," << t.end << "]" << " ";
        s.pop();
    }
 
    return;
}
 
// Functions to run test cases
void TestCase1()
{
    Interval intvls[] = { {6,8}, {1,9}, {2,4}, {4,7} };
 
    mergeIntervals(intvls);
}
void TestCase2()
    Interval intvls[] = { {6,8},{1,3},{2,4},{4,7} };
 
    mergeIntervals(intvls);
}
void TestCase3()
{
    // Create a set of intervals
    Interval intvls[] = { {1,3},{7,9},{4,6},{10,13} };
 
    // Merge overlapping inervals and print result
    mergeIntervals(intvls);
}
 
// Driver program to test above functions
int main()
{
    TestCase1();
    TestCase2();
    TestCase3();
    return 0;
}

