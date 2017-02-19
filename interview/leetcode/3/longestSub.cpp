#include <iostream>
#include <string>
#include <vector>

int lengthOfLongestSubstring(std::string s) {
    int len = 0;
    for (int i = 0; i < s.length(); i++) {
        int tmpLen = 0;
        bool arr[256] = {false};
        for (int j = i; j < s.length(); j++) {
            int v = (int)s[j];
            if (arr[v]) break;
            arr[v] = true;
            tmpLen++;
        }
        len = std::max(len, tmpLen);
    }
    
    return len;
}

int lengthOfLongestSubstring2(std::string s) {
    // 32ms
    std::vector<int> v(256, -1);
    int maxLen = 0, start = -1;
    for (int i = 0; i < s.length(); i++) {
        if (v[s[i]] > start)
            start = v[s[i]];
        v[s[i]] = i;
        maxLen = std::max(maxLen, i - start);
    }
    return maxLen;
}

int main()
{
    std::string s1 = "hello, world";
    std::string s2 = "abcdefghijklmnopqrstuvwxyzABCD1234567890";

    std::cout << lengthOfLongestSubstring(s1) << std::endl;
    std::cout << lengthOfLongestSubstring(s2) << std::endl;

    std::cout << lengthOfLongestSubstring2(s1) << std::endl;
    std::cout << lengthOfLongestSubstring2(s2) << std::endl;
	return 0;
}
