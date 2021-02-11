// 面试题 17.13. 恢复空格
// 哦，不！你不小心把一个长篇文章中的空格、标点都删掉了，并且大写也弄成了小写。像句子"I reset the computer. It still didn’t boot!"已经变成了"iresetthecomputeritstilldidntboot"。在处理标点符号和大小写之前，你得先把它断成词语。当然了，你有一本厚厚的词典dictionary，不过，有些词没在词典里。假设文章用sentence表示，设计一个算法，把文章断开，要求未识别的字符最少，返回未识别的字符数。
// 注意：本题相对原题稍作改动，只需返回未识别的字符数
// 示例：
// 输入：
// dictionary = ["looked","just","like","her","brother"]
// sentence = "jesslookedjustliketimherbrother"
// 输出： 7
// 解释： 断句后为"jess looked just like tim her brother"，共7个未识别字符。
// 提示：
// 0 <= len(sentence) <= 1000
// dictionary中总字符数不超过 150000。
// 你可以认为dictionary和sentence中只包含小写字母。
class Trie{
    public:
    Trie* next[26]={nullptr};
    bool isend=false;
    Trie(){
        isend=false;
    }
    void insert(string &s){
        Trie* currp=this;
        int n=s.size();
        for(int i=n-1;i>=0;i--){
            int t=s[i]-'a';
            if(currp->next[t]==nullptr)currp->next[t]=new Trie();
            currp=currp->next[t];
        }
        currp->isend=true;
    }
};

int respace(vector<string>& dictionary, string sentence) {
    int n =sentence.size();
    int inf=0x3f3f3f3f;
    int dlen=dictionary.size();
    Trie* root=new Trie();
    if(n==0)return 0;
    if(dlen==0)return n;
    vector<int> dp(n+1,inf);
    dp[0]=0;
    for(int i = 0;i<dlen;i++)
    root->insert(dictionary[i]);
    //Trie* curr=nullptr;
    int t=0;
    for(int i=1;i<n+1;i++){
        dp[i]=dp[i-1]+1;
        Trie* curr=root;
        for(int j=i;j>=1;j--)
        {
            t=sentence[j-1]-'a';
            if(curr->next[t]==nullptr)break;
            else if(curr->next[t]->isend)
            dp[i]=min(dp[i],dp[j-1]);
            if(dp[i]==0)break;
            curr=curr->next[t];
        }

    }
    return dp[n];
}