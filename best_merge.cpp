#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool sort_fun(int a, int b) {
    if (a >= b) return false;
    else return true;
}
int main() {
    int n, temp;
    cin >> n;
    vector<int> len;
    for (int i = 0; i < n; i++) {
        cin >> temp;
        len.push_back(temp);
    }
    if (len.size() == 1) {
        return 0; //作为主函数无意义，
    }
    sort(len.begin(), len.end(), sort_fun);

    vector<int>::iterator p = len.begin();
    int sum = 0;
    while (len.size() > 2)
    {
        int temp=len[0] + len[1];
        sum += temp - 1;
        len.erase(len.begin());
        len.erase(len.begin());
        p = len.begin();
        for ( ; p != len.end(); p++) {
            if (temp < *p) {
                break;
            }
        }
        if (p == len.end()) len.push_back(temp);
        else len.insert(p,temp);
    }
    sum += len[0] + len[1]-1;
    cout << len.size() <<  " " << sum << endl;
    system("pause");
}
