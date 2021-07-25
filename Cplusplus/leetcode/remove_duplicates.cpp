int removeDuplicates(vector<int>& nums) {
        int totalLength = nums.size();

        int curIndex = 0;
        int moveStart = 0;
        int moveLen = 0;

        while(curIndex < totalLength) {
            int length = getSameLength(curIndex, totalLength, nums);
            if (length > 1) {
                moveForword(length - 1, curIndex + length, totalLength, nums);
                totalLength -= (length - 1);
            }
            curIndex++;
        }
        return totalLength;
    }

    void moveForword(int length, int startIndex, int endIndex, vector<int>& nums) {
        for(int i = startIndex; i < endIndex; i++) {
            nums[i - length] = nums[i];
        }
    }

    int getSameLength(int from, int totalLength, vector<int>& nums) {
        int length = 1;
        int index = from + 1;
        while(index < totalLength) {
            if (nums[index] == nums[from]) {
                length++;
                index++;
            } else {
                return length;
            }
        }
        return length;
    }

    int removeDuplicates(vector<int>& nums) {
        if (nums.size() < 1)
        {
            return 0;
        }

        int acceptedIndex = 0;
        int acceptedValue = nums[0];

        for (size_t i = 0; i < nums.size(); i++)
        {
            if (nums[i] != acceptedValue)
            {
                nums[++acceptedIndex] = nums[i];
                acceptedValue = nums[i];
            }
        }
        return acceptedIndex + 1;
    }