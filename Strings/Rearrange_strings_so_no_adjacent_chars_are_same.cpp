struct Element {
    char ch;
    int freq;
    
    bool operator < (const Element &e) const {
        return freq < e.freq;
    }
};

class Solution {
public:
    string reorganizeString(string S) {
        string res;
        int count[26] = {0};
        priority_queue<Element> pq;
        
        for(int i=0;S[i];i++)
            count[S[i]-'a']++;
        
        for(char c='a';c<='z';c++) {
            if(count[c-'a'] > 0) {
                pq.push(Element{c , count[c-'a']});
            }
        }
        
        Element prev{'#',-1};
        
        while(!pq.empty()) {
            Element k = pq.top();
            pq.pop();
            
            // cout<<k.ch<<" "<<k.freq<<endl;
       
            res.push_back(k.ch);
            
            if(prev.freq > 0)
                pq.push(prev);
            
            k.freq--;
            prev = k;
        }
        
        if(res.size() == S.size())
            return res;
        return "";
    }
};