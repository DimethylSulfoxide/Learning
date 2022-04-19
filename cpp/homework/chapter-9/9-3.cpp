#include <iostream>
using namespace std;

struct score{
	int x;
	score *next;
};
score *insertLinklist(score *, score *);
score *removeRepeaded(score *);
void displayLinkList(score *);
int main(void){
	score *head = NULL, *tmp = NULL;
	cout << "请输入链表:";
	do {
		tmp = new score;
		if (!tmp){
			cout << "内存分配失败";
			return -1;
		}
		cin >> tmp->x;
		tmp->next = NULL;
		head = insertLinklist(head, tmp);
	} while (cin.get() != '\n');
	cout << "原链表:";
	displayLinkList(head);
	cout << "去重后:";
	head = removeRepeaded(head);
	displayLinkList(head);
	return 0;
}

score* insertLinklist(score *head, score *newNode){
	if (!head)
		return newNode;
	else {
		score *t = head;
		while (t->next)
			t = t->next;
		t->next = newNode;
		return head;
	}
}

score *removeRepeaded(score *h){
	score *t1 = h, *t2 = h->next;
	while (t2){
		if (t1->x == t2->x){
			t2 = t2->next;
			delete t1->next;
			t1->next = t2;
		}
		else {
			t1 = t1->next;
			t2 = t2->next;
		}
	}
	return h;
}
	
void displayLinkList(score *head){
	cout << head->x;
	head = head->next;
	while (head){
		cout << " -> " << head->x;
		head = head->next;
	}
	cout << '\n';
	return;
}
