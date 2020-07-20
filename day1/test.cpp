#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	bool Find(int target, vector<vector<int> > array) {
		int i = 0;
		int j = array[0].size() - 1;

		while (i < array.size() && j >= 0) {
			if (target < array[i][j]) {
				j--;
			}
			else if (target > array[i][j]) {
				i++;
			}
			else
				return true;
		}
		return false;
	}
};


class Solution {
public:
	int minNumberInRotateArray(vector<int> rotateArray) {
		if (rotateArray.size() == 0) {
			return 0;
		}
		int left = 0;
		int right = rotateArray.size() - 1;
		int mid = 0;
		while (rotateArray[left] >= rotateArray[right]) {
			if (right - left == 1) {
				mid = right;
				break;
			}
			mid = left + ((right - left) >> 1);
			if (rotateArray[left] == rotateArray[mid] && rotateArray[mid] == rotateArray[right]) {
				int result = rotateArray[left];
				for (int i = left + 1; i < right; i++) {
					if (rotateArray[i] < result) {
						result = rotateArray[i];
					}
				}
				return result;
			}
			if (rotateArray[left] <= rotateArray[mid]) {
				left = mid;
			}
			else {
				right = mid;
			}
		}
		return rotateArray[mid];
	}
};

class Solution {
public:
	void reOrderArray(vector<int> &array) {
		int k = 0;
		for (int i = 0; i < array.size(); i++) {
			if (array[i] & 1) { //����
				int tmp = array[i];
				int j = i;
				//������Ԫ��
				while (j > k) {
					array[j] = array[j - 1];
					j--;
				}
				//��������
				array[k++] = tmp;
			}
		}
	}
};