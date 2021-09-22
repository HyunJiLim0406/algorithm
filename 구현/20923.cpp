#include <iostream>
#include <deque>

using namespace std;

void moveCard(deque<int> &deck, deque<int> &ground) {
    while (!ground.empty()) {
        deck.push_back(ground.back());
        ground.pop_back();
    }
}

int main() {
    int n, m, num1, num2;
    deque<int> deck[2], ground[2];

    cin >> n >> m;
    while (n--) {
        cin >> num1 >> num2;
        deck[0].push_front(num1);
        deck[1].push_front(num2);
    }

    bool turn = false;
    while (m--) { //m번의 턴
        if (deck[turn].size() <= 1 || deck[!turn].empty()) { //empty거나, empty가 된다면
            if (deck[turn].size() == 1)
                deck[turn].pop_front();
            break;
        }
        int card = deck[turn].front();
        ground[turn].push_front(card);
        deck[turn].pop_front();

        int bell = -1; //종을 칠 사람
        if (card == 5) //도도
            bell = 0;
        else if (!ground[0].empty() && !ground[1].empty() && (card + ground[!turn].front() == 5)) //수연
            bell = 1;

        turn = !turn; //턴 바꾸기
        if (bell == -1) //종을 칠 사람이 없음
            continue;
        moveCard(deck[bell], ground[!bell]);
        moveCard(deck[bell], ground[bell]);
    }

    if (deck[0].size() > deck[1].size())
        cout << "do\n";
    else if (deck[0].size() < deck[1].size())
        cout << "su\n";
    else
        cout << "dosu\n";
}