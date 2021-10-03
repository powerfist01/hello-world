#include <iostream>
#include <stack>

using namespace std;
int main( )
{
    stack <int> s;  // declaration of stack

    //inserting 5 elements in stack from 0 to 4.
    for(int i = 0;i < 5; i++)
    {
        s.push( i ) ;
    }

    //Now the stack is {0, 1, 2, 3, 4}

    //size of stack s
    cout<<”Size of stack is: ” <<s.size( )<<endl;

    //accessing top element from stack, it will be the last inserted element.
    cout<<”Top element of stack is: ” <<s.top( ) <<endl ;

    //Now deleting all elements from stack 
    for(int i = 0;i < 5;i++)
    {
        s.pop( );
    }

    //Now stack is empty,so empty( ) function will return true.

    if(s.empty())
    {
        cout <<”Stack is empty.”<<endl;
    }
    else
    {
        cout <<”Stack is Not empty.”<<endl;
    }

    return 0;

}
