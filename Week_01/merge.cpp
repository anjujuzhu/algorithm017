//直接合并排序（不推荐）
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        copy(nums2.begin(),nums2.end(),nums1.begin()+m);
        sort(nums1.begin(), nums1.end());
    }
};
//双指针
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> nums3;
        nums3.assign(nums1.begin(), nums1.begin() + m);
        int i = 0, j = 0, k = 0;
        while ( i < n || j < m ) {
            if (i < n && j < m && nums2[i] <= nums3[j]) {
                copy(nums2.begin() + i, nums2.begin() + i + 1, nums1.begin()+k);
                i++;
            } else if (i < n && j < m && nums2[i] > nums3[j]) {
                copy(nums3.begin() + j, nums3.begin() + j + 1, nums1.begin()+k);
                j++;
            } else if (i < n) {
                copy(nums2.begin() + i, nums2.begin() + i + 1, nums1.begin()+k);
                i++;
            } else if (j < m) {
                copy(nums3.begin() + j, nums3.begin() + j + 1, nums1.begin()+k);
                j++;
            }
            ++k;
        }
    }
};
//双指针，不开辟新数组
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int k = m + n - 1;
        --m;
        --n;
        while ( n >= 0 ) {
            if (m >= 0 && nums1[m] > nums2[n]) {
                copy(nums1.begin() + m, nums1.begin() + m + 1, nums1.begin()+k);
                --m;
            } else {
                copy(nums2.begin() + n, nums2.begin() + n + 1, nums1.begin()+k);
                --n;
            }
            --k;
        }
    }
};