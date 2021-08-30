// QuickSort
int Partition(vector<int>& v, int p, int r) {
	int pivos = v[r];
	int i = p - 1;
	for (int j = p; j <= r - 1; j++) {
		if (v[j] <= pivos) {
			i = i + 1;
			swap(v[i], v[j]);
		}
	}
	swap(v[i + 1], v[r]);
	return i + 1;
}

void QuickSort(vector<int>& v, int p, int r) {
	if (p < r) {
		int q = Partition(v, p, r);
		QuickSort(v, p, q - 1);
		QuickSort(v, q + 1, r);
	}
}

int RandomizedPartition(vector<int>& v, int p, int r) {
	int i = rand() % (r - p + 1) + p;
	swap(v[r], v[i]);
	return Partition(v, p, r);
}

void RandomizedQuickSort(vector<int>& v, int p, int r) {
	if (p < r) {
		int q = RandomizedPartition(v, p, r);
		RandomizedQuickSort(v, p, q - 1);
		RandomizedQuickSort(v, q + 1, r);
	}
}
