// [2022 KAKAO TECH INTERNSHIP] 성격 유형 검사하기
// https://school.programmers.co.kr/learn/courses/30/lessons/118666

#include <string>
#include <vector>
#include <map>

using namespace std;

string solution(vector<string> survey, vector<int> choices) {
    string answer = "";
    
    // choices의 숫자가 1부터 시작하므로 index 0번째의 요소를 0으로 지정한다. 
    int scoreX[8] = {0, 3, 2, 1, 0, 1, 2, 3};
    
    map<char, long long> m;
    
    m['R'] = 0;
    m['T'] = 0;
    m['C'] = 0;
    m['F'] = 0;
    m['J'] = 0;
    m['M'] = 0;
    m['A'] = 0;
    m['N'] = 0;
    
    for(int i =0; i < survey.size(); i++) {
        int idx = choices[i];
        if (idx < 4) {
            m[survey[i][0]] += scoreX[idx];
        } else {
            m[survey[i][1]] += scoreX[idx];
        }
    }
    
    // 사전 순으로 R > T | C > F | J > M | A > N
    if (m['R'] >= m['T']) {
        answer += 'R';
    } else {
        answer += 'T';
    }
        
    if (m['C'] >= m['F']) {
        answer+= 'C';
    } else {
        answer += 'F';
    }
        
    if (m['J'] >= m['M']) {
        answer += 'J';
    } else {
        answer += 'M';
    }
        
    if (m['A'] >= m['N']) {
        answer += 'A';
    } else {
        answer += 'N';
    }
    return answer;
}