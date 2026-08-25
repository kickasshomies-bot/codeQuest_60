// question link
// https://www.naukri.com/code360/problems/count-subsets-with-sum-k_3952532

int totalCount = 0;
void generate(vector<int>&arr,int index, int k, int curr_sum){
	if(curr_sum>k)return;
	if (index == arr.size()){
		if(curr_sum == k){
			totalCount++;
		}
		return;
	} 
	generate(arr,index+1,k,curr_sum);
	//take
	generate(arr,index+1,k,curr_sum+arr[index]);	
}
int findWays(vector<int>& arr, int k) {
	// Code here
	totalCount = 0;
	generate(arr,0,k,0);
	return totalCount;
}