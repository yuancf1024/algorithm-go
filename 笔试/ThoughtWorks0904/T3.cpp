#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);



/*
 * Complete the 'even_and_odds' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts INTEGER_ARRAY numbers as parameter.
 */
/*
去奇留偶并排序
*/

vector<int> even_and_odds(vector<int> numbers) {
    int n = numbers.size();
    vector<int> nums;
    int zeros = 0;
    // 去奇
    for (int i = 0; i < n; ++i) {
        if (numbers[i] % 2  == 0 && numbers[i] != 0) {
            nums.push_back(numbers[i]);
        }
        if (numbers[i] == 0) {
            zeros++;
        }
    }
    sort(nums.begin(), nums.end());
    
    for (int i = 0; i < zeros; ++i) {
        nums.push_back(0);
    }
    
    return nums;
    
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string numbers_count_temp;
    getline(cin, numbers_count_temp);

    int numbers_count = stoi(ltrim(rtrim(numbers_count_temp)));

    vector<int> numbers(numbers_count);

    for (int i = 0; i < numbers_count; i++) {
        string numbers_item_temp;
        getline(cin, numbers_item_temp);

        int numbers_item = stoi(ltrim(rtrim(numbers_item_temp)));

        numbers[i] = numbers_item;
    }

    vector<int> result = even_and_odds(numbers);

    for (size_t i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

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
