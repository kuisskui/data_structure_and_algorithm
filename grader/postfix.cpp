#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

typedef double ValueType;

struct ListNode
{
    ValueType val;
    ListNode *next;

    ListNode(ValueType val, ListNode *next = nullptr)
        : val(val), next(next) {}
};

ValueType pop(ListNode *&head)
{
    ListNode *next = head->next;
    ValueType x = head->val;
    delete head;
    head = next;

    return x;
}

void push(ListNode *&head, ValueType x)
{
    ListNode *new_node = new ListNode(x, head);
    head = new_node;
}

int main()
{
    string buffer;

    ListNode *head = nullptr;

    do
    {
        cin >> buffer;
        if (buffer.at(0) == '=')
        {
            break;
        }
        else if ((buffer.at(0) >= '0') && (buffer.at(0) <= '9'))
        {
            double val = stod(buffer);
            // *****************************
            // insert val into the top of the stack
            push(head, val);
        }
        else
        {
            // *****************************
            // buffer is an operator.
            // your code here
            double int2 = pop(head);
            double int1 = pop(head);

            if (buffer.at(0) == '+')
            {
                int1 += int2;
            }
            else if (buffer.at(0) == '-')
            {
                int1 -= int2;
            }
            else if (buffer.at(0) == '*')
            {
                int1 *= int2;
            }
            else if (buffer.at(0) == '/')
            {
                int1 /= int2;
            }
            push(head, int1);
        }
    } while (true);
    cout << fixed << setprecision(4) << head->val << endl;
}