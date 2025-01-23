#include <set>
#include <utility>
#include <vector>
using namespace std;

class Solution {
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        typedef pair<int, int> PII;
        int n = lists.size();
        set<PII> s;
        for (int i = 0; i < n; i++) {
            if (lists[i] == nullptr) continue;
            s.insert(PII(lists[i]->val, i));
        }
        ListNode new_head, *p = &new_head, *q;
        new_head.next = nullptr;
        while (s.size()) {
            PII a = *s.begin();
            s.erase(s.begin());
            q = lists[a.second];
            lists[a.second] = lists[a.second]->next;
            p->next = q;
            q->next = nullptr;
            p = q;
            if (lists[a.second]) {
                s.insert(PII(lists[a.second]->val, a.second));
            }
        }
        return new_head.next;
    }
};
