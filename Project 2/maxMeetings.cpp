#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool compareEndTime(const pair<int, int> &a, const pair<int, int> &b) {
	return a.second < b.second;
}


int maxMeetings (vector <pair<int,int>> meetings){
	sort (meetings.begin(),meetings.end(),compareEndTime);
	
	int count=0;
	signed int endTime=-1;
	
	for (int i=0; i<meetings.size(); i++){
		int start = meetings[i].first;
		int end = meetings[i].second;
		
		if (start >= endTime) {
			count++;
			endTime = end;
		}
	}
	return count;
}

int main() {
	int n;
	cout << "Enter number of meetings: ";
	cin >> n;
	
	vector<pair<int, int>> meetings(n);
	cout << "Enter start and end time for each meeting:\n";
	for (int i = 0; i < n; i++) {
		cin >> meetings[i].first >> meetings[i].second;
	}
	
	cout << "Maximum non-overlapping meetings: " << maxMeetings(meetings) << endl;
	return 0;
}
