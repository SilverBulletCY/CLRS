
void InsertSort(vector<int>& v) {
	int key, j;
	for (int i = 1; i < v.size(); i++) {
		key = v[i];
		j = i - 1;
		// Non-descending
		while (j >= 0 && v[j] > key) { 
		// Non-ascending  
		// while (j >= 0 && v[j] < key)
			v[j + 1] = v[j];
			j = j - 1;
		}
		v[j + 1] = key;
	}
}