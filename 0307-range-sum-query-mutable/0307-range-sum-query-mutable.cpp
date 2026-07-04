class NumArray {
public:
    vector<int> seg;
    vector<int> arr;
    int n;

    void build(int idx, int low, int high) {
        if (low == high) {
            seg[idx] = arr[low];
            return;
        }

        int mid = (low + high) / 2;
        build(2 * idx + 1, low, mid);
        build(2 * idx + 2, mid + 1, high);

        seg[idx] = seg[2 * idx + 1] + seg[2 * idx + 2];
    }

    void updateSeg(int idx, int low, int high, int i, int val) {
        if (low == high) {
            seg[idx] = val;
            return;
        }

        int mid = (low + high) / 2;

        if (i <= mid)
            updateSeg(2 * idx + 1, low, mid, i, val);
        else
            updateSeg(2 * idx + 2, mid + 1, high, i, val);

        seg[idx] = seg[2 * idx + 1] + seg[2 * idx + 2];
    }

    int query(int idx, int low, int high, int l, int r) {
        // no overlap
        if (high < l || low > r)
            return 0;

        // complete overlap
        if (low >= l && high <= r)
            return seg[idx];

        int mid = (low + high) / 2;

        int left = query(2 * idx + 1, low, mid, l, r);
        int right = query(2 * idx + 2, mid + 1, high, l, r);

        return left + right;
    }

    NumArray(vector<int>& nums) {
        arr = nums;
        n = nums.size();
        seg.resize(4 * n);

        if (n > 0)
            build(0, 0, n - 1);
    }

    void update(int index, int val) {
        updateSeg(0, 0, n - 1, index, val);
    }

    int sumRange(int left, int right) {
        return query(0, 0, n - 1, left, right);
    }
};