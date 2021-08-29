// The maximum-subarray problem
int FindMaxCrossingSubArray(vector<int>& v, int low, int mid, int high) {
	int left_sum = INF_MIN, right_sum = INF_MIN;
	int sum = 0;
	for (int i = mid; i >= low; i--) {
		sum = sum + v[i];
		if (sum > left_sum) {
			left_sum = sum;
		}
	}
	sum = 0;
	for (int j = mid + 1; j <= high; j++) {
		sum = sum + v[j];
		if (sum > right_sum) {
			right_sum = sum;
		}
	}
	return left_sum + right_sum;
}

int FindMaximumSubArray_Recursive(vector<int>& v, int low, int high) {
	if (low == high) {
		return v[low];
	}
	else {
		int mid = (low + high) / 2;
		int left_sum = FindMaximumSubArray_Recursive(v, low, mid);
		int right_sum = FindMaximumSubArray_Recursive(v, mid + 1, high);
		int cross_sum = FindMaxCrossingSubArray(v, low, mid, high);
		if (left_sum >= right_sum && left_sum >= cross_sum) {
			return left_sum;
		}
		else if (right_sum >= left_sum && right_sum >= cross_sum) {
			return right_sum;
		}
		else {
			return cross_sum;
		}
	}
}

int FindMaximumSubArray_DP(vector<int>& v, int low, int high) {
	vector<int> dp;
	dp.push_back(v[low]);
	int sum = dp[0];
	for (int i = low + 1; i <= high; i++) {
		dp.push_back(max(dp[i - 1] + v[i], v[i]));
		if (dp[i] > sum) {
			sum = dp[i];
		}
	}
	return sum;
}
