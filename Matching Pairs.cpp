#include <bits/stdc++.h>
// Add any extra import statements you may need here

using namespace std;

// Add any helper functions you may need here

//abcde
//abdex

//abdce, //abced => 3

//ab
//ab

//ba ab =>0

//abc
//abc  => 1
/*
Matching Pairs
Given two strings s and t of length N, find the maximum number of possible matching pairs in strings s and t after swapping exactly two characters within s.
A swap is switching s[i] and s[j], where s[i] and s[j] denotes the character that is present at the ith and jth index of s, respectively. The matching pairs of the two strings are defined as the number of indices for which s[i] and t[i] are equal.
Note: This means you must swap two characters at different indices.
Signature
int matchingPairs(String s, String t)
Input

    s and t are strings of length N
    N is between 2 and 1,000,000

Output
Return an integer denoting the maximum number of matching pairs
Example 1
s = "abcd"
t = "adcb"
output = 4
Explanation:
Using 0-based indexing, and with i = 1 and j = 3, s[1] and s[3] can be swapped, making it  "adcb".
Therefore, the number of matching pairs of s and t will be 4.
Example 2
s = "mno"
t = "mno"
output = 1
Explanation:
Two indices have to be swapped, regardless of which two it is, only one letter will remain the same. If i = 0 and j=1, s[0] and s[1] are swapped, making s = "nmo", which shares only "o" with t.

94

    cout << rightTick << "Test #" << test_case_number << "\n";

95

  }

96

  else {

97

    cout << wrongTick << "Test #" << test_case_number << ": Expected ";

98

    printInteger(expected); 

99

    cout << " Your output: ";

100

    printInteger(output);

101

    cout << endl; 

102

  }

103

  test_case_number++;

104

}

105

​

106

int main() {

107

  string s_1 = "abcde";

108

  string t_1 = "adcbe";

109

  int expected_1 = 5;

110

  int output_1 = matchingPairs(s_1, t_1);

111

  check(expected_1, output_1);

112

​

113

  string s_2 = "abcd";

114

  string t_2 = "abcd";

115

  int expected_2 = 2;

116

  int output_2 = matchingPairs(s_2, t_2);

117

  check(expected_2, output_2);

118

​

119

  string s_3 = "abcdef";

120

  string t_3 = "abcffd";

121

  int expected_3 = 5;

122

  int output_3 = matchingPairs(s_3, t_3);

123

  check(expected_3, output_3);

124

  // Add your own test cases here

125

  

126

}

CONSOLE

​

​

✓Test #1

✓Test #2

✓Test #3

​

​


  */

int matchingPairs(string s, string t) {
  // Write your code here
  unordered_map<char,vector<int>> indexStore;
  int match_count = 0,umatch_count=0;
  for (int i=0;i<s.length();i++){
    if(s[i]==t[i]){
      match_count++;
    }else{
      umatch_count++;
      indexStore[s[i]].push_back(i);
    }
  }
  
  if(umatch_count==0){
    return match_count-2;
  }else if (umatch_count==1){
    auto it=indexStore.begin();
    int idx =it->second[0];
    char a = t[idx];
    bool match = false;
    for(int i=0;i<s.length();i++){
      if(i=idx)continue;
      if(t[idx]==t[i])match=true;
    }
    if(match)return match_count;
    else return match_count -1;
  }
  int mini = 0;
  for(auto it=indexStore.begin() ;it!=indexStore.end(); it++){
    for(int i=0;i<it->second.size();i++){
      auto it2= indexStore.find(t[it->second[i]]);
      if(it2 != indexStore.end()){
        for(int j=0;j<it2->second.size();j++){
          if(t[it2->second[j]]==it->first){
            mini = max(mini,2);
            return match_count +2;
          }else{
            mini = max(mini,1);
          }
        }
      }
    }
  }
  
  return match_count +mini;
}












// These are the tests we use to determine if the solution is correct.
// You can add your own at the bottom.

void printInteger(int n) {
  cout << "[" << n << "]";
}

int test_case_number = 1;

void check(int expected, int output) {
  bool result = (expected == output);
  const char* rightTick = u8"\u2713";
  const char* wrongTick = u8"\u2717";
  if (result) {
    cout << rightTick << "Test #" << test_case_number << "\n";
  }
  else {
    cout << wrongTick << "Test #" << test_case_number << ": Expected ";
    printInteger(expected); 
    cout << " Your output: ";
    printInteger(output);
    cout << endl; 
  }
  test_case_number++;
}

int main() {
  string s_1 = "abcde";
  string t_1 = "adcbe";
  int expected_1 = 5;
  int output_1 = matchingPairs(s_1, t_1);
  check(expected_1, output_1);

  string s_2 = "abcd";
  string t_2 = "abcd";
  int expected_2 = 2;
  int output_2 = matchingPairs(s_2, t_2);
  check(expected_2, output_2);

  string s_3 = "abcdef";
  string t_3 = "abcffd";
  int expected_3 = 5;
  int output_3 = matchingPairs(s_3, t_3);
  check(expected_3, output_3);
  // Add your own test cases here
  
}
