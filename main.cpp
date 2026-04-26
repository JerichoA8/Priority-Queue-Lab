#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>
#include <functional>

using namespace std;

template <typename T>
class PriorityQueue{
private:
    vector<T>data;
    function<double(T)>priority;

public:
    PriorityQueue(function<double(T)> priority_func) {
        priority = priority_func;
    }

    void push(const T& val){
        data.push_back(val);
        sort(data.begin(),data.end(),[this](const T& a, const T& b){
            return priority(a) > priority(b);// sorts by largest to smallest
        });
    }

    T pop(){
        if(is_empty()){
            cout << "Error: Priority Queue is empty!" << endl;
            exit(1);
        }
        T front = data.front();
        data.erase(data.begin());
        return front;
    }

    bool is_empty()const{return data.empty();}
};

int main(){
    PriorityQueue<string> pq([](string s){return (double)s.length();});

    pq.push("hello");
    pq.push("philippines");
    pq.push("ball");
    pq.push("jericho");

    while (!pq.is_empty()) {
        cout << pq.pop() << endl;
    }

    return 0;
}
