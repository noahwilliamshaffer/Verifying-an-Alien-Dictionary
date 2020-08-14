
//bool function takes in a vector of strings( words ) and a string order which represents the order of the alphabet in the alien language
bool isAlienSorted(vector<string> &words, string order) {

        //size_t is used to represent the size of any object in bytes, most commonly used to represent sizes and counts
        //indices of size 26 used to represent the number of different letters in the alphabet
        size_t indices[26]{};
        
        //we loop through the alphebet 
        for (size_t i = 0; i < order.size(); ++i) {
        //for all the alphebet in the alien laguage we subtract a to convert it to 
            indices[order[i] - 'a'] = i;
        }
        
        //pass in the beggining and end of the vector string and the new indices as a reference 
        return is_sorted(words.begin(), words.end(), [&indices](
                const string &w1,
                const string &w2
        ) {
            auto l1 = w1.size(), l2 = w2.size();
            for (auto i = 0; i < min(l1, l2); ++i) {
                auto c1 = w1[i], c2 = w2[i];
                if (c1 != c2) {
                    return indices[c1 - 'a'] < indices[c2 - 'a'];
                }
            }
            return l1 < l2;
        });
    }
