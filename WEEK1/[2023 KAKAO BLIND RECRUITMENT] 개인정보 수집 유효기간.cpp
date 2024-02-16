// [2023 KAKAO BLIND RECRUITMENT] 개인정보 수집 유효기간
// https://school.programmers.co.kr/learn/courses/30/lessons/150370

#include <string>
#include <vector>
#include <map>

using namespace std;

struct Date {
    int year;
    int month;
    int day;
};

Date getDateFromString(string day) {
    Date date;
    date.year = stoi(day.substr(0,4));
    date.month = stoi(day.substr(5, 2));
    date.day = stoi(day.substr(8, 2));
    
    return date;
}

map<char, int> getRetentionPeriod(vector<string> terms) {
    map<char, int> retentionPeriodMap;
    int len = 0;    
    for(int i = 0;  i < terms.size(); i++) {
        len = stoi(terms[i].substr(2, terms[i].size() - 2));
        retentionPeriodMap[terms[i][0]] = len;
    }
    
    return retentionPeriodMap;
}

bool isMonthExceed12(int month) {
    return month > 12;
}

bool isResultExceedDefault(int defaultVal, int resultVal) {
    return defaultVal < resultVal;
}

bool isResultSameAsDefault(int defaultVal, int resultVal) {
    return defaultVal == resultVal;
}

bool shouldDelete(Date date, Date current, int len) {

    // 100달 -> 8년 4개월
    Date delta;
    delta.year = len / 12;
    delta.month = len % 12;
    delta.day = 0;
    
    Date finalResult = date;
    
    int calculatedMonth = date.month + delta.month;
    if (isMonthExceed12(calculatedMonth)) {
        delta.year += calculatedMonth / 12;
        finalResult.month = calculatedMonth - 12;
    } else {
        finalResult.month = calculatedMonth;
    }
    finalResult.year += delta.year;
    
    if (isResultExceedDefault(current.year, finalResult.year)) {
        return false;
    }
    else if (isResultSameAsDefault(current.year, finalResult.year)) {
        if (isResultExceedDefault(current.month, finalResult.month)) {
            return false;
        } else if (isResultSameAsDefault(current.month, finalResult.month)) {
            if (isResultExceedDefault(current.day, finalResult.day)) {
                return false;
            } else {
                return true;
            }
        } else {
            return true;
        }
    } else {
        return true;
    }
}

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;
    
    // 1. 현재 기준 시점 찾기
    Date current = getDateFromString(today);
    
    // 2. terms 변환하기
    map<char, int> retentionPeriodMap = getRetentionPeriod(terms);
    
    // 3. Input 데이터 정제 및 비교
    for(int i = 0; i < privacies.size(); i++) {
        Date inputDate = getDateFromString(privacies[i]);
        
        char term = privacies[i][11];
        if (shouldDelete(inputDate, current, retentionPeriodMap[term])) {
            answer.push_back(i + 1);
        }
    }
    return answer;
}