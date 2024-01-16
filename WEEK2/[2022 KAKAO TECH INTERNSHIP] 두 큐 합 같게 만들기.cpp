// [2022 KAKAO TECH INTERNSHIP] 두 큐 합 같게 만들기
// https://school.programmers.co.kr/learn/courses/30/lessons/118667

#include <string>
#include <vector>

using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
    int answer = 0;
    
    vector<int> connectedQV;
    long long queue1Sum = 0;
    long long queue2Sum = 0;

    int s1 = 0;
    int e1 = queue1.size() - 1;
    int s2 = queue1.size();
    int e2 = queue1.size() * 2 - 1;

    for(int i = 0; i < queue1.size(); i++) {
        connectedQV.push_back(queue1[i]);
        queue1Sum += queue1[i];
    }
    
    for(int i = 0; i < queue2.size(); i++) {
        connectedQV.push_back(queue2[i]);
        queue2Sum += queue2[i];
    }
    
    int size = queue1.size() * 2;
    
    while(answer <= size * 2) {
        if (queue1Sum < queue2Sum) {
            queue2Sum -= connectedQV[s2 % size];
            s2 += 1;
            e1 += 1;
            queue1Sum += connectedQV[e1 % size];
        } else if (queue1Sum > queue2Sum) {
            queue1Sum -= connectedQV[s1 % size];
            s1 += 1;
            e2 += 1;
            queue2Sum += connectedQV[e2 % size];
        } else {
            return answer;
        }
        answer += 1;
    }
    
    return -1;
}