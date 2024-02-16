// [2023 KAKAO BLIND RECRUITMENT] 이모티콘 할인행사
// https://school.programmers.co.kr/learn/courses/30/lessons/150368

#include <string>
#include <vector>

#define MAXDISCOUNTRATE 40

using namespace std;

int maxPrice = 0;
int maxPeopleNum = 0;

struct EmoticonInfo {
    int price;
    int discountRate;
};

vector<EmoticonInfo> emoticonDiscountedV(7, {0, 0});

void DFS(int depth, int emoticonSize, vector<vector<int>> users, vector<int> emoticons) {
    if (depth < emoticonSize) {
        for(int i = 10; i <= MAXDISCOUNTRATE;) {
            emoticonDiscountedV[depth].price = (100 - i) * emoticons[depth] / 100;
            emoticonDiscountedV[depth].discountRate = i;
            DFS(depth + 1, emoticonSize, users, emoticons);
            i += 10;
        }
    } else {
        int totalPrice = 0;
        int plusSubscribePeopleNum = 0;
        
        int tempPrice = 0;
        int userMinimumAffordableRate = 0;
        int userMaximumAffordablePrice = 0;
        for(int i = 0; i < users.size(); i++) {
            tempPrice = 0;
            userMinimumAffordableRate = users[i][0];
            userMaximumAffordablePrice = users[i][1];
            for(int j = 0; j < emoticonDiscountedV.size(); j++) {
                if (userMinimumAffordableRate <= emoticonDiscountedV[j].discountRate) {
                    tempPrice += emoticonDiscountedV[j].price;
                }
            }
            
            if (userMaximumAffordablePrice <= tempPrice) {
                plusSubscribePeopleNum += 1;
            } else {
                totalPrice += tempPrice;
            }
        }
        
        if (plusSubscribePeopleNum > maxPeopleNum) {
            maxPeopleNum = plusSubscribePeopleNum;
            maxPrice = totalPrice;
        } else if (plusSubscribePeopleNum == maxPeopleNum) {
            if (maxPrice < totalPrice) {
                maxPrice = totalPrice;
            }
        }
        return;
    }
    
}

vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {
    vector<int> answer;
    
    DFS(0, emoticons.size(), users, emoticons);
    answer.push_back(maxPeopleNum);
    answer.push_back(maxPrice);
    return answer;
}