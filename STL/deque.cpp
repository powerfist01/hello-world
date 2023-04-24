#include <iostream>
#include <deque>

using namespace std;

int main(){
    deque<int> dq;
    // inserting elements in back of the deque
    dq.push_back(1);
    dq.push_back(2);
    dq.push_back(3);

    //inserting elements in front of the deque
    dq.push_front(9);
    dq.push_front(8);
    dq.push_front(7);

    //iterate over deque;
    cout << endl << "The deque is : ";
    for(auto it: dq){
        cout << it << " ";
    }

    // to remove element from front of the deque
    dq.pop_front();

    // to remove element from last 
    dq.pop_back();

    // size of the deque
    cout << endl << dq.size() << endl;

    for(auto it=dq.begin(); it != dq.end(); it++) {
        cout << *it << " ";
    }
    return 0;
}