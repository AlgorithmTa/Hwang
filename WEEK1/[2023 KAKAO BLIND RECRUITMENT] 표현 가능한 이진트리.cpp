// [2023 KAKAO BLIND RECRUITMENT] 표현 가능한 이진트리
// https://school.programmers.co.kr/learn/courses/30/lessons/150367#

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string decimalToBinary(long long number) {
    string result = "";
    long long temp = number;
    while(temp != 0) {
        result += (temp % 2) + '0';
        temp = temp / 2;
    }
    return result;
}

string makeFullBinaryTree(string number) {
    int val = 2;
    int numberLen = number.size();
    
    while(true) {
        if (numberLen > val - 1) {
            val *= 2;
        } else {
            break;
        }
    }
    
    int remain = val - 1 - numberLen;
    for(int i =0; i < remain; i++) {
        number += "0";
    }

    reverse(number.begin(), number.end());
    return number;
}

bool isAllZero(string number) {
    for(int i = 0; i < number.size(); i++) {
        if (number[i] != '0') {
            return false;
        }
    }
    return true;
}

bool canMake(string number) {
    if (number.size() == 1 || isAllZero(number)) {
        return true;
    }
    
    int len = number.size();
    int mid = len / 2;
    string left = number.substr(0, mid);
    string right = number.substr(mid + 1);
    
    if (number[mid] == '1' && canMake(left) && canMake(right)) {
        return true;
    } else {
        return false;
    }
}

vector<int> solution(vector<long long> numbers) {
    vector<int> answer;
    string number = "";
    for(int i = 0; i < numbers.size(); i++) {
        number = decimalToBinary(numbers[i]);
        number = makeFullBinaryTree(number);
        int result = canMake(number);
        answer.push_back(result);
    }
    return answer;
}