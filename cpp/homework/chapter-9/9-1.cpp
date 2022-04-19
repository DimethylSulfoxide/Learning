#include <iostream>
using namespace std;

struct stu{
	char name[40];
	char num[20];
	float eGrade;
	float mGrade;
	stu *next;
};

stu* insertLinklist(stu *, stu *);
int displayLinklist(stu *);
stu *getAveGradeMin(stu *);
stu *getAveGradeMax(stu *);

int main(void){
	int n = 0;
	cout << "请输入学生个数:";
	cin >> n;
	stu *tmp = NULL, *head = NULL;
	for (int i = 0; i < n; i ++){
		tmp = new stu;
		if (!tmp){
			cout << "内存分配失败";
			return -1;
		}
		cout << "请输入第" << i + 1 << "个学生的姓名、学号、英语成绩、数学成绩:\n";
		cin >> tmp->name >> tmp->num >> tmp->eGrade >> tmp->mGrade;
		head = insertLinklist(head, tmp);
	}
	// displayLinklist(head);
	stu *max = getAveGradeMax(head), *min = getAveGradeMin(head);
	cout << "平均分最高的学生是" << max->name << "，学号是" << max->num << "，平均分" << 1.0 * (max->mGrade + max->eGrade) / 2 << "。\n";
	cout << "平均分最低的学生是" << min->name << "，学号是" << min->num << "，平均分" << 1.0 * (min->mGrade + min->eGrade) / 2 << "。\n";
	return 0;
}

stu* insertLinklist(stu *head, stu *newNode){
	if (!head)
		return newNode;
	else {
		stu *t = head;
		while (t->next)
			t = t->next;
		t->next = newNode;
		return head;
	}
}

int displayLinklist(stu* tmp){
	int i = 0;
	for (i = 0; tmp; i++){
		cout << "第" << i + 1 << "个学生:\n";
		cout << tmp->name << '\t' << "学号:" << tmp->num << '\n';
		cout << "英语成绩" << tmp->eGrade << '\n';
		cout << "数学成绩" << tmp->mGrade << '\n';
		tmp = tmp->next;
	}
	return i;
}

stu *getAveGradeMin(stu *head){
	stu *min = head;
	while (head){
		if (min->mGrade + min->eGrade > head->eGrade + head->mGrade)
			min = head;
		head = head->next;
	}
	return min;
}

stu *getAveGradeMax(stu *head){
	stu *max = head;
	while (head){
		if (max->mGrade + max->eGrade < head->eGrade + head->mGrade)
			max = head;
		head = head->next;
	}
	return max;
}

