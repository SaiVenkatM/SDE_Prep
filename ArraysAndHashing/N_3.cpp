vector<int> majorityElement(vector<int> v) {
	// Write your code here
	//better approach
	/*int target = v.size()/3;
	vector<int> result;
	map<int, int> freq;
	for(auto i : v){
		freq[i] += 1;
	}
	for( const auto& pair: freq){
		if (pair.second > target){
			result.push_back(pair.first);
		}
		//cout<<pair.first<< " : " <<pair.second<<endl;
	}
	return result;*/
	//optimal approach
	int count1 = 0, count2 = 0, element1 =INT_MIN, element2 =INT_MIN;
	vector<int>  result;
	for(int i : v){
		if (count1 == 0 && element2 != i) {
			count1 += 1;
			element1 = i;
		}
		else if (count2 == 0 && element2 != i){
			count2 += 1;
			element2 = i;
		}
		else if ( i == element1){
			count1 += 1;
		}
		else if(i == element2){
			count2 += 1;
		}
		else {
			count1 -=1;
			count2 -=1;
		}
	}

    count1 = 0, count2 = 0;
	for(int i : v){
        if (i == element1) count1++;
        if (i == element2) count2++;
    }

    int mini = int(v.size() / 3) + 1;
    if (count1 >= mini) result.push_back(element1);
    if (count2 >= mini) result.push_back(element2);


    return result;
	
}