#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>
using namespace std;

// cos pro c++ 1급 코딩 문제
// 평균 점수가 가장 높은 지원자의 순번과 점수 구하기

double getAvg(vector<int> &v) {
    int sum = 0;
    for (int i = 1; i < 3; i++) {
        sum += v[i];
    }
    double avg = (double)sum / 2;
    return avg;
}

int main() {

    int cnt; // 지원자 수

    srand(time(NULL)); // 각 지원자의 점수를 난수 발생으로 랜덤 생성

    do {
        cout << "지원자 수를 입력 : ";
        cin >> cnt;
        if (cnt < 2 || cnt > 100) {
            cout << "조건에 맞도록 재입력" << endl;
        }
    } while (cnt > 100 || cnt < 2);

    // 벡터를 사용해 2차원 배열 구현
    vector<vector<int>> scores(cnt, vector<int>(4, 0));

    for (int i = 0; i < cnt; i++) {
        for (int j = 0; j < 4; j++) {
            scores[i][j] = rand() % 21 + 80;
        }
        sort(scores[i].begin(), scores[i].end());
    }

    // 딕셔너리(map) 사용해 지원자 ( 순번 : 평균값 ) 형식 저장
    map<int, double> maxAvg;

    for (int i = 0; i < cnt; i++) {
        cout << i + 1 << " 번째 지원자의 점수 목록 : ";
        for (int j = 0; j < 4; j++) {
            cout << scores[i][j] << " ";
        }
        cout << endl;
        maxAvg.insert(make_pair(i, getAvg(scores[i])));
    }

    // 비교할 값의 초기 설정
    int topIdx = 0;
    double topAvg = maxAvg[0];

    for (auto it = maxAvg.begin(); it != maxAvg.end(); it++) {
        if(it->second > topAvg) {
            topIdx = it->first;
            topAvg = it->second;
        }
    }
    
    cout << "가장 높은 평균 점수는 " << topIdx+1 << "번 지원자의 평균 점수인 "
        << topAvg << "점입니다." << endl;

    return 0;
}