struct tnode{
    struct tnode *tc[26];
    int total;
    int rest;
    struct tnode *next;
};

int
char_to_offset(char c)
{
    int ret = -1;
    
    if(c>='A' && c<='Z')
    {
        ret = c -'A' + 0;
    }
    else
    {
        ret = c - 'a' + 0;
    }
    
    return ret;
}

struct tnode *
addNewWord(struct tnode *root, char *word, struct tnode *last)
{
    int idx, isNew, now;
    struct tnode *cur, *newTnode;
    
    
    cur = root;
    isNew = now = 0 ;
    
    while(*word != '\0')
    {
        now ++;
        idx = char_to_offset(*word);
        if(idx>=26 || idx<0 || !cur)
        {
            return NULL;
        }
        
        if(!(cur->tc[idx]))
        {
            newTnode = (struct tnode *)malloc(sizeof(struct tnode));
            newTnode->total = 1;
            newTnode->rest = 1;
            newTnode->next = NULL;
            for(int j=0; j<26;j++)
            {
                newTnode->tc[j] = NULL;
            }
            cur->tc[idx] = newTnode;
            isNew = 1;
        }
        
        cur = cur->tc[idx];
        word ++;
    }
    
    if(!last)
    {
        return cur;
    }
    else if(isNew)
    {
        last->next = cur;
        return cur;
    }
    else
    {
        cur->total ++;
        cur->rest ++;
        return last;
    }
}

struct tnode *
genTrieTree(struct tnode *root, char** words, int wordsSize)
{
    int i;
    struct tnode *ret, *last;

    ret = last = addNewWord(root,words[0], NULL);
    
    for(i = 1; i < wordsSize; ++i)
    {
        last = addNewWord(root,words[i], last);
    }
    
    return ret;
}

bool
searchTnode(struct tnode *root, char *s, int len)
{
    struct tnode *cur;
    int idx;
    
    cur = root;
    while(len>0)
    {
        idx = char_to_offset(*s);
        
        if(idx>=26 || idx<0)
        {
            return false;
        }
        if(!cur->tc[idx])
        {
            return false;
        }
        cur = cur->tc[idx];
        len --;
        s++;
    }
    if(!cur->rest)
    {
        return false;
    }
    else
    {
        cur->rest --;
        return true;
    }
}

void
freeTrieTree(struct tnode *root)
{
    for(int i = 0; i<26; ++i)
    {
        if(root->tc[i])
        {
            freeTrieTree(root->tc[i]);
            root->tc[i] = NULL;
        }
    }
    
    free(root);
    root = NULL;
}

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findSubstring(char* s, char** words, int wordsSize, int* returnSize) {
    struct tnode    *root = NULL,
                    *tList = NULL,
                    *cTnode = NULL;
    int             matchNum = 0,
                    wordLen = 0,
                    idx = 0,
                    totalLen = 0;
    char            *cur = NULL;
    int             *ret = NULL;
    bool            searchRes = false;
    
    wordLen = strlen(words[0]);
    totalLen = wordLen * wordsSize;
    if(strlen(s)<totalLen)
    {
        return NULL;
    }
    ret = (int *)malloc((strlen(s)-wordLen+1)*sizeof(int));
    
    root = (struct tnode *)malloc(sizeof(struct tnode));
    root->total = wordsSize;
    root->rest = wordsSize;
    root->next = NULL;
    for(int i=0; i<26; ++i)
    {
        root->tc[i] = NULL;
    }
    
    tList = genTrieTree(root, words, wordsSize);
    
    matchNum = idx = 0;
    *returnSize = 0;
    
    cur = s;
    while(*(s+totalLen-1))
    {
        if(!searchTnode(root, cur, wordLen))
        {
            if(matchNum>0)
            {
                for(cTnode = tList; cTnode; cTnode = cTnode->next)
                {
                    cTnode->rest = cTnode->total;
                }
                matchNum = 0;
            }
            s++;
            idx++;
            cur = s;
        }
        else
        {
            matchNum++;
            if(matchNum == wordsSize)
            {
                ret[*returnSize] = idx;
                (*returnSize) ++;
                s++;
                idx ++;
                for(cTnode = tList; cTnode; cTnode = cTnode->next)
                {
                    cTnode->rest = cTnode->total;
                }
                cur = s;
                matchNum = 0;
            }
            else
            {
                cur += wordLen;
            }
        }
    }
    
    freeTrieTree(root);
    
    return ret;
}