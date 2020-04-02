// Definition for singly-linked list.
#include <iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 };
    void insertNodeS(ListNode* &number, int data)
    {
        ListNode *temp;
        if(number == nullptr)
        {
            number = new ListNode(data);
            return;
        }
        temp = new ListNode(data);
        temp->next = number;
        number = temp;
        return;
    }  

    void insertNode(ListNode* &number, int data)
    {
        ListNode *temp;
        if (number == nullptr)
        {
            number = new ListNode(data);
            return;
        }
        temp = number;
        while(temp->next != nullptr)
        {
            temp = temp->next;
        }
        temp->next = new ListNode(data);

    } 
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *result = nullptr;
        int sum = 0;
        int carry = 0;
        
        while (l1 && l2)
        {
            sum = l1->val + l2->val + carry;
            if(sum > 9)
            {
                carry = sum / 10;
                sum = sum % 10;
            }
            l1 = l1->next;
            l2 = l2->next;
            insertNode(result, sum);
        }
        return result;
    }
    
    void print(ListNode *lst)
    {
        while(lst != nullptr)
        {
            cout << lst->val << " ";
            lst = lst->next;
        }
        cout << endl;
    }

    int main()
    {
        ListNode *l1 = nullptr;
        ListNode *l2 = nullptr;
        insertNode(l1, 3);
        insertNode(l1, 4);
        insertNode(l1, 2);
        
        insertNode(l2, 4);
        insertNode(l2, 6);
        insertNode(l2, 5);

        cout << "print l1" << endl;
        print(l1);
        cout << "print l2" << endl;
        print(l2);

    }
/**
void trimLeftTrailingSpaces(string &input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
        return !isspace(ch);
    }));
}

void trimRightTrailingSpaces(string &input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
        return !isspace(ch);
    }).base(), input.end());
}

vector<int> stringToIntegerVector(string input) {
    vector<int> output;
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    stringstream ss;
    ss.str(input);
    string item;
    char delim = ',';
    while (getline(ss, item, delim)) {
        output.push_back(stoi(item));
    }
    return output;
}

ListNode* stringToListNode(string input) {
    // Generate list from the input
    vector<int> list = stringToIntegerVector(input);

    // Now convert that list into linked list
    ListNode* dummyRoot = new ListNode(0);
    ListNode* ptr = dummyRoot;
    for(int item : list) {
        ptr->next = new ListNode(item);
        ptr = ptr->next;
    }
    ptr = dummyRoot->next;
    delete dummyRoot;
    return ptr;
}

string listNodeToString(ListNode* node) {
    if (node == nullptr) {
        return "[]";
    }

    string result;
    while (node) {
        result += to_string(node->val) + ", ";
        node = node->next;
    }
    return "[" + result.substr(0, result.length() - 2) + "]";
}

int main() {
    string line;
    while (getline(cin, line)) {
        ListNode* l1 = stringToListNode(line);
        getline(cin, line);
        ListNode* l2 = stringToListNode(line);
        
        ListNode* ret = Solution().addTwoNumbers(l1, l2);

        string out = listNodeToString(ret);
        cout << out << endl;
    }
    return 0;
}**/