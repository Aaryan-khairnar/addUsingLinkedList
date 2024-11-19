#include <iostream>
#include <vector>
using namespace std;


// Input: l1 = [1,2,4], l2 = [1,3,4]
// Output: [2,5,8]

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class Solution {
public:

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        ListNode* head=nullptr;
        ListNode* tail=nullptr;
        int carry = 0;

        while(carry != 0 || l1 != nullptr || l2 != nullptr){
            
            int digit1=0;
            int digit2 =0;

            if(l1 != nullptr){
                digit1 = l1->val;
                l1 = l1->next;
            }

            if(l2 != nullptr){
                digit2 = l2->val;
                l2= l2->next;
            }

            int total = digit1+digit2+carry;
            carry = total/10;
            int sum = total%10;

            ListNode* newNode = new ListNode(sum); //initialise a new node

            if(head == nullptr){
                head = newNode;
            }
            else{
                tail->next=newNode;
            }
            tail=newNode;
        }
    
        return head;
    }

};

void printList(ListNode* head) {
    ListNode* temp = head;
    while (temp != nullptr) {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
}

ListNode* createList(const vector<int>& values) {
    ListNode* head = nullptr;
    ListNode* tail = nullptr;
    for (int value : values) {
        ListNode* newNode = new ListNode(value);
        if (head == nullptr) {
            head = newNode;
        } else {
            tail->next = newNode;
        }
        tail = newNode;
    }
    return head;
}

int main(){
    Solution solution;

    // Test Case 1: l1 = [1,2,4], l2 = [1,3,4]
    vector<int> values1 = {1, 2, 4};
    vector<int> values2 = {1, 3, 4};
    ListNode* l1 = createList(values1);
    ListNode* l2 = createList(values2);
    ListNode* result = solution.addTwoNumbers(l1, l2);
    cout << "Test Case 1 Result: ";
    printList(result);

    // Test Case 2: l1 = [0,4], l2 = [0]
    vector<int> values3 = {0,4};
    vector<int> values4 = {0};
    l1 = createList(values3);
    l2 = createList(values4);
    result = solution.addTwoNumbers(l1, l2);
    cout << "Test Case 2 Result: ";
    printList(result);

    // Test Case 3: l1 = [9,9,9], l2 = [1]
    vector<int> values5 = {9, 9, 9};
    vector<int> values6 = {1};
    l1 = createList(values5);
    l2 = createList(values6);
    result = solution.addTwoNumbers(l1, l2);
    cout << "Test Case 3 Result: ";
    printList(result);

    // Test Case 4: l1 = [1,2], l2 = [1,2]
    vector<int> values7 = {1, 2};
    vector<int> values8 = {1, 2};
    l1 = createList(values7);
    l2 = createList(values8);
    result = solution.addTwoNumbers(l1, l2);
    cout << "Test Case 4 Result: ";
    printList(result);

    // Test Case 5: l1 = [5, 6, 7], l2 = [1, 9]
    vector<int> values9 = {5, 6, 7};
    vector<int> values10 = {1, 9};
    l1 = createList(values9);
    l2 = createList(values10);
    result = solution.addTwoNumbers(l1, l2);
    cout << "Test Case 5 Result: ";
    printList(result);

    return 0;
}


