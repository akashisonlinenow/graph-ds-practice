//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int wordLadderLength(string startword, string targetword, vector<string>& wordList) {
        // Code here
        // refer striver
        queue<pair<string,int>> q;
        q.push({startword,1}); // pushimg startword with its step=1
        unordered_set<string> st(wordList.begin(),wordList.end());
        st.erase(startword);
        
        while(!q.empty()){
            string word = q.front().first;
            int steps = q.front().second;
            q.pop();
            
            if(word==targetword){
                return steps;
            }
            
            for(int i=0;i<word.size();i++){
                char original = word[i]; // storing original to replace the word to its original further
                for(char ch='a';ch<='z';ch++){
                    word[i]=ch;
                    // if the word exists in set
                    if(st.find(word)!=st.end()){
                        st.erase(word);
                        q.push({word,steps+1});
                    }
                }
                word[i]=original; // changing the replaced char of word to its original 
            }
        }
        return 0;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<string>wordList(n);
		for(int i = 0; i < n; i++)cin >> wordList[i];
		string startWord, targetWord;
		cin >> startWord >> targetWord;
		Solution obj;
		int ans = obj.wordLadderLength(startWord, targetWord, wordList);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends