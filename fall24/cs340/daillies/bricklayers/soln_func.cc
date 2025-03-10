#include <algorithm>
int r_bricklayers(int b, int * first, int * last,  int len) {
    if (first >= last) { return -1; }
    int walls = len / b;
    int time = *last;
    for (int i = 0; i < walls - 1; ++i) {
        time += *first++;
    }
    return std::max(time, r_bricklayers(b - 1, first, last - 1, len - walls));
}
int bricklayers(int b, int a[], int len) {
    if (b <= 0 || len <= 0) {return -1; }
    std::sort(a, a + len);
    int time = (r_bricklayers(b, a, a + len - 1, len));
    return (time > 0) ? time : -1;

}

