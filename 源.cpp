#include <iostream>  
#include <stack>  

using namespace std;

//第一步：
//将最小圆盘移动到下一个杆上；
//第二步：
//对剩下两个杆的顶上元素进行判断，把较小
//的那个圆盘移动到较大的那个圆盘上（如果有空杆则
//移在空杆上)。

char s[4] = { '0','a','b','c' };
stack<int> a[4];

void move(int now, int next) {
    if (!a[now].empty()) { // 确保从当前栈移动  
        a[next].push(a[now].top());
        printf("%c -> %c\n", s[now], s[next]); // 添加换行符  
        a[now].pop();
    }
}

int main() {
    int n;
    cin >> n;

    // 初始化，将盘子从大到小放入栈1  
    for (int i = n; i >= 1; i--) {
        a[1].push(i);
    }

    // 奇偶处理，设定目标柱子  
    if (n % 2 == 1) {
        s[2] = 'c';
        s[3] = 'b';
    }
    else {
        s[2] = 'b';
        s[3] = 'c';
    }

    while (true) {
        int next = 1;

        // 寻找已移动的盘子  
        for (int i = 1; i <= 3; i++) {
            if (!a[i].empty()) {
                if (a[i].top() == 1) {
                    if (i == 3) next = 1;
                    else next = i + 1;
                    move(i, next);
                    break;
                }
            }
        }

        // 检查是否完成  
        if (a[2].size() == n || a[3].size() == n) break;

        int other1, other2;

        switch (next) {
        case 1: {other1 = 2; other2 = 3; break; }
        case 2: {other1 = 3; other2 = 1; break; }
        case 3: {other1 = 1; other2 = 2; break; }
        }

        // 进行移动  
        if (a[other1].empty()) {
            move(other2, other1);
        }
        else if (a[other2].empty()) {
            move(other1, other2);
        }
        else {
            if (a[other1].top() < a[other2].top())
                move(other1, other2);
            else
                move(other2, other1);
        }
    }

    return 0;
}