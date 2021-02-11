// 面试题 10.05. 稀疏数组搜索
// 稀疏数组搜索。有个排好序的字符串数组，其中散布着一些空字符串，编写一种方法，找出给定字符串的位置。
// 示例1:
//  输入: words = ["at", "", "", "", "ball", "", "", "car", "", "","dad", "", ""], s = "ta"
//  输出：-1
//  说明: 不存在返回-1。
// 示例2:
//  输入：words = ["at", "", "", "", "ball", "", "", "car", "", "","dad", "", ""], s = "ball"
//  输出：4
// 提示:
// words的长度在[1, 1000000]之间
#include<vector>
#include<string>
using namespace std;
int findString(vector<string>& words, string s) {
    int left=0,right=words.size()-1;
    while(left<right){
        while(words[left]=="")left++;
        while(words[right]=="")right--;
        int mid=(right-left)/2+left;
        if(mid>=left&&words[mid]=="")mid--;
        if(words[mid]==s)return s;
        else if(words[mid]>s)right=mid-1;
        else left=mid+1;
    }
    return -1;
}