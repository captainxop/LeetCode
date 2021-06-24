class Solution {
public:
    bool isSumEqual(string firstWord, string secondWord, string targetWord) 
    {
        for(auto &c : firstWord) c -= 'a' - '0';
        for(auto &c : secondWord) c-= 'a' - '0';
        for(auto &c : targetWord) c -= 'a' - '0';
                
        return (stoi(firstWord) + stoi(secondWord) == stoi(targetWord));
    }
};
