#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    priority_queue< int > front_q;
    priority_queue< int, vector<int>, greater<int> > back_q;
    int n;
    cin >> n;

    int input;

    cin >> input;
    cout << input << '\n';
    front_q.push(input);
    if(n == 1) return 0;

    cin >> input;
    if(input >= front_q.top()){
        back_q.push(input);
    }
    else{
        back_q.push(front_q.top());
        front_q.pop();
        front_q.push(input);
    }
    cout << front_q.top() << '\n';

    for(int i = 2; i < n; i++){
        cin >> input;
        if(input < front_q.top()){
            if(front_q.size() == back_q.size() + 1){
                back_q.push(front_q.top());
                front_q.pop();
            }
            front_q.push(input);
        }
        else if(front_q.top() <= input && input <= back_q.top()){
            if(front_q.size() == back_q.size() + 1){
                back_q.push(input);
            }
            else{
                front_q.push(input);
            }
        }
        else{
            if(front_q.size() == back_q.size()){
                front_q.push(back_q.top());
                back_q.pop();
            }
            back_q.push(input);
        }
        cout << front_q.top() << '\n';
    }
}
