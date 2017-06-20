class trie{
public:
   trie *child[26];
   trie *next;
   bool isWord;
   int  num;
   int  cover;
   
   trie(bool b){
       for(int i = 0; i<26; ++i)
       {
           child[i] = NULL;
       }
       
       isWord = b;
       num = 0;
       next = NULL;
       cover = 0;
   }
   
   ~trie(){
       for(int i = 0; i<26; ++i)
       {
           delete child[i];
           child[i] = NULL;
       }
   }
};

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> res;
        
        pair<trie *, trie *> rf = buildTrieTree(words);
        int len = words[0].size();
        
        for(int i = 0; i+len<=s.size(); ++i)
        {
            int j = i;
            while(j<s.size())
            {
                if(!hasWord(rf.first, s.substr(j, len)))
                {
                    break;
                }
                j += len;
                if(allCover(rf.second))
                {
                    res.push_back(i);
                    break;
                }
            }
            
            resetTrie(rf.second);
        }
        
        return res;
    }
    
    pair<trie *, trie *> buildTrieTree(vector<string>& words)
    {
        trie *root  = new trie(false);
        trie *first = NULL,
             *last = NULL;
        
        for(auto word : words)
        {
            trie *cur = root;
            for(int i = 0; i<word.size(); ++i)
            {
                if(cur->child[word[i]-'a'] == NULL)
                {
                    cur->child[word[i]-'a'] = new trie(false);
                }
                
                cur = cur->child[word[i]-'a'];
            }
            
            ++cur->num;
            cur->isWord = true;
            
            if(!last)
            {
                last = cur;
                first = cur;
            }
            else if(cur->num == 1)
            {
                last->next = cur;
                last = cur;
            }
        }
        
        return make_pair(root, first);
    }
    
    bool allCover(trie *first)
    {
        trie *cur = first;
        while(cur)
        {
            if(cur->cover != cur->num)
            {
                return false;
            }
            cur = cur->next;
        }
        
        return true;
    }
    
    bool hasWord(trie *root, string word)
    {
        trie *cur = root;
        for(int i = 0; i<word.size(); ++i)
        {
            if(cur->child[word[i]-'a'] == NULL)
            {
                return false;
            }
            
            cur = cur->child[word[i]-'a'];
        }
        
        ++cur->cover;
        if(cur->cover>cur->num)
        {
            return false;
        }
        else
        {
            return true;
        }
    }
    
    void resetTrie(trie *first)
    {
        trie *cur = first;
        while(cur)
        {
            cur->cover = 0;
            cur = cur->next;
        }
    }
};