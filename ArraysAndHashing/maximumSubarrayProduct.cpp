#include<vector>

int subarrayWithMaxProduct(vector<int> &arr){
	// Write your code here.
	/* Brute force
	for( size_t i= 0; i < arr.size(); i++){
		for (size_t j=0; j < arr.size(); j++){
			product = 1;
			for (size_t k =i; k <= j; k++){
				product *=arr[k];
			}
			//cout<<product<<endl;
			if (result <= product){
				result = product;
			}
		}
	}*/
	/* Better Approach
	for(size_t i =0; i <arr.size(); i++){
		product = arr[i];
		for(size_t j =i; j<arr.size()-1; j++){
			product *= arr[j+1];
			if(result <= product){
				result = product;
			}
		}
		if(result <= product){
				result = product;
			}
	}*/

	//Optimal Approach
	int max_prod = arr[0];
	int  min_prod = arr[0];
	int result = arr[0];
	for (size_t i = 1; i<arr.size(); i++){
		if (arr[i]<0){
			swap(max_prod, min_prod);
		}
		max_prod = max(arr[i], arr[i]*max_prod);
		min_prod = min(arr[i], arr[i]*min_prod);
		result = max(result,max_prod);
	}
	return result;
	}