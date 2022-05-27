#include <iostream>
#include <stack>
#include <ctime>
#include <cstdlib>
#include <algorithm>
#include <stdlib.h>

using namespace std;

void generare(stack <int> &mystack, int limita)
{
    for(int i = 0 ; i < limita; i++)
    {
        int a = 1 + (rand() % 14);
        mystack.push(a);
    }
}

void afisare(stack <int> mystack)
{
    if(mystack.empty())
    {
        cout << endl << "------- You have no more books -------" << endl;
        return ;
    }
    else if(mystack.size() > 1)
        cout << endl << "The books you have are: " << endl;
    else if(mystack.size() == 1)
        cout << endl << "The book you have is: "<< endl;

    while(!mystack.empty())
    {
        cout << mystack.top() << " ";
        mystack.pop();
    }
    cout << endl;
}

void inserarea_la_baza(stack <int> &st, int x)
{
    if(st.empty())
        st.push(x);
    else
    {
        int a = st.top();
        st.pop();
        inserarea_la_baza(st, x);
        st.push(a);
    }
}

void razboi(stack <int> &mystack, stack <int> &mystack1, int a, int b)
{
    mystack.push(a); 
    mystack1.push(b);
    int nr = mystack.top(); 
    if((nr + 1 > mystack.size()) || (nr + 1 > mystack1.size())) 
    {
        nr = min(mystack.size(), mystack1.size()) - 1;
    }
    int i = 0 ,j = 0, k = 0;
    stack <int> aux1; 
    stack <int> aux2;
    while(i <= nr)
    {
        int a = mystack.top(); 
        mystack.pop();
        aux1.push(a);

        int b = mystack1.top();
        mystack1.pop();
        aux2.push(b);
        i++; 
    }
    
    int c = aux1.top(); 
    int d = aux2.top(); 
    
    if(c > d)
    {
        while(k <= nr) 
        {
            int f = aux2.top();
            aux2.pop();
            inserarea_la_baza(mystack, f);
            k++;
        }
        while(j <= nr) 
        {
            int e = aux1.top();
            aux1.pop();
            inserarea_la_baza(mystack, e);
            j++;
        }
    }
    else
    {
        while(j <= nr) 
        {
            int e = aux1.top();
            aux1.pop();
            inserarea_la_baza(mystack1, e);
            j++;
        }
        while(k <= nr) 
        {
            int f = aux2.top();
            aux2.pop();
            inserarea_la_baza(mystack1, f);
            k++;
        }

    }

}

int comparatie(stack <int> &mystack, stack <int> &mystack1)
{
    int a, b, comp;
    a = mystack.top(); 
    mystack.pop();
    b = mystack1.top(); 
    mystack1.pop();
    
    if(a > b)
    {
        
        inserarea_la_baza(mystack, b);
        inserarea_la_baza(mystack, a);
    }
    else if(a < b)
    {
        
        inserarea_la_baza(mystack1, a);
        inserarea_la_baza(mystack1, b);
    }
    else if(a == b)
    {
        
        razboi(mystack, mystack1, a , b);
    }
}


int main()
{
    system("Color 0A");
    int i = 1;
    stack <int> Jucator1;
    stack <int> Jucator2;
    srand((unsigned) time(0));
    generare(Jucator1, 26);
    generare(Jucator2, 26);
    cout << "Round " << i << ": " << endl;
    i++;
    afisare(Jucator1);
    cout << endl;
    while(!Jucator1.empty() || !Jucator2.empty())
    {
        cout << "Round " << i << ": ";
        comparatie(Jucator1, Jucator2);
        cout << endl;
        afisare(Jucator1);
        i++;
        cout << endl;
        if(Jucator1.empty())
        {
            cout << "-----------------------------------" << endl;
            cout << "Unfortunately, you lost." << endl;
            break;
        }
        if(Jucator2.empty())
        {
            cout << "-----------------------------------" << endl;
            cout << "Congratulations, you won." << endl;
            break;
        }
    }
    return 0;
}
