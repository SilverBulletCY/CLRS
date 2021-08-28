// InsertSort
void InsertSort(vector<int>& v) {
	int key, j;
	for (int i = 1; i < v.size(); i++) {
		key = v[i];
		j = i - 1;
		// Nondecreasing
		while (j >= 0 && v[j] > key) { 
		// Nonincreasing  
		// while (j >= 0 && v[j] < key)
			v[j + 1] = v[j];
			j = j - 1;
		}
		v[j + 1] = key;
	}
}
