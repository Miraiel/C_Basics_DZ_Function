#include <iostream>

#include <iostream>
using namespace std;

void search(int* mas, int b, int e, int x, int* low, int* high) {
    if (b > e) return;
    int mid = (e + b) / 2;
    if (mas[mid] > x) search(mas, b, mid - 1, x, low, high);
    else if (mas[mid] < x) search(mas, mid + 1, e, x, low, high);
    else {
        int l = mid;
        int h = mid;
        while (l > b && mas[l - 1] == x) l--;
        while (h < e && mas[h + 1] == x) h++;
        *low = l;
        *high = h;
    }
}

int main()
{
    int m[] = { 3, 4, 4, 4, 5, 6, 7, 7, 8, 9 };
    int low, high;
    low = -1,
        high = -1;
    search(m, 0, 9, 5, &low, &high);
    // Если low и  high остались -1 - то элемент не найден.
    cout << low << " " << high;
    return 0;
}
