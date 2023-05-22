#include <string>
#include <vector>
#include <set>
#include <unordered_map>
#include <sstream>

using namespace std;
// 중복 제거를 위해 `unordered_set`대신 `set`를 사용하면서 알파벳 순서 자동정렬
// 문자열에서 `reporter`과 `reported` 추출할때 `istringstream` 사용해서 코드 가독성 향상
vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    unordered_map<string, set<string>> reporters;
    unordered_map<string, int> reported_count;
    vector<int> answer(id_list.size(), 0);
    // 신고 내역을 순회하며 신고자와 신고당한 사용자들의 관계 기록
    for (const auto& r : report) {
        istringstream iss(r);
        string reporter, reported;
        // 입력 문자열 'r'을 공백 기준으로 나눠서 reporter과 reported 변수에 각각 저
        iss >> reporter >> reported;
        reporters[reporter].insert(reported);
    }
    // reporters 맵을 순회하면서 각 사용자가 신고 당한 횟수 추가
    for (const auto& rep : reporters) {
        for (const auto& r : rep.second) {
            reported_count[r]++;
        }
    }
    // id_list를 돌면서 신고 당한 횟수가 k 이상인 경우 카운트
    for (int i = 0; i < id_list.size(); i++) {
        for (const auto& r : reporters[id_list[i]]) {
            if (reported_count[r] >= k) {
                answer[i]++;
            }
        }
    }

    return answer;
}

