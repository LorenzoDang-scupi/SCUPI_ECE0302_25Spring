#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int N=1000;

bool compare(int a, int b){
	return a>b;
}

int minNumItems(vector<int> &nums, int T){
	sort (nums.begin(), nums.end(),compare);
	int sum = 0;
	int count = 0;
	for (int i=0; i<nums.size(); i++){
		sum += nums[i];
		count++;
		if (sum >= T){
			return count;
		}
	}
	return -1;
}

int main(){
	int n , T;
	cout << "Enter number of elements: \n";
	cin >> n;
	cout << "Enter Target: \n";
	cin >> T;	
	
	vector<int> nums(n);
	cout << "Enter " << n << " integers:\n";
	for (int i = 0; i < n; ++i) {
		cin >> nums[i];
	}
	
	int result = minNumItems(nums,T);
	cout << "Minimum Number of Items to Reach Target Sum is: " << result <<endl;
	return 0;
}
