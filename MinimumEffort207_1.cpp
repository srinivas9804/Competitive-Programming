//#include <iostream>
//#include <string>
//#include <map>
//#include <sstream>
//#include <queue>
//#include <list>
//#include <functional>
//#define INF 0x5FFFFFFF;//Max Value
//using namespace std;
//list<int> vertices;
//int dist[200] ;
//typedef pair<int, int> Edge;//First value represents distance becuase by default first element is compared
//string input[200];
//list <pair<int, int> > *graph = new list<Edge>[200];
//int parent[200];
//priority_queue <Edge, vector<Edge>, greater<Edge> > pq;
//
//void dijkstras() {
//	while (!pq.empty()) {
//		int u = pq.top().second;
//		pq.pop();
//		list<pair<int, int> >::iterator i;
//		for (i = graph[u].begin(); i != graph[u].end(); i++) {
//			int v = i->second;
//			int distance = i->first;
//			if (dist[v] > (dist[u] + distance)) {
//				dist[v] = dist[u] + distance;
//				pq.push(make_pair(dist[v], v));
//				parent[v] = u;
//			}
//		}
//	}
//}
//
//int main() {
//	int ctr = 0;
//	int n = 0;
//	string in;
//	while (getline(cin, in)) {
//		graph = new list<Edge>[200];
//		stringstream ss(in);
//		ss >> n;
//		int start = 0;
//		int end = 0;
//		map <string, int> m;
//		for (int i = 0; i < n; i++) {
//			getline(cin, input[i]);
//			m[input[i]] = i;
//			parent[i] = -1;
//			vertices.push_back(i);
//			if (input[i] == "office") {
//				dist[i] = 0;
//				start = i;
//				continue;
//			}
//			else if (input[i] == "hall")
//				end = i;
//			dist[i] = INF;
//		}
//		int p = 0;
//		getline(cin, in);
//		stringstream s1(in);
//		s1 >> p;
//		for (int i = 0; i < p; i++) {
//			bool flag = true;
//			map <string, int>::iterator it;
//			map <string, int>::iterator it1;
//			map <string, int>::iterator it2;
//			string str;
//			string p1;
//			string p2;
//			int w1 = 0;
//			int w2 = 0;
//			getline(cin, str);
//			int j = 0;
//			for (; j < (int)str.length(); j++) {
//				if (str[j] == ':') {
//					flag = false;
//					continue;
//				}
//				if (flag == true) {
//					p1 += str[j];
//					continue;
//				}
//				if (str[j] == ' '&& str[j + 1] >= '0'&&str[j + 1] <= '9') {//found a number check if it is a part of the string
//					it2 = m.find(p2);
//					if (it2 == m.end()) {
//						p2 += str[j];
//						continue;
//					}
//					else {
//						w1 = str[++j] - '0';
//						while (j <(int)str.length() && str[++j] >= '0'&&str[j] <= '9') {
//							w1 = (w1 * 10) + str[j] - '0';
//						}
//						break;
//					}
//					
//				}
//				else
//					p2 += str[j];
//			}
//			it = m.find(p1);
//			it1 = m.find(p2);
//			int u = it->second;
//			int v = it1->second;
//
//			graph[u].push_back(make_pair(w1,v));
//			while  ((++j) < (int)str.length()&& str[j]>='0'&&str[j]<='9') {
//				w2 = (w2*10) + str[j] - '0';
//			}	
//			if(w2>0)
//				graph[v].push_back(make_pair(w2, u));
//		}
//		pq.push(make_pair(0, start));
//		dijkstras();
//		string output = " -> hall ";
//		int x = parent[end];
//		while (parent[x] != -1) {
//			output = " -> " + input[x] + output;
//			x = parent[x];
//		}
//		output = "office" + output;
//		int distance = dist[end];
//		for (int i = 0; i < n; i++) {
//			if (i == end) {
//				dist[i] = 0;
//			}
//			else
//				dist[i] = INF;
//			parent[i] = -1;
//		}
//		pq.push(make_pair(0, end));
//		dijkstras();
//		string output2;
//		output2="-> office";
//		distance += dist[start];
//		x = parent[x];
//		while (parent[x] != -1) {
//
//			output2 = "-> " + input[x] + " " + output2;
//			x = parent[x];
//		}
//		output += output2;
//		cout << distance << endl;
//		cout << output << endl << endl;
//		
//	}
//	return 0;
//}