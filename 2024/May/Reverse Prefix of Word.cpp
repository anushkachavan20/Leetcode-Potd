// The code defines a class Solution.
// Inside the class, there is a public member function reversePrefix which takes two parameters: a string word and a character ch.
// The function aims to reverse the prefix of the string word up to the first occurrence of the character ch.
// It initializes an integer variable end to store the index of ch.
// It then iterates through the characters of the string word until it finds the first occurrence of ch. Once found, it stores the index and breaks out of the loop.
// Using the reverse function from the C++ Standard Library, it reverses the substring of word from the beginning up to the index of ch (inclusive).
// Finally, it returns the modified string word.

  
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
