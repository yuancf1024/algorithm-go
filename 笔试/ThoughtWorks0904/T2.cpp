#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);



/*
 * Complete the 'countVotes' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts following parameters:
 *  1. STRING_ARRAY validCandidates
 *  2. STRING_ARRAY voteCasted
 */

/*
设计一个投票器
返回投票结果要按照字典序，只能用哈希表

2022-09-04 
这一题本来可以做对的，
没有注意到最终输出是按照哈希表的字典序整理的
所以其他方面都是对的，只是候选人的投票结果顺序不对
😂

*/

string countVotes(vector<string> validCandidates, vector<string> voteCasted) {
    string res;
    int n = voteCasted.size();
    int m = validCandidates.size();
    // 统计候选人票数的数组
    vector<int> nums(m, 0);
    int numsInvalid = 0;
    int maxN = 0;
    
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if(voteCasted[j] == validCandidates[i]) {
                nums[i]++;
                maxN = max(maxN, nums[i]);
            }
        }
    }
    // int max = *max_element(nums.begin(),nums.end());
    string winner;
    int invalid=0;
    for (int i = 0; i < m; ++i) {
        if (nums[i] == maxN) {
            winner = validCandidates[i];
            break;
        }
    }
    
    // 专门统计无效字符数量
    set<string> set;
    for (auto& i : validCandidates) {
        set.insert(i);
    }
    for (auto& a : voteCasted) {
        if (!set.count(a)) {
            invalid++;
        }
    }
    
    string invalidVotes = "invalidVotes";
    string Winner = "Winner";
    

    // 输出结果
    for (int i = 0; i < m; ++i) {
        string temp = validCandidates[i] + "=" + to_string(nums[i]);
        res += temp + " ";
    }
    
    if (n == 0) {
        Winner += "=N/A";
        invalidVotes += "=0";
        return res + " " + Winner + " " + invalidVotes;
    }
    
    res += invalidVotes + "=" + to_string(invalid) + " ";
    res += Winner + "=" + winner;
    return res;
    
    
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string validCandidates_count_temp;
    getline(cin, validCandidates_count_temp);

    int validCandidates_count = stoi(ltrim(rtrim(validCandidates_count_temp)));

    vector<string> validCandidates(validCandidates_count);

    for (int i = 0; i < validCandidates_count; i++) {
        string validCandidates_item;
        getline(cin, validCandidates_item);

        validCandidates[i] = validCandidates_item;
    }

    string voteCasted_count_temp;
    getline(cin, voteCasted_count_temp);

    int voteCasted_count = stoi(ltrim(rtrim(voteCasted_count_temp)));

    vector<string> voteCasted(voteCasted_count);

    for (int i = 0; i < voteCasted_count; i++) {
        string voteCasted_item;
        getline(cin, voteCasted_item);

        voteCasted[i] = voteCasted_item;
    }

    string result = countVotes(validCandidates, voteCasted);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
