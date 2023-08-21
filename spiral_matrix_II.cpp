class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int count = 1;
        int startX = 0, startY = 0;
        int offset = 1, cycNum = n/2;
        int j = startX, i = startY;

        vector<vector<int>> result;
        result.resize(n);

        for (int i = 0; i < n; ++i) {
            result[i].resize(n);
        }

        while (cycNum) {
            j = startX, i = startY;

            for (; j < n - offset; ++j) {
                result[startY][j] = count++;
            }

            for (; i < n - offset; ++i) {
                result[i][j] = count++;
            }

            for (; j > startX; --j) {
                result[i][j] = count++;
            }

            for (; i > startY; --i) {
                result[i][j] = count++;
            }

            ++startX;
            ++startY;
            ++offset;
            --cycNum;
        }

        if (n % 2 == 1) {
            j = startX, i = startY;
            result[i][j] = count++;
        }

        return result;
    }
};