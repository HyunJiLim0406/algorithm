#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct info { //학생번호, 추천 횟수, 게시 시기
    int student, cnt, post_time;
};

vector<info> photo;

int findPos(int student) { //이미 게시된 학생인지 확인
    for (int i = 0; i < photo.size(); i++) {
        if (photo[i].student == student)
            return i;
    }
    return -1;
}

int main() {
    int N, s, num, idx = 0, t = 0;

    cin >> N >> s;
    photo.assign(N, {-1, -1, -1});
    while (s--) {
        cin >> num;
        int pos = findPos(num);
        if (pos != -1) //이미 게시된 학생이면 추천 횟수 갱신
            photo[pos].cnt++;
        else if (idx < N) //사진틀 비어있으면 추가
            photo[idx++] = {num, 1, t};
        else { //사진틀 꽉참
            sort(photo.begin(), photo.end(), //추천횟수, 게시 시기로 정렬
                 [](const info &i1, const info &i2) {
                     if (i1.cnt != i2.cnt)
                         return i1.cnt < i2.cnt;
                     return i1.post_time < i2.post_time;
                 });
            photo[0] = {num, 1, t}; //학생 교체
        }
        t++; //게시 시기
    }
    sort(photo.begin(), photo.end(), //학생 번호로 정렬
         [](const info &i1, const info &i2) {
             return i1.student < i2.student;
         });
    for (auto stu:photo)
        cout << stu.student << ' ';
}