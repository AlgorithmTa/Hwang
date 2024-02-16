// [2023 KAKAO BLIND RECRUITMENT] 택배 배달과 수거하기
// https://school.programmers.co.kr/learn/courses/30/lessons/150369?language=cpp

#include <string>
#include <vector>

using namespace std;

long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
    long long answer = 0;
    
    int deliveryAvailability = 0;
    int pickupAvailability = 0;
    int roundtripNum = 0;
    for(int i = n - 1; i >= 0; i--) {
        deliveryAvailability -= deliveries[i];
        pickupAvailability -= pickups[i];
        
        while(true) {
						// 택배를 배달(수거)할 수 있느냐 없느냐의 판별문
            if (deliveryAvailability >= 0 && pickupAvailability >= 0) {
                break;
            }
						// 택배 배달(수거)을 실패한 경우, 한 번 더 왕복해야하므로 cap만큼 plus
						// 예를 들면, cap = 2, deliveries[i] = 6인 경우 3번 왕복이 필요
            deliveryAvailability += cap;
            pickupAvailability += cap;
            roundtripNum += 1;
        }
        answer += (i + 1) * 2 * roundtripNum;
        roundtripNum = 0;
    }
    return answer;
}