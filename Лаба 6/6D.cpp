#include <iostream>
 
using namespace std;
 
#define int long long
 
class AAA {
    public:
        int S[350000];
        bool flag;
        int x;
    private:
        int counter;
        
    public: AAA() {
        flag = false;
        counter = 0;
        x = 0;
    }
    int Next(int n) {
        int min = -1;
        bool flag1 = false;
        for (int i=0; i<counter; i++) {
            if ((flag1 == false) && (S[i])>=n) {
                min = S[i];
                flag1 = true;
            } else if (S[i]<=min) min = S[i]; 
        }
        flag1 = true;
        x = min;
        return min;
    }
    void Add(int n) {
        if (flag == true) {
            S[counter] = n+x;
            flag = false;
        } else S[counter] = n;
        counter++;
    }
};
 
int32_t main() {
    AAA A;
    int k;
    cin >> k;
    char last = '+';
    int y = -1;
    while (k--) {
        int n;
        char ch;
        cin >> ch >> n;
        if (ch == '+') {
            if (last == '?') n = (n + y) % 1000000000;
            A.Add(n);
            //cout << "+ " << n << endl;
        } else {
            y = A.Next(n);
            //cout << "? " << y << endl;
            cout << y << endl;
        }
        last = ch;
    }
}
