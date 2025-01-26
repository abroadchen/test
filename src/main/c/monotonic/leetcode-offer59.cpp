#include <deque>
#include <queue>
using namespace std;

class MaxQueue {
public:
    queue<int> q;
    deque<int> mq;
    MaxQueue() {}

    int max_value() {
        if (q.empty()) return -1;
        return mq.front();
    }

    void push_back(int value) {
        q.push(value);
        while (!mq.empty() && value > mq.back()) mq.pop_back();
        mq.push_back(value);
        return;
    }

    int pop_front() {
        if (q.empty()) return -1;
        int val = q.front();
        q.pop();
        if (mq.front() == val) mq.pop_front();
        return val;
    }
};
