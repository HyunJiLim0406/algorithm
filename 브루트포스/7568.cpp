#include <iostream>
using namespace std;

struct Physical { //사람 정보 저장하는 구조체
    int weight;
    int height;
    int score;
};

int main() {
    int N, i, j;

    cin >> N;
    Physical* num = new Physical[N];
    for (i = 0; i < N; i++) { //초기화
        cin >> num[i].weight >> num[i].height;
        num[i].score = 1;
    }
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            if (i != j) {
                if ((num[i].weight < num[j].weight) && (num[i].height < num[j].height)) //나보다 덩치 큰 사람 수 세기
                    num[i].score++;
            }
        }
    }
    for (i = 0; i < N; i++)
        cout << num[i].score << ' ';
}