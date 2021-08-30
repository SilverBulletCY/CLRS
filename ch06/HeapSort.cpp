// HeapSort
void MaxHeapify(vector<int>& v, int i) {
	int l = 2 * i - 1, r = 2 * i;
	int largest;
	if (l <= v.size() - 1 && v[l] > v[i - 1]) {
		largest = l;
	}
	else {
		largest = i - 1;
	}
	if (r <= v.size() - 1 && v[r] > v[largest]) {
		largest = r;
	}
	if (largest != i - 1) {
		swap(v[i - 1], v[largest]);
		MaxHeapify(v, largest + 1);
	}

}

void BuildMaxHeap(vector<int>& v) {
	for (int i = v.size() / 2; i >= 1; i--) {
		MaxHeapify(v, i);
	}
}

void HeapSort(vector<int>& v, vector<int>& res) {
	BuildMaxHeap(v);
	for (int i = v.size() - 1; i >= 1; i--) {
		res.push_back(v[0]);
		swap(v[0], v[i]);
		v.pop_back();
		MaxHeapify(v, 1);
	}
	res.push_back(v[0]);
}
