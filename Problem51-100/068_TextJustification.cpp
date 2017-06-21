class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> res;
        int i, curIdx, curLen, gapLen, gapRest, extra,m;
        string save;
        
        save = "";
        curLen = 0;
        curIdx = gapLen = gapRest = 0;
        
        if(maxWidth <=1)
        {
            return words;
        }
        
        for(i = 0; i<words.size()-1;++i)
        {
            curLen += words[i].size();
            
            if(curLen>=maxWidth || (curLen + words[i+1].size()+i+1-curIdx>maxWidth && i==curIdx))
            {
                extra = curLen<maxWidth?(maxWidth-curLen):0;

                res.push_back(words[curIdx]+string(extra, ' '));
                save = "";
                curIdx = i+1;
                curLen = 0;
            }
            else if(curLen + words[i+1].size()+i+1-curIdx>maxWidth)
            {
                gapLen = (maxWidth-curLen)/(i-curIdx);
                gapRest = (maxWidth-curLen)%(i-curIdx);
            
                for(int j = curIdx; j<curIdx+gapRest;++j)
                {
                    save += words[j]+string(gapLen+1, ' ');
                }
                
                for(int k=curIdx+gapRest; k<i; ++k)
                {
                    save += words[k]+string(gapLen, ' ');
                }

                save += words[i];
                
                res.push_back(save);
                save = "";
                curIdx = i+1;
                curLen = 0;
            }
        }

        curLen = 0;
        for(m = curIdx; m<words.size()-1; ++m)
        {
            save += words[m]+" ";
            curLen += words[m].size()+1;
        }
        
        curLen += words[m].size();
        extra = curLen<maxWidth?(maxWidth-curLen):0;
        save += words[m]+string(extra, ' ');
        res.push_back(save);

        return res;
    }
};