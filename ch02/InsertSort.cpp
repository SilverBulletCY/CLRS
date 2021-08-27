void InsertSort(vector<int>& v) {
	int key, j;
	for (int i = 1; i < v.size(); i++) {
		cout << "yes" << endl;
		key = v[i];
		j = i - 1;
		while (v[j] > key && j >= 0) {
			v[j + 1] = v[j];
			j = j - 1;
		}
		v[j + 1] = key;
	}
}