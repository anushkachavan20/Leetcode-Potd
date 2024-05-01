
  
class Solution {
public:
    // Function to reverse the prefix of a string up to the first occurrence of a specified character.
    string reversePrefix(string word, char ch) {
        
        // Variable to store the index of the character 'ch' in the string.
        int end=0;
        
        // Loop through the characters of the string.
        for(int i=0;i<word.size();i++){
            // If the current character is equal to the specified character 'ch', store its index and exit the loop.
            if(word[i]==ch){
                end=i;
                break;
            }
        }
        
        // Reverse the substring from the beginning of the string up to the index of 'ch' (inclusive).
        reverse(word.begin(),word.begin()+end+1);
        
        // Return the modified string.
        return word;
    }
};
