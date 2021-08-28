
int BinarySearch_Iterative(vector<int>& v, int key, int low, int high) {
	while (low < high) {
		int mid = (low + high) / 2;
		if (key == v[mid]) {
			return mid;
		}
		else if (key < v[mid]) {
			high = mid - 1;
		}
		else if (key < v[mid]) {
			low = mid + 1;
		}
	}
	return -1;
}

int BinarySearch_Recursive(vector<int>& v, int key, int low, int high) {
	if (low > high) {
		return -1;
	}
	int mid = (low + high) / 2;
	if (key == v[mid]) {
		return mid;
	}
	else if (key < v[mid]) {
		BinarySearch_Recursive(v, key, low, mid - 1);
	}
	else {
		BinarySearch_Recursive(v, key, mid + 1, high);
	}
}

int main() {
	vector<int> v = { 1,2,3,4,5 };
	cout << BinarySearch_Iterative(v, 3, 0, v.size() - 1) << endl;
	cout << BinarySearch_Recursive(v, 3, 0, v.size() - 1) << endl;
}