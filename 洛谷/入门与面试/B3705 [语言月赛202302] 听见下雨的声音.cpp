#include<iostream>
using namespace std;
int main() {
    string ans [] = {
        "B", // ˫�������滻Ϊ ���� 1 �Ĵ�
        "A", // ˫�������滻Ϊ ���� 2 �Ĵ�
        "8", // ˫�������滻Ϊ ���� 3 �Ĵ�
        "50", // ˫�������滻Ϊ ���� 4 �Ĵ�
        "6,5,4,3,2,1,", // ˫�������滻Ϊ ���� 5 �Ĵ�
    };
    int T;
    cin >> T;
    cout << ans[T - 1] << endl;
    return 0;
}
