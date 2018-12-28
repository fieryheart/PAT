#include <iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
}; 

void printNumber(string s, int x)
{
	cout << s << " : " << x << endl;
}

// 会有超过int最大限制的情况 
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* head;
    ListNode* l3 = new ListNode(0);
    head = l3;
    int carry = 0;
    while(l1 || l2 || carry) {
        int num1 = l1 ? l1->val : 0;
        int num2 = l2 ? l2->val : 0;
        l1 = l1 ? l1->next : l1;
        l2 = l2 ? l2->next : l2;
        ListNode* temp = new ListNode(num1+num2+carry);
        carry = temp->val / 10;
        temp->val = temp->val % 10;
        l3->next = temp;
        l3 = l3->next;
    }
    return head->next;
}

ListNode* createList(ListNode *list, int* arr, int size)
{
	ListNode *head;
	list = new ListNode(0);
	head = list;	
	for(int i = 0; i < size; i++){
		ListNode *temp = new ListNode(arr[i]);
		temp->next = NULL;
		list->next = temp;
		list = list->next;
	}
	return head->next;
}

void printList(ListNode *list)
{
	while(list) {
		cout << list->val << " ";
		list = list->next; 
	}
	cout << endl;
}

int main()
{
	int list1[] = {9};
	int list2[] = {1,9,9,9,9,9,9,9,9,9};
	ListNode *l1, *l2, *l3;
	l1 = createList(l1, list1, sizeof(list1)/sizeof(int));
	printList(l1);
	l2 = createList(l2, list2, sizeof(list2)/sizeof(int));
	printList(l2);
	l3 = addTwoNumbers(l1, l2);
	printList(l3);
	return 0;
}
