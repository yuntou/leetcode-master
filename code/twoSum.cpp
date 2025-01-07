#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <unordered_set>
#include <unordered_map>
//#include "twoSum.h"
using namespace std;
//               ��Ŀ
//���������ַ��� s �� t ����дһ���������ж� t �Ƿ��� s ����ĸ��λ�ʡ�
//
//ʾ�� 1: ����: s = "anagram", t = "nagaram" ��� : true
//
//ʾ�� 2 : ���� : s = "rat", t = "car" ��� : false
//
//˵�� : ����Լ����ַ���ֻ����Сд��ĸ��
//              ����˼·
//�ù�ϣ��洢a-zÿ����ĸ��s�г��ֵĴ�����
//��s�У���ĸÿ����һ�Σ��ͶԹ�ϣ���Ӧ��ĸ��key����value+1��
//ͬ��ÿ����ĸ���ַ���t�г���һ�Σ����ϣ���Ӧ��ĸ��value-1.
//������ϣ�������е�value�ǲ���0�������0��������s��t����ĸ��λ�ʡ�
//class Solution_isAnagram {
//public:
//    bool isAnagram(std::string s, std::string t) {
//        int record[26] = { 0 };
//        for (int i = 0; i < s.size(); i++) {
//            // ������Ҫ��ס�ַ�a��ASCII��ֻҪ���һ�������ֵ�Ϳ�����
//            record[s[i] - 'a']++;
//        }
//        for (int i = 0; i < t.size(); i++) {
//            record[t[i] - 'a']--;
//        }
//        for (int i = 0; i < 26; i++) {
//            if (record[i] != 0) {
//                // record��������е�Ԫ�ز�Ϊ��0��˵���ַ���s��t һ����˭�����ַ�����˭�����ַ���
//                return false;
//            }
//        }
//        // record��������Ԫ�ض�Ϊ��0��˵���ַ���s��t����ĸ��λ��
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

//                         ��Ŀ
//�����������飬�������ǵĽ�����
//���룺nums1 = [1,2,2,1], nums2 = [2,2]
//�����[2]
//���룺nums1 = [4,9,5], nums2 = [9,4,9,8,4]
//�����[4,9]
//                   ���ⲽ��
//��Ϊ�����е�Ԫ�������֣��ҿ�Ƚϴ����ʹ�ù�ϣ�������洢��������ɿռ��˷ѣ����Կ���ʹ�ù�ϣ���ϡ�

//https://www.programmercarl.com/0349.%E4%B8%A4%E4%B8%AA%E6%95%B0%E7%BB%84%E7%9A%84%E4%BA%A4%E9%9B%86.html#%E6%80%9D%E8%B7%AF
//class Solution_jiaoji {
//public:
//    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
//        unordered_set<int> result_set; // ��Ž����֮������set��Ϊ�˸������ȥ��
//        unordered_set<int> nums_set(nums1.begin(), nums1.end());
//        for (int num : nums2) {
//            // ����nums2��Ԫ�� ��nums_set���ֳ��ֹ�
//			  //������ڣ��򷵻ص��Ǹ�������vector�е�λ�ã����λ�ÿ϶���endλ�ò�ͬ��
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
		//����һ����ϣ��key�������Ԫ�أ�value��Ԫ�ص��±ꡣ
		std::unordered_map<int, int> map;
		for (int i = 0; i < nums.size(); i++) {
			//������ǰԪ�أ�����map��Ѱ���Ƿ���ƥ���key
			// iter�д洢����ƥ���Ŀ��ֵ
			//��һ��ѭ����16-2=14����map���Ҳ���14.nums[0]=2,0,�����ϣ��
			//�ڶ���ѭ����16-7=9����
			auto iter = map.find(target - nums[i]);//auto�Զ��Ƶ�Ϊ������
			if (iter != map.end()) {
				//���صĽ����ֱ������ѭ��
				//iter->second��ƥ��Ԫ�ص��±꣬i�ǡ�����ֵ��
				return { iter->second,i };
			}
			//���û�ҵ�ƥ�䣬�Ͱѷ��ʹ���Ԫ�غ��±����map�С�
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
	//��forѭ���ж�������ʹ��auto�ؼ��֣�����ʹ�������ࡣ
	for (auto i : result) {
		cout << i << endl;
	}
}