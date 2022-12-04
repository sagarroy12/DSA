package sorting;

public class Sort {

    public void bubbleSort(int arr[]) {

        for (int i = 0; i < arr.length; i++) {
            for (int j = 0; j < arr.length - i - 1; j++) {
                if (arr[j] > arr[j + 1]) {
                    int t = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = t;
                }
            }
        }
    }

    public void selectionSort(int arr[]) {
        int size = arr.length;
        for (int i = 0; i < size; i++) {
            int min = i;
            for (int j = i + 1; j < size; j++) {
                if (arr[j] < arr[min]) {
                    min = j;
                }
            }
            if (i != min) {
                int t = arr[i];
                arr[i] = arr[min];
                arr[min] = t;
            }
        }
    }

    public void insertionSort(int arr[]) {
        int size = arr.length;

        for (int i = 1; i < size; i++) {
            int key = arr[i];
            int j = i - 1;
            while (j >= 0 && arr[j] > key) {
                arr[j + 1] = arr[j];
                j--;
            }
            arr[j + 1] = key;
        }
    }
// merge sort algo start.
    void merge(int arr[], int s, int mid, int e) {

        int s1 = s;
        int s2 = mid + 1;
        int newSize = e - s + 1;
        int ar[] = new int[newSize];
        int i = 0;
        while (s1 <= mid && s2 <= e) {
            if (arr[s1] <= arr[s2]) {
                ar[i++] = arr[s1++];
            } else {
                ar[i++] = arr[s2++];
            }
        }
        while (s1 <= mid) {
            ar[i++] = arr[s1++];
        }
        while (s2 <= e) {
            ar[i++] = arr[s2++];
        }

        for (int j = 0; j < newSize; j++) {
            arr[s++] = ar[j];
        }
        return;
    }

    void split(int arr[], int s, int e) {
        if (s >= e) {
            return;
        }
        int mid = (s + e) / 2;
        split(arr, s, mid);
        split(arr, mid + 1, e);

        merge(arr, s, mid, e);
        return;

    }

    public void mergeSort(int arr[]) {
        System.out.println("h");
        int size = arr.length;
        split(arr, 0, size - 1);
    }

    //merge sort algo end.
};
