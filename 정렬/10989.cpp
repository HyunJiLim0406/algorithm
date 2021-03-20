#include <iostream>
using namespace std;

/*이 놈을 풀기위해 했던 짓들
1. 일반적인 counting sort 사용. 배열 3개(input, output, counting) 사용 => 메모리 초과
2. N 크기의 배열을 할당한게 문제였나? 처음부터 max에 맞춰서 전역변수로 선언 => 메모리 초과222
3. 검색해보니까 input, output 배열을 쓰면 안된다고 함. 뭐 어쩌라는건지 욕이 나옴
4. 값 받고 바로 counting 배열에 넣어줌. 10000개 다 도는건 좀 그래서 max도 저장해봄. 그리고 그거 돌면서 걍 출력함 stable sort는 아니게 됐음. => 시간초과
5. 화가 났지만 메모리 초과가 아닌게 어딘가 싶어서 ios웅앵이랑 cin웅앵 추가해줌 => 성공 와!*/

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N, i, j, key, count_arr[10001], max = 0;
    for (i = 1; i < 10001; i++) //자연수라길래 0은 쓸 일 없겠다 싶어서 1부터 함.
        count_arr[i] = 0;

    cin >> N;
    for (i = 0; i < N; i++) {
        cin >> key;
        count_arr[key]++;
        if (key > max)
            max = key;
    }
    for (i = 1; i < max + 1; i++) {
        for (j = 0; j < count_arr[i]; j++)
            cout << i << '\n';
    }
}