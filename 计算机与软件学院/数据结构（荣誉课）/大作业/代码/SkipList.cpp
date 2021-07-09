#include "SkipList.h"

//�������level�㷨
int randomLevel() {
	int k = 1;

	while (rand() % 2) {
		k++;
	}
	k = (k < MAXLEVEL) ? k : MAXLEVEL;
	return k;
}

skiplist::skiplist()
{
	//head = NULL;
	max_length = 0;
	//��ʼ��headΪһ��5���val(0)��node
	node* p = new node(0, 5);
	head = p;
}

void skiplist::insert(int val)
{
	int level = randomLevel();
	max_length++;
	//���Ŀǰ��û�нڵ�
	if (head == NULL) {
		//��һ���ڵ�ĸ߶�Ϊmax
		node* p = new node(val, MAXLEVEL);
		head = p;
		max_length++;
	}
	else {
		//ָ���һ���ڵ�
		node* cur = head;
		//p���¼���Ľڵ�
		node* p = new node(val, level);

		//����ÿһ���������ǰ��ڵ�
		//node** last=(node**)malloc(MAXLEVEL*sizeof(node*));
		node* last[MAXLEVEL];
		for (int i = MAXLEVEL - 1; i >= 0; i--) {
			//�ڵ�i���ҵ����һ����valС�Ľڵ�
			while (cur->forword[i] != NULL && cur->forword[i]->val < val) {
				cur = cur->forword[i];

			}
			last[i] = cur;
		}
		//�ҵ���
		if (cur->forword[0] == NULL) {
			//���뵽���
			for (int i = p->level - 1; i >= 0; i--) {
				last[i]->forword[i] = p;
			}
		}
		else if (cur->forword[0]->val > val) {
			//����
			for (int i = p->level - 1; i >= 0; i--) {
				//p�ĺ���ָ��=pǰ���ָ��ĺ���ָ��
				p->forword[i] = last[i]->forword[i];
				//�ı�pǰ���ָ��ĺ���ָ��
				last[i]->forword[i] = p;
			}

		}

	}
}

bool skiplist::search(int val)
{
	node* cur = head;
	for (int i = MAXLEVEL - 1; i >= 0; i--) {
		while (cur->forword[i] != NULL && cur->forword[i]->val < val) {
			cur = cur->forword[i];

		}

		if (cur->forword[i] != NULL && cur->forword[i]->val == val) {

			return true;
		}
		//else cout << "not find" << endl;

	}
	return false;
}

void skiplist::delete_val(int val)
{
	if (!search(val)) {
		return;
	}
	node* cur = head;
	node* ask = NULL;//Ҫ�ҵ��Ľڵ�
	node* last[MAXLEVEL];
	for (int i = MAXLEVEL - 1; i >= 0; i--) {
		while (cur->forword[i] != NULL && cur->forword[i]->val < val) {
			cur = cur->forword[i];
		}
		//����ÿ��level��ǰ���ָ��
		last[i] = cur;

		if (cur->forword[i] != NULL && cur->forword[i]->val == val) {
			//�ҵ��˵��ǵñ���ǰ���ָ�����Լ�������ɨ��
			//�����ҵ��Ľڵ�
			ask = cur->forword[i];
		}
		//else cout << "not find" << endl;

	}
	for (int i = ask->level - 1; i >= 0; i--) {
		//ɾ���Ľڵ�ǰ���ָ���滻��ɾ���Ľڵ���ָ
		last[i]->forword[i] = ask->forword[i];

	}
}

void skiplist::print()
{
	for (int i = MAXLEVEL - 1; i >= 0; i--) {
		node* cur = head;
		/*cout << cur->val;*/
		if (cur->forword[i] == NULL)
			continue;
		while (cur->forword[i]) {

			cur = cur->forword[i];
			cout << cur->val << ' ';
		}
		cout << endl;
	}
	//cout << head->get_val() << endl;
	//cout << max_length;
}

int skiplist::get_max_length()
{
	return max_length;
}
