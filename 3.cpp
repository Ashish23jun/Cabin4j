#include<bits/stdc++.h>
using namespace std;

int main(){
	#ifndef ONLINE_JUDGE

    // For getting input from input.txt file
	freopen("input.txt", "r", stdin);

    // Printing the Output to output.txt file
	freopen("output.txt", "w", stdout);

	#endif

	vector<pair<double,string>>arr;
	double d;
	string s;
	while(cin>>d && getline(cin,s)){
		getline(cin,s);
		arr.push_back({d,s});
	}

	int k=d;
	
	priority_queue<pair<double,string>>pq;

	for(auto &j:arr){
		pq.push(j);
		if((int)pq.size()>k)
			pq.pop();
	}
	while(pq.size()){
		cout<<pq.top().first<<' '<<pq.top().second<<endl;
		pq.pop();
	}
}
