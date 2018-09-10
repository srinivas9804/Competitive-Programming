//#include<cstdio>
//#include<cstring>
//#include<cmath>
//#include<algorithm>
//#include<queue>
//using namespace std;
//int convert(char c)
//{
//	switch (c)
//	{
//	case 'A':
//		return 0;
//	case 'T':
//		return 1;
//	case 'C':
//		return 2;
//	case 'G':
//		return 3;
//	}
//}
//struct node
//{
//	node *next[4] = { 0, 0, 0 ,0 };
//	node *fail = 0;
//	int sum = 0, id = 0;
//};
//char pattern[100005];
//char key[100005];
//int T, n, ans[100005], to[100005];
//node *root;
//void Insert(char *s, int T){
//	node *p = root;
//	for (int i = 0; s[i]; i++){
//		int x = convert(s[i]);
//		if (!p->next[x]){
//			node *newnode = new node;
//			p->next[x] = newnode;
//		}
//		p = p->next[x];
//	}
//	p->sum++;
//	if (p->sum == 1)
//		p->id = T;
//	else 
//		to[T] = p->id;
//}
//void build_fail_pointer(){
//	queue<node*> q;
//	q.push(root);
//	node *p, *tmp;
//	while (!q.empty()){
//		tmp = q.front(); 
//		q.pop();
//		for (int i = 0; i < 4; i++){
//			if (tmp->next[i]){
//				if (tmp == root)
//					tmp->next[i]->fail = root;
//				else{
//					p = tmp->fail;
//					while (p){
//						if (p->next[i]){
//							tmp->next[i]->fail = p->next[i];
//							break;
//						}
//						p = p->fail;
//					}
//					if (!p)
//						tmp->next[i]->fail = root;
//				}
//				q.push(tmp->next[i]);
//			}
//		}
//	}
//}
//void ac_automation(char *s)
//{
//	node *p = root;
//	int len = strlen(s);
//	for (int i = 0; i < len; i++)
//	{
//		int x = convert(s[i]);
//		while (!p->next[x] && p != root)p = p->fail;
//		p = p->next[x];
//		if (!p)p = root;
//		node *tmp = p;
//		while (tmp != root)
//		{
//			ans[tmp->id]++;
//			tmp = tmp->fail;
//		}
//	}
//}
//int main()
//{	
//	scanf("%d\n", &T);
//	for (int t = 1; t <= T; t++)
//	{
//		scanf("\n");
//		gets(pattern);
//		scanf("%d\n", &n);
//		root = new node;
//		memset(to, -1, sizeof(to));
//		for (int i = 1; i <= n; i++)
//		{
//			gets(key);
//			Insert(key, i);
//		}
//		memset(ans, 0, sizeof(ans));
//		build_fail_pointer();
//		ac_automation(pattern);
//		printf("Case #%d\n", t);
//		for (int i = 1; i <= n; i++)
//			if (to[i] == -1)printf("%d\n", ans[i]);
//			else printf("%d\n", ans[to[i]]);
//	}
//	return 0;
//}