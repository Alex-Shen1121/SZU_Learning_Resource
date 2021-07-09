#include "SkipList.h"

//随机生成level算法
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
	//初始化head为一个5层的val(0)的node
	node* p = new node(0, 5);
	head = p;
}

void skiplist::insert(int val)
{
	int level = randomLevel();
	max_length++;
	//如果目前还没有节点
	if (head == NULL) {
		//第一个节点的高度为max
		node* p = new node(val, MAXLEVEL);
		head = p;
		max_length++;
	}
	else {
		//指向第一个节点
		node* cur = head;
		//p是新加入的节点
		node* p = new node(val, level);

		//保存每一层插入的最近前面节点
		//node** last=(node**)malloc(MAXLEVEL*sizeof(node*));
		node* last[MAXLEVEL];
		for (int i = MAXLEVEL - 1; i >= 0; i--) {
			//在第i层找到最后一个比val小的节点
			while (cur->forword[i] != NULL && cur->forword[i]->val < val) {
				cur = cur->forword[i];

			}
			last[i] = cur;
		}
		//找到了
		if (cur->forword[0] == NULL) {
			//插入到最后
			for (int i = p->level - 1; i >= 0; i--) {
				last[i]->forword[i] = p;
			}
		}
		else if (cur->forword[0]->val > val) {
			//插入
			for (int i = p->level - 1; i >= 0; i--) {
				//p的后面指针=p前面的指针的后续指针
				p->forword[i] = last[i]->forword[i];
				//改变p前面的指针的后续指针
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
	node* ask = NULL;//要找到的节点
	node* last[MAXLEVEL];
	for (int i = MAXLEVEL - 1; i >= 0; i--) {
		while (cur->forword[i] != NULL && cur->forword[i]->val < val) {
			cur = cur->forword[i];
		}
		//保留每个level的前面的指针
		last[i] = cur;

		if (cur->forword[i] != NULL && cur->forword[i]->val == val) {
			//找到了但是得保存前面的指针所以继续往下扫描
			//保存找到的节点
			ask = cur->forword[i];
		}
		//else cout << "not find" << endl;

	}
	for (int i = ask->level - 1; i >= 0; i--) {
		//删除的节点前面的指针替换成删除的节点所指
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
