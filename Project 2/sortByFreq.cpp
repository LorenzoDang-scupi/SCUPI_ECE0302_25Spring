#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int N=1000;
vector<int> freq(2001, 0);

bool compareValue(int a, int b){
	int freqA = freq[a+N];
	int freqB = freq[b+N];
	if(freqA == freqB){
		return a >b;
	}
	return freqA < freqB;
}

vector<int>sortByFreq(vector<int> &nums){
	for(int i=0; i<nums.size();i++){
		int num = nums[i];
		freq[num+N]++;
	}
	sort(nums.begin(),nums.end(),compareValue);
	return nums;
}

int main(){
	int n;
	cout << "Enter number of elements: ";
	cin >> n;
		
	vector<int> nums(n);
	cout << "Enter " << n << " integers:\n";
	for (int i = 0; i < n; ++i) {
		cin >> nums[i];
	}
	vector<int> result = sortByFreq(nums);
	for (int i=0; i<result.size(); i++) {
		cout << result[i] << " ";
	}
	return 0;	
}
