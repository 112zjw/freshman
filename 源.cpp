#include <iostream>  
#include <stack>  

using namespace std;

//��һ����
//����СԲ���ƶ�����һ�����ϣ�
//�ڶ�����
//��ʣ�������˵Ķ���Ԫ�ؽ����жϣ��ѽ�С
//���Ǹ�Բ���ƶ����ϴ���Ǹ�Բ���ϣ�����пո���
//���ڿո���)��

char s[4] = { '0','a','b','c' };
stack<int> a[4];

void move(int now, int next) {
    if (!a[now].empty()) { // ȷ���ӵ�ǰջ�ƶ�  
        a[next].push(a[now].top());
        printf("%c -> %c\n", s[now], s[next]); // ��ӻ��з�  
        a[now].pop();
    }
}

int main() {
    int n;
    cin >> n;

    // ��ʼ���������ӴӴ�С����ջ1  
    for (int i = n; i >= 1; i--) {
        a[1].push(i);
    }

    // ��ż�����趨Ŀ������  
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

        // Ѱ�����ƶ�������  
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

        // ����Ƿ����  
        if (a[2].size() == n || a[3].size() == n) break;

        int other1, other2;

        switch (next) {
        case 1: {other1 = 2; other2 = 3; break; }
        case 2: {other1 = 3; other2 = 1; break; }
        case 3: {other1 = 1; other2 = 2; break; }
        }

        // �����ƶ�  
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