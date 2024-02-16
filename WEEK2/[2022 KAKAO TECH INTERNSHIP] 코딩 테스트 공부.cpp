// [2022 KAKAO TECH INTERNSHIP] 코딩 테스트 공부
// https://school.programmers.co.kr/learn/courses/30/lessons/118668

#include <string>
#include <vector>

#define LEN 200
#define MAX 1000000
using namespace std;

int alp_max = 0;
int cop_max = 0;
    
// dp[i][j]: alp를 i만큼, cop를 j만큼 얻기 위해 필요한 시간
int dp[LEN][LEN] = { 1000000, };

void getMaxAlpCop(vector<vector<int>> problems) {
    // 전체 문제에서 요구하는 알고력과 코딩력의 최대값 구하기
    // problem = [alp_req, cop_req, alp_rwd, cop_rwd, cost]
    for (auto problem : problems) {
        int alp_req = problem[0];
        int cop_req = problem[1];
        alp_max = max(alp_max, alp_req);
        cop_max = max(cop_max, cop_req);
    }
}

void initializeDPArray(int alp, int cop) {
    // dp[i][j] 값 할당
        for(int i = 0; i <= alp_max; i++) {
            for(int j = 0; j <= cop_max; j++) {
                dp[i][j] = MAX;
            }
        }
        dp[alp][cop] = 0;
}

int DP(int alp, int cop, vector<vector<int>> problems) {
    for(int i = alp; i <= alp_max; i++) {
        for(int j = cop; j <= cop_max; j++) {

            // alp와 cop를 1시간 공부를 통해 올리는 경우
            dp[i+1][j] = min(dp[i+1][j], dp[i][j] + 1);
            dp[i][j+1] = min(dp[i][j+1], dp[i][j] + 1);
            
            // alp와 cop를 문제 풀이를 통해 올리는 경우
            for (auto problem : problems) {
                int alp_req = problem[0];
                int cop_req = problem[1];
                int alp_rwd = problem[2];
                int cop_rwd = problem[3];
                int cost = problem[4];
                
                if (i >= alp_req && j >= cop_req) {
                    // max값 도달 자체가 "모든 문제들을 풀 수 있는" 조건을 만족
                    int target_alp = min(alp_max, i + alp_rwd);
                    int target_cop = min(cop_max, j + cop_rwd);
                    dp[target_alp][target_cop] = min(dp[target_alp][target_cop], dp[i][j] + cost);
                }
            }
        }
        return dp[alp_max][cop_max];
    }
}

int solution(int alp, int cop, vector<vector<int>> problems) {
    int answer = 0;
    
    getMaxAlpCop(problems);
    
    // 사용자의 default alp와 cop가 max보다 큰 경우 두 값 중 작은 값으로 고정
    alp = min(alp, alp_max);
    cop = min(cop, cop_max);
    
    initializeDPArray(alp, cop);
    answer = DP(alp, cop, problems);
    
    return answer;
}