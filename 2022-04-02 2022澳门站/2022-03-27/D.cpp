#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;
const int MAXN = 2 * 1e5;
const int MAXM = 2 * 1e5;
class State {
	public:
		int up;
		int down;
		int cover;
		int up1;
		int up2;
		int down1;
		int down2;
		bool isOut;
		State();
		void clear();
};
State::State() {
	this->up = 0;
	this->down = 0;
	this->cover = 0;
	this->up1 = 0;
	this->up2 = 0;
	this->down1 = 0;
	this->down2 = 0;
	this->isOut = false;
}
State::clear() {
	this->up = 0;
	this->down = 0;
	this->cover = 0;
	this->up1 = 0;
	this->up2 = 0;
	this->down1 = 0;
	this->down2 = 0;
	this->isOut = false;
}
State states[MAXN + 1];
queue<int> states_queue[6];
int full, half_full;
int main() {
	int k, l, temp;
	while(~scanf("%d%d", &n, &m)) {
		full = 0;
		half_full = 0;
		l = 0;
		for(int i = 0; i < 6; i++)
			states_queue[i].clear();
		for(int i = 1; i <= m; i++)
			states[i].clear();
			scanf("%d", &k);
			if(k == 0)
				full++;
			if(k == 1) {
				scanf("%d", &k);
				states[k].down++;
				half_full++;
			}
			if(k == 2) {
				scanf("%d", &k);
				states[k].down++;
				states[k].cover++;
				temp = k;
				scanf("%d", &k);
				states[k].up++;
				if(states[k].down1 == 0) {
					states[k].down1 = temp;
					states[temp].up1 = k;
				}
				else {
					states[k].down2 = temp;
					states[temp].up2 = k;
				}
			}
		for(int i = 1; i <= n; i++) {
			if(states[i].down == 2 && states[i].cover == 2)
				states_queue[0].push(i);
			if(states[i].up == 2)
				states_queue[1].push(i);
			if(states[i].up == 1 && states[i].cover == 1)
				states_queue[2].push(i);
			if(states[i].up == 1 && states[i].cover == 0)
				states_queue[3].push(i);
			if(states[i].down == 2 && states[i].cover == 1)
				states_queue[4].push(i);
			if(states[i].down == 2 && states[i].cover == 0)
				states_queue[5].push(i);
		}
		while(!states_queue[3].empty() || !states_queue[5].empty()) {
			if(!states_queue[3].empty()) {
				int temp_state = states_queue[3].front();
				states[states[temp_state].down1].cover--;
				if(states[states[temp_state].down1].up1 == states[temp_state])
					states[states[temp_state].down1].up1 = 0;
				else
					states[states[temp_state].down1].up2 = 0;
				if(states[states[temp_state].down1].up == 1 && states[states[temp_state].down1].cover == 0)
					states_queue[3].push(states[temp_state].down1);
				if(states[states[temp_state].down1].down == 2 && states[states[temp_state].down1].cover == 1)
					states_queue[4].push(states[temp_state].down1);
				if(states[states[temp_state].down1].down == 2 && states[states[temp_state].down1].cover == 0)
					states_queue[5].push(states[temp_state].down1);
				states_queue[3].pop()
				l++;
				states[temp_state].isOut = true;
			}
			else if(!states_queue[5].empty()) {
				int temp_state = states_queue[5].front();
				states[temp_state].down--;
				states[temp_state].up++;
				half_full -= 2;
				full++;
				states_queue[5].pop()
				l++;
				states[temp_state].isOut = true;
			}
		}
		while(!states_queue[0].empty() || !states_queue[1].empty() || !states_queue[2].empty() || !states_queue[4].empty()) {
			if(!states_queue[4].empty()) {
				while(states[states_queue[4].front()].isOut)
					states_queue[4].pop();
				if(full >= 1) {
					int temp_state = states_queue[4].front();
					int temp_up;
					if(states[temp_state].up1 != 0)
						temp_up = states[temp_state].up1;
					else
						temp_up = states[temp_state].up2;
					states[temp_up].down++;
					states[temp_up].up--;
					states[temp_state].cover--;
					if(states[temp_state].up1 == states[temp_state])
						states[temp_state].up1 = 0;
					else
						states[temp_state].up2 = 0;
					if(states[temp_state].up == 1 && states[temp_state].cover == 0)
						states_queue[3].push(temp_state);
					if(states[temp_state].down == 2 && states[temp_state].cover == 1)
						states_queue[4].push(temp_state);
					if(states[temp_state].down == 2 && states[temp_state].cover == 0)
						states_queue[5].push(temp_state);
					half_full += 2;
					full--;
					states_queue[2].pop()
					l++;
				}
			}
			
			else if(!states_queue[2].empty()) {
				while(states[states_queue[2].front()].isOut)
					states_queue[2].pop();
				if(full >= 1) {
					int temp_state = states_queue[2].front();
					states[temp_state].down++;
					states[temp_state].up--;
					states[states[temp_state].down1].cover--;
					if(states[states[temp_state].down1].up1 == states[temp_state])
						states[states[temp_state].down1].up1 = 0;
					else
						states[states[temp_state].down1].up2 = 0;
					if(states[states[temp_state].down1].up == 1 && states[states[temp_state].down1].cover == 0)
						states_queue[3].push(states[temp_state].down1);
					if(states[states[temp_state].down1].down == 2 && states[states[temp_state].down1].cover == 1)
						states_queue[4].push(states[temp_state].down1);
					if(states[states[temp_state].down1].down == 2 && states[states[temp_state].down1].cover == 0)
						states_queue[5].push(states[temp_state].down1);
					half_full += 2;
					full--;
					states_queue[2].pop()
					l++;
				}
			}
			
			else if(!states_queue[1].empty()) {
				while(states[states_queue[1].front()].isOut)
					states_queue[1].pop();
				if(full >= 1) {
					int temp_state = states_queue[1].front();
					states[temp_state].down++;
					states[temp_state].up--;
					states[states[temp_state].down1].cover--;
					if(states[states[temp_state].down1].up1 == states[temp_state])
						states[states[temp_state].down1].up1 = 0;
					else
						states[states[temp_state].down1].up2 = 0;
					states[states[temp_state].down2].cover--;
					if(states[states[temp_state].down2].up1 == states[temp_state])
						states[states[temp_state].down2].up1 = 0;
					else
						states[states[temp_state].down2].up2 = 0;
					if(states[states[temp_state].down1].up == 1 && states[states[temp_state].down1].cover == 0)
						states_queue[3].push(states[temp_state].down1);
					if(states[states[temp_state].down1].down == 2 && states[states[temp_state].down1].cover == 1)
						states_queue[4].push(states[temp_state].down1);
					if(states[states[temp_state].down1].down == 2 && states[states[temp_state].down1].cover == 0)
						states_queue[5].push(states[temp_state].down1);
					if(states[states[temp_state].down2].up == 1 && states[states[temp_state].down2].cover == 0)
						states_queue[3].push(states[temp_state].down2);
					if(states[states[temp_state].down2].down == 2 && states[states[temp_state].down2].cover == 1)
						states_queue[4].push(states[temp_state].down2);
					if(states[states[temp_state].down2].down == 2 && states[states[temp_state].down2].cover == 0)
						states_queue[5].push(states[temp_state].down2);
					half_full += 2;
					full--;
					states_queue[1].pop()
					l += 2;
					states[temp_state].isOut = true;
				}
			}
			
			else if(!states_queue[0].empty())
				while(states[states_queue[0].front()].isOut)
					states_queue[0].pop();
		}
	}
	return 0;
} 
