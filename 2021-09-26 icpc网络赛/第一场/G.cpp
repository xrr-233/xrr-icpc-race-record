#include <iostream>
#include <string>
using namespace std;

class Node {
	public:
		Node* left;
		Node* right;
		int depth;
		string result;
		Node();
};
Node::Node() {
	this->left = NULL;
	this->right = NULL;
	this->result = "";
}
string ip, ip_bin_str_part, ip_bin_str, next_hop, ans;

inline string get_bin(int v) {
	string temp = "00000000";
	register int ptr = 7;
	while(v != 0) {
		temp[ptr--] = (v % 2) + '0';
		v /= 2;
	}
	return temp;
}

string M[300];
int main() {
	for(register int i = 0; i < 256; i++) {
		M[i] = get_bin(i);
	}
	register int n, len, v, wei, depth, yanma;
	cin >> n;
	Node* root = new Node();
	Node* temp;
	ip_bin_str = "00000000000000000000000000000000";
	while(n--) {
		cin >> ip >> yanma >> next_hop;
		len = ip.length();
		v = 0;
		wei = 0;
		for(register int i = 0; i <= len; i++) {
			if(i < len && ip[i] != '.') {
				v = v * 10 + (ip[i] - '0');
			}
			else {
				ip_bin_str_part = M[v];
				for(register int j = wei; j < wei + 8; j++) {
					ip_bin_str[j] = ip_bin_str_part[j % 8];
				}
				v = 0;
				wei += 8;
			}
		}
		//cout << ip_bin_str << endl;
		temp = root;
		depth = 0;
		if(yanma == 0)
			root->result = next_hop;
		while(depth < 32) {
			if(ip_bin_str[depth] == '0') {
				if(temp->left != NULL)
					temp = temp->left;
				else {
					Node* new_node = new Node();
					new_node->depth = depth + 1;
					temp->left = new_node;
					temp = temp->left;
				}
			}
			else {
				if(temp->right != NULL)
					temp = temp->right;
				else {
					Node* new_node = new Node();
					new_node->depth = depth + 1;
					temp->right = new_node;
					temp = temp->right;
				}
			}
			depth++;
			if(depth == yanma)
				temp->result = next_hop;
		}
	}
	cin >> n;
	while(n--) {
		cin >> ip;
		len = ip.length();
		v = 0;
		wei = 0;
		for(register int i = 0; i <= len; i++) {
			if(i < len && ip[i] != '.') {
				v = v * 10 + (ip[i] - '0');
			}
			else {
				ip_bin_str_part = M[v];
				for(register int j = wei; j < wei + 8; j++) {
					ip_bin_str[j] = ip_bin_str_part[j % 8];
				}
				v = 0;
				wei += 8;
			}
		}
		temp = root;
		depth = 0;
		ans = root->result;
		while(depth < 32) {
			if(ip_bin_str[depth] == '0') {
				if(temp->left != NULL)
					temp = temp->left;
				else
					break;
			}
			else {
				if(temp->right != NULL)
					temp = temp->right;
				else
					break;
			}
			depth++;
			if(temp->result != "")
				ans = temp->result;
		}
		cout << ans << endl;
	}
	return 0;
}
