// The string_split function splits a string by a specified delimiter and returns a vector containing the substrings.
// The compareVersion function compares two version strings. It first splits each version string into its components (major, minor, patch) using the string_split function.
// It then converts these components into integers and compares them element-wise.
// If one version string has fewer components than the other, it pads it with zeros.
// It then iterates through the components of the shorter version string and compares them with the corresponding components of the longer version string.
// If all corresponding components are equal, it checks if there are additional non-zero components in the longer version string.
// Finally, it returns 0 if the versions are equal, 1 if the first version is greater, and -1 if the second version is greater.






class Solution {
public:
    std::vector<std::string> string_split(std::string str, std::string delimiter){
        size_t pos = 0;
        std::string token;
        std::vector<std::string> result;
        
        while(true){
            pos = str.find(delimiter);
            //works even if pos is string::npos
            token = str.substr(0, pos);
            result.push_back(token);
            if(pos == string::npos) break;
            //pos+1 equals to 0, so the line below can't handle this situation
            str.erase(0, pos+delimiter.length());
        }
        return result;
    };

    int compareVersion(string version1, string version2) {
        vector<string> vsv1 = string_split(version1, ".");
        vector<string> vsv2 = string_split(version2, ".");

        vector<int> viv1, viv2;
        transform(vsv1.begin(), vsv1.end(), back_inserter(viv1), [](string& s){return stoi(s);});
        transform(vsv2.begin(), vsv2.end(), back_inserter(viv2), [](string& s){return stoi(s);});

        int swapped = 1;
        if(viv1.size() < viv2.size()) {
            swapped = -1;
            swap(viv1, viv2);
        }
        
        int i;

        for(i = 0; i < viv2.size() && viv1[i] == viv2[i]; ++i){}

        if(i == viv2.size()){
            for(i =  viv2.size(); i < viv1.size() && viv1[i] == 0; ++i){}
            return (i == viv1.size()) ? 0 : (viv1[i] > 0) ? 1*swapped : -1*swapped;
        }else{
            return (viv1[i] > viv2[i]) ? 1*swapped : -1*swapped;
        }
        
    }
};
