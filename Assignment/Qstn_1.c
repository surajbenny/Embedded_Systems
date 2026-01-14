int secondLargest(int arr[], int n)
{
    int max = arr[0];
    int second = arr[1];

    if (second > max) {
        int temp = max;
        max = second;
        second = temp;
    }

    for (int i = 2; i < n; i++) {
        if (arr[i] > max) {
            second = max;
            max = arr[i];
        }
        else if (arr[i] > second && arr[i] != max) {
            second = arr[i];
        }
    }

    return second;
}
