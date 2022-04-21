#include <iostream>
using namespace std;

struct score{
	int x;
	score *next;
};

score *insertLinklist(score*, score*);
score *merge(score *,score *);
void displayLinkList(score *);
void deleteLinklist(score *);
int main(void){
	int n1, n2;
	score *tmp = NULL, *head1 = NULL, *head2 = NULL, *head = NULL;
	cout << "链表输入格式：以空格分割，以回车结尾\n";
	cout << "请输入第一个链表:";
	do {
		tmp = new score;
		if (!tmp){
			cout << "内存分配失败";
			return -1;
		}
		cin >> tmp->x;
		tmp->next = NULL;
		head1 = insertLinklist(head1, tmp);
	} while (cin.get() != '\n');
	cout << "请输入第二个链表:";
	do {
		tmp = new score;
		if (!tmp){
			cout << "内存分配失败";
			return -1;
		}
		cin >> tmp->x;
		tmp->next = NULL;
		head2 = insertLinklist(head2, tmp);
	} while (cin.get() != '\n');

	cout << "A: ";
	displayLinkList(head1);
	cout << "B: ";
	displayLinkList(head2);
	head = merge(head1, head2);
	displayLinkList(head);
	deleteLinklist(head);
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
	score *p1 = a, *p2 = b, *h = NULL, *t = NULL;
	bool flag = true;
	if (p1->x < p2->x){
		h = p1;
		p1 = p1->next;
	}
	else {
		h = p2;
		p2 = p2->next;
	}
	t = h;
	while (p1 || p2){
		if (p1 && p2){
			if (p1->x < p2->x){
				t->next = p1;
				p1 = p1->next;
				t = t->next;
			}
			else {
				t->next = p2;
				p2 = p2->next;
				t = t->next;
			}
		}
		else if (p1){
			t->next = p1;
			p1 = p1->next;
			t = t->next;
		}
		else {
			t->next = p2;
			p2 = p2->next;
			t = t->next;
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

void deleteLinklist(score *h){
	score *t = h->next;
	while (t){
		delete h;
		h = t;
		t = t->next;
	}
	delete h;
	return;
}
