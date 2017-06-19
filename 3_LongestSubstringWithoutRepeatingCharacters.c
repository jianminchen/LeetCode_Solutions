struct heapMem{
    char val;  
    struct heapMem *next;
};

struct heapHeader{
    struct heapMem *firstMem;
    struct heapMem *lastMem;
    int num;
};

void deleteHeap(struct heapHeader *);
void addHeap(struct heapHeader *, char);

int lengthOfLongestSubstring(char* s) {
    int  curMax, found, i, deleteNum, j;
    struct heapHeader *strHeap;
    struct heapMem *curMem;
    
    strHeap = (struct heapHeader *)malloc(sizeof(struct heapHeader));
    strHeap->firstMem = NULL;
    strHeap->lastMem = NULL;
    strHeap->num = 0;
    curMax = deleteNum = 0;
    found = 0;
    
    for(i = 0; s[i] != '\0'; ++i)
    {
        for(curMem = strHeap->firstMem; curMem; curMem = curMem->next)
        {
            deleteNum ++;
            if(curMem->val == s[i])
            {
                found = 1;
                break;
            }
        }
        
        if(found)
        {
            for(j = 0; j< deleteNum; j++)
            {
                deleteHeap(strHeap);
            }
            found = 0;
            addHeap(strHeap, s[i]);
        }
        else
        {
            addHeap(strHeap, s[i]);
            curMax = strHeap->num>curMax? strHeap->num : curMax;
        }
        
        deleteNum = 0;
    }

    while(strHeap->firstMem)
    {
        deleteHeap(strHeap);
    }

    free(strHeap);    
    return curMax;
}

void
deleteHeap(struct heapHeader *strHeap)
{
    struct heapMem *oldFirst;
    
    if(strHeap->num == 1)
    {
        strHeap->lastMem = NULL;
    }
    
    oldFirst = strHeap->firstMem;
    
    strHeap->firstMem = oldFirst->next;
    strHeap->num --;
    free(oldFirst);
}

void
addHeap(struct heapHeader *strHeap, char val)
{
    struct heapMem *newMem;
    
    newMem = (struct heapMem *)malloc(sizeof(struct heapMem));
    newMem->next = NULL;
    newMem->val = val;
    
    if(!strHeap->num)
    {
        strHeap->firstMem = newMem;
        strHeap->lastMem = newMem;
    }
    else
    {
        strHeap->lastMem->next = newMem;
        strHeap->lastMem = newMem;
    }
    strHeap->num ++;
}