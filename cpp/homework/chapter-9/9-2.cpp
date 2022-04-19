#include <cstddef>
#include <iostream>
using namespace std;

struct score{
	int x;
	score *next;
};

score *insertLinklist(score*, score*);
score *merge(score *,score *);
void displayLinkList(score *);
int main(void){
	int n1, n2;
	score *tmp = NULL, *head1 = NULL, *head2 = NULL;
	cout << "请输入第一个链表的元素个数:";
	cin >> n1;
	for (int i = 0; i < n1; i ++){
		tmp = new score;
		if (!tmp){
			cout << "内存分配失败";
			return -1;
		}
		cout << "请输入第" << i + 1 << "个元素的值:\n";
		cin >> tmp->x;
		tmp->next = NULL;
		head1 = insertLinklist(head1, tmp);
	}
	cout << "请输入第二个链表的元素个数:";
	cin >> n1;
	for (int i = 0; i < n1; i ++){
		tmp = new score;
		if (!tmp){
			cout << "内存分配失败";
			return -1;
		}
		cout << "请输入第" << i + 1 << "个元素的值:\n";
		cin >> tmp->x;
		tmp->next = NULL;
		head2 = insertLinklist(head2, tmp);
	}
	cout << "A: ";
	displayLinkList(head1);
	cout << "B: ";
	displayLinkList(head2);
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

score *merge(score *a, score *b){
	score *p1 = a, *p2 = b, *h = NULL;
	return NULL;
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
