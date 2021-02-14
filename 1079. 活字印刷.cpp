// 1079. 活字印刷
// 你有一套活字字模 tiles，其中每个字模上都刻有一个字母 tiles[i]。返回你可以印出的非空字母序列的数目。
// 注意：本题中，每个活字字模只能使用一次。
// 示例 1：
// 输入："AAB"
// 输出：8
// 解释：可能的序列为 "A", "B", "AA", "AB", "BA", "AAB", "ABA", "BAA"。
// 示例 2：
// 输入："AAABBC"
// 输出：188
// 提示：
// 1 <= tiles.length <= 7
// tiles 由大写英文字母组成
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
int res=0;
int numTilePossibilities(string& tiles){
    string track;
    vector<bool> visited(tiles.size(),false);
    sort(tiles.begin(),tiles.end());
    back_track(tiles,track,visited,0);
    return res;
}
void back_track(string&tiles,string&track,vector<bool>&visited,int start){
    int n=tiles.size();
    if(start>n)return ;
    for(int i=0;i<n;i++){
        if(visited[i])continue;
        if(i>0&&tiles[i]==tiles[i-1]&&visited[i]==false)continue;
        res++;
        visited[i]=true;
        track+=tiles[i];
        back_track(tiles,track,visited,i);
        visited[i]=false;
        track.pop_back();
    }
}