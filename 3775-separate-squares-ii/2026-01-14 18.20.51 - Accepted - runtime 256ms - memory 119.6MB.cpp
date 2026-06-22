class Solution {
public:
    struct Event {
        double y;
        int type; // +1 = add, -1 = remove
        int x1, x2;
        bool operator<(const Event& other) const {
            return y < other.y;
        }
    };

    vector<double> xs;
    vector<int> cnt;
    vector<double> len;

    void pushUp(int node, int l, int r) {
        if (cnt[node] > 0) {
            len[node] = xs[r + 1] - xs[l];
        } else if (l == r) {
            len[node] = 0;
        } else {
            len[node] = len[node * 2] + len[node * 2 + 1];
        }
    }

    void update(int node, int l, int r, int ql, int qr, int val) {
        if (qr < l || r < ql) return;
        if (ql <= l && r <= qr) {
            cnt[node] += val;
            pushUp(node, l, r);
            return;
        }
        int mid = (l + r) / 2;
        update(node * 2, l, mid, ql, qr, val);
        update(node * 2 + 1, mid + 1, r, ql, qr, val);
        pushUp(node, l, r);
    }

    double separateSquares(vector<vector<int>>& squares) {
        vector<Event> events;

        // collect x-coordinates
        for (auto& s : squares) {
            xs.push_back(s[0]);
            xs.push_back(s[0] + s[2]);
        }

        sort(xs.begin(), xs.end());
        xs.erase(unique(xs.begin(), xs.end()), xs.end());

        auto getX = [&](double x) {
            return lower_bound(xs.begin(), xs.end(), x) - xs.begin();
        };

        // build events
        for (auto& s : squares) {
            int x1 = getX(s[0]);
            int x2 = getX(s[0] + s[2]) - 1;
            double y1 = s[1];
            double y2 = s[1] + s[2];
            events.push_back({y1, +1, x1, x2});
            events.push_back({y2, -1, x1, x2});
        }

        sort(events.begin(), events.end());

        int m = xs.size();
        cnt.assign(4 * m, 0);
        len.assign(4 * m, 0);

        // -------- First sweep: total area --------
        double totalArea = 0;
        for (int i = 0; i + 1 < events.size(); i++) {
            update(1, 0, m - 2, events[i].x1, events[i].x2, events[i].type);
            double dy = events[i + 1].y - events[i].y;
            totalArea += len[1] * dy;
        }

        // -------- Second sweep: find split Y --------
        cnt.assign(4 * m, 0);
        len.assign(4 * m, 0);

        double currArea = 0;
        double target = totalArea / 2.0;

        for (int i = 0; i + 1 < events.size(); i++) {
            update(1, 0, m - 2, events[i].x1, events[i].x2, events[i].type);
            double dy = events[i + 1].y - events[i].y;
            double sliceArea = len[1] * dy;

            if (currArea + sliceArea >= target) {
                double remaining = target - currArea;
                return events[i].y + remaining / len[1];
            }
            currArea += sliceArea;
        }

        return 0.0; // fallback (should not reach)
    }
};