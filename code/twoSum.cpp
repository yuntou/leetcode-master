#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <unordered_set>
#include <unordered_map>
//#include "twoSum.h"
using namespace std;
//               题目
//给定两个字符串 s 和 t ，编写一个函数来判断 t 是否是 s 的字母异位词。
//
//示例 1: 输入: s = "anagram", t = "nagaram" 输出 : true
//
//示例 2 : 输入 : s = "rat", t = "car" 输出 : false
//
//说明 : 你可以假设字符串只包含小写字母。
//              解题思路
//用哈希表存储a-z每个字母在s中出现的次数。
//在s中，字母每出现一次，就对哈希表对应字母（key）的value+1。
//同理，每个字母在字符串t中出现一次，则哈希表对应字母的value-1.
//最后检查哈希表中所有的value是不是0，如果是0，则两个s和t是字母异位词。
//class Solution_isAnagram {
//public:
//    bool isAnagram(std::string s, std::string t) {
//        int record[26] = { 0 };
//        for (int i = 0; i < s.size(); i++) {
//            // 并不需要记住字符a的ASCII，只要求出一个相对数值就可以了
//            record[s[i] - 'a']++;
//        }
//        for (int i = 0; i < t.size(); i++) {
//            record[t[i] - 'a']--;
//        }
//        for (int i = 0; i < 26; i++) {
//            if (record[i] != 0) {
//                // record数组如果有的元素不为零0，说明字符串s和t 一定是谁多了字符或者谁少了字符。
//                return false;
//            }
//        }
//        // record数组所有元素都为零0，说明字符串s和t是字母异位词
//        return true;
//    }
//};

//int main() {
//    Solution_isAnagram ana;
//    string a = "anagramvvv", b = "nagaram";
//    bool result;
//    result = ana.isAnagram(a,b);
//    if (result == 1) {
//        cout << "a and b is same" << endl;
//    }
//    else {
//        cout << "a and b is not same" << endl;
//
//    };
//    return 0;
//}

//                         题目
//给定两个数组，计算他们的交集。
//输入：nums1 = [1,2,2,1], nums2 = [2,2]
//输出：[2]
//输入：nums1 = [4,9,5], nums2 = [9,4,9,8,4]
//输出：[4,9]
//                   解题步骤
//因为数组中的元素是数字，且跨度较大，如果使用哈希数组来存储，可能造成空间浪费，所以考虑使用哈希集合。

//https://www.programmercarl.com/0349.%E4%B8%A4%E4%B8%AA%E6%95%B0%E7%BB%84%E7%9A%84%E4%BA%A4%E9%9B%86.html#%E6%80%9D%E8%B7%AF
//class Solution_jiaoji {
//public:
//    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
//        unordered_set<int> result_set; // 存放结果，之所以用set是为了给结果集去重
//        unordered_set<int> nums_set(nums1.begin(), nums1.end());
//        for (int num : nums2) {
//            // 发现nums2的元素 在nums_set里又出现过
//			  //如果存在，则返回的是该数字在vector中的位置，这个位置肯定与end位置不同。
//            if (nums_set.find(num) != nums_set.end()) {
//                result_set.insert(num);
//            }
//        }
//        return vector<int>(result_set.begin(), result_set.end());
//    }
//};
//
//int main() {
//    Solution_jiaoji jiaoji;
//    vector<int> nums1 = { 4,9,5 }, nums2 = { 9,4,9,8,4 };
//    vector<int> result;
//    result = jiaoji.intersection(nums1, nums2);
//    for (int i = 0; i < result.size(); ++i) {
//        std::cout << result[i] << " ";
//    }
//    return 0;
//}

class Solution_twoSum {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		//定义一个哈希表，key是数组的元素，value是元素的下标。
		std::unordered_map<int, int> map;
		for (int i = 0; i < nums.size(); i++) {
			//遍历当前元素，并在map中寻找是否有匹配的key
			// iter中存储的是匹配的目标值
			//第一次循环，16-2=14，在map中找不到14.nums[0]=2,0,放入哈希表。
			//第二次循环，16-7=9，在
			auto iter = map.find(target - nums[i]);//auto自动推导为迭代器
			if (iter != map.end()) {
				//返回的结果，直接跳出循环
				//iter->second是匹配元素的下标，i是。返回值是
				return { iter->second,i };
			}
			//如果没找到匹配，就把访问过的元素和下标放入map中。
			map.insert(pair<int, int>(nums[i], i));
		}
	}
};

int main() {
	Solution_twoSum twoSum;
	vector<int> nums = { 2, 7, 9, 15 };
	int target = 16;
	vector<int> result;
	result = twoSum.twoSum(nums, target);
	for (int i = 0; i < result.size(); i++) {
		std::cout << result[i] << " ";

	}
	cout << endl << "---------" << endl;
	//在for循环判断条件中使用auto关键字，可以使代码更简洁。
	for (auto i : result) {
		cout << i << endl;
	}
}