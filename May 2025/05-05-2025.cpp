// https://www.geeksforgeeks.org/problems/search-in-an-almost-sorted-array/1

// ==== BRUTE FORCE======
class Solution
{
public:
    int findTarget(vector<int> &arr, int target)
    {

        for (int i = 0; i < arr.size(); i++)
        {
            if (arr[i] == target)
            {
                return i;
            }
        }
        return -1;
    }
};

// ==== OPTIMISED=====
class Solution
{
public:
    int findTarget(vector<int> &arr, int target)
    {

        int low = 0;
        int high = arr.size() - 1;

        while (low <= high)
        {

            int mid = low + (high - low) / 2;

            if (arr[mid] == target)
            {
                return mid;
            }

            if (mid > low && arr[mid - 1] == target)
            {
                return mid - 1;
            }
            if (mid < high && arr[mid + 1] == target)
            {
                return mid + 1;
            }

            if (target < arr[mid])
            {
                high = mid - 2;
            }
            else
            {
                low = mid + 2;
            }
        }
        return -1;
    }
};