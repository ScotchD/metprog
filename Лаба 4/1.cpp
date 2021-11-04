#include<fstream>
#include<queue>
#include <vector>
#include <string>

using namespace std;

int main() {
       int x1, y1, x2, y2;
       string a1;
       queue <pair<int, int>> q; // будем хранить координаты исследуемой клетки
       ifstream in("input.txt");
       ofstream out("output.txt"); out.clear();
       in >> a1;    // координаты первого кон€
       x1 = a1[0] - 'a'; // пересчитываем в числа
       y1 = a1[1] - '1';
       in >> a1;    // координаты второго кон€
       x2 = a1[0] - 'a'; // пересчитываем в числа
       y2 = a1[1] - '1';
       vector <vector <int>>  a(8, vector <int>(8, 1000000)); // доска первого кон€
       vector <vector <int>>  c(8, vector <int>(8, 1000000)); // доска второго кон€
       // заполним доску первого кон€
       a[x1][y1] = 0;      // ѕуть 1-й €чейки равен 0
       q.push(make_pair(x1, y1)); 
       while (!q.empty()) { 
             pair <int, int> b;
             b = q.front(); // берем из очереди координаты €чейки
             q.pop();            // и стираем верхушку очереди
             // всего есть 8 вариантов хода конем
             // в каждую подход€щую клетку заносим длину пути
             // и координаты отправл€ем в очередь
             if (b.first < 6 && b.second < 7 && // 1
                    a[b.first + 2][b.second + 1] == 1000000) {
                    a[b.first + 2][b.second + 1] = a[b.first][b.second] + 1;
                    q.push(make_pair(b.first + 2, b.second + 1));
             }
             if (b.first < 7 && b.second < 6 && // 2
                    a[b.first + 1][b.second + 2] == 1000000) {
                    a[b.first + 1][b.second + 2] = a[b.first][b.second] + 1;
                    q.push(make_pair(b.first + 1, b.second + 2));
             }
             if (b.first < 6 && b.second > 0 && // 3
                    a[b.first + 2][b.second - 1] == 1000000) {
                    a[b.first + 2][b.second - 1] = a[b.first][b.second] + 1;
                    q.push(make_pair(b.first + 2, b.second - 1));
             }
             if (b.first > 0 && b.second < 6 && // 4
                    a[b.first - 1][b.second + 2] == 1000000) {
                    a[b.first - 1][b.second + 2] = a[b.first][b.second] + 1;
                    q.push(make_pair(b.first - 1, b.second + 2));
             }
             if (b.first > 1 && b.second < 7 && // 5
                    a[b.first - 2][b.second + 1] == 1000000) {
                    a[b.first - 2][b.second + 1] = a[b.first][b.second] + 1;
                    q.push(make_pair(b.first - 2, b.second + 1));
             }
             if (b.first < 7 && b.second > 1 && // 6
                    a[b.first + 1][b.second - 2] == 1000000) {
                    a[b.first + 1][b.second - 2] = a[b.first][b.second] + 1;
                    q.push(make_pair(b.first + 1, b.second - 2));
             }
             if (b.first > 0 && b.second > 1 && // 7
                    a[b.first - 1][b.second - 2] == 1000000) {
                    a[b.first - 1][b.second - 2] = a[b.first][b.second] + 1;
                    q.push(make_pair(b.first - 1, b.second - 2));
             }
             if (b.first > 1 && b.second > 0 && // 8
                    a[b.first - 2][b.second - 1] == 1000000) {
                    a[b.first - 2][b.second - 1] = a[b.first][b.second] + 1;
                    q.push(make_pair(b.first - 2, b.second - 1));
             }
       }
       // заполним доску второго кон€
       c[x2][y2] = 0;      // ѕуть 1-й €чейки равен 0
       q.push(make_pair(x2, y2));  
       while (!q.empty()) { 
             pair <int, int> b;
             b = q.front(); // берем из очереди координаты €чейки
             q.pop();            // и стираем верхушку очереди
             // всего есть 8 вариантов хода конем
             // Ќо сначала проверим, не добрались ли мы до финиша
             if (a[b.first][b.second] == c[b.first][b.second]) { // кони встретились
                    out << a[b.first][b.second];
                    return 0;
             }
             // в каждую подход€щую клетку заносим длину пути
             // и координаты отправл€ем в очередь
             if (b.first < 6 && b.second < 7 && // 1
                    c[b.first + 2][b.second + 1] == 1000000) {
                    c[b.first + 2][b.second + 1] = c[b.first][b.second] + 1;
                    q.push(make_pair(b.first + 2, b.second + 1));
             }
             if (b.first < 7 && b.second < 6 && // 2
                    c[b.first + 1][b.second + 2] == 1000000) {
                    c[b.first + 1][b.second + 2] = c[b.first][b.second] + 1;
                    q.push(make_pair(b.first + 1, b.second + 2));
             }
             if (b.first < 6 && b.second > 0 && // 3
                    c[b.first + 2][b.second - 1] == 1000000) {
                    c[b.first + 2][b.second - 1] = c[b.first][b.second] + 1;
                    q.push(make_pair(b.first + 2, b.second - 1));
             }
             if (b.first > 0 && b.second < 6 && // 4
                    c[b.first - 1][b.second + 2] == 1000000) {
                    c[b.first - 1][b.second + 2] = c[b.first][b.second] + 1;
                    q.push(make_pair(b.first - 1, b.second + 2));
             }
             if (b.first > 1 && b.second < 7 && // 5
                    c[b.first - 2][b.second + 1] == 1000000) {
                    c[b.first - 2][b.second + 1] = c[b.first][b.second] + 1;
                    q.push(make_pair(b.first - 2, b.second + 1));
             }
             if (b.first < 7 && b.second > 1 && // 6
                    c[b.first + 1][b.second - 2] == 1000000) {
                    c[b.first + 1][b.second - 2] = c[b.first][b.second] + 1;
                    q.push(make_pair(b.first + 1, b.second - 2));
             }
             if (b.first > 0 && b.second > 1 && // 7
                    c[b.first - 1][b.second - 2] == 1000000) {
                    c[b.first - 1][b.second - 2] = c[b.first][b.second] + 1;
                    q.push(make_pair(b.first - 1, b.second - 2));
             }
             if (b.first > 1 && b.second > 0 && // 8
                    c[b.first - 2][b.second - 1] == 1000000) {
                    c[b.first - 2][b.second - 1] = c[b.first][b.second] + 1;
                    q.push(make_pair(b.first - 2, b.second - 1));
             }
       }
       out << -1;
       return 0;
}
