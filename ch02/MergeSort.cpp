// MergeSort
void Merge(vector<int>& v, int p, int q, int r) {
	vector<int> L, R;
	int n1 = q - p + 1;
	int n2 = r - q;
	int i, j;
	for (i = 0; i < n1; i++) {
		L.push_back(v[p + i]);
	}
	for (j = 0; j < n2; j++) {
		R.push_back(v[q + j + 1]);
	}
	// Sentinels are set so that we need not to frequently check if i or j overflows.
	L.push_back(INF_MAX);
	R.push_back(INF_MAX);
	i = 0;
	j = 0;
	for (int k = p; k <= r; k++) {
		if (L[i] <= R[j]) {
			v[k] = L[i];
			i = i + 1;
		}
		else {
			v[k] = R[j];
			j = j + 1;
		}
	}
}

void MergeSort(vector<int>& v, int p, int r) {
	if (p < r) {
		int q = (p + r) / 2;
		MergeSort(v, p, q);
		MergeSort(v, q + 1, r);
		Merge(v, p, q, r);
	}
}
