#include"SortingAlgorithms.h"


void mergeC(int a[], int first, int mid, int last, long long& compare) {

    int first1 = first, last1 = mid, first2 = mid + 1, last2 = last; // chia lam 2 mang
    int index = first1;
    int* tmpArr = new int[last + first + 1]; // Tao mang phu de luu cac phan tu

    while (++compare && first1 <= last1 && ++compare && first2 <= last2) { // Merge 2 mang lai
        if (++compare && a[first1] < a[first2])
            tmpArr[index++] = a[first1++];
        else
            tmpArr[index++] = a[first2++];
    }

    while (++compare && first1 <= last1) // Xet cac phan tu con du trong TH mang 2 da het
        tmpArr[index++] = a[first1++];
    while (++compare && first2 <= last2) // Xet cac phan tu con du trong TH mang 1 da het
        tmpArr[index++] = a[first2++];

    ++compare;
    for (index = first; index <= last; index++) { // Copy vao mang chinh
        a[index] = tmpArr[index];
        ++compare;
    }

    delete[]tmpArr;
}

void mergeSortC(int a[], int first, int last, long long& compare) {
    if (++compare && first < last) {
        int mid = (first + last) / 2; // Chia doi mang
        mergeSortC(a, first, mid, compare); // Goi de quy tiep tuc chia doi mang cho den khi con 1 phan tu
        mergeSortC(a, mid + 1, last, compare);
        mergeC(a, first, mid, last, compare);
    }
}

void heapRebuildC(int a[], int n, int start, long long& compare) {
    int leftChild = 2 * start + 1; // Xet child dau tien trong cay

    if (++compare && leftChild >= n) // neu vuot qua kich thuoc mang ==> ngung lai
        return;
    int larger = leftChild;
    int rightChild = 2 * start + 2; // Child con lai

    if (++compare&& rightChild < n)
        larger = a[leftChild] > a[rightChild] ? leftChild : rightChild; // Tim child lon hon de build max heap

    if (++compare && a[start] < a[larger]) {
        swap(a[start], a[larger]);
        heapRebuildC(a, n, larger, compare);
    }
}

void heapSortC(int a[], int n, long long& compare) {
    for (int i = (n - 1) / 2; i >= 0; i--)
        heapRebuildC(a, n, i, compare);

    swap(a[0], a[n - 1]);
    int heapSize = n - 1;
    while (heapSize > 1) {
        heapRebuildC(a, heapSize, 0, compare);
        heapSize--;
        swap(a[heapSize], a[0]);
    }

}

void radixSortC(int a[], int n, long long& compare) {
    int maxVal = a[0];

    ++compare;
    for (int i = 1; i < n; i++) {
        ++compare;
        if (a[i] > maxVal)
            maxVal = a[i];
    } // tim phan tu lon nhat

    int maxDigits = 0;
    do {
        maxDigits++;
        maxVal /= 10;
    } while (++compare && maxVal > 0); // tim so luong chu so cua phan tu lon nhat

    int** tmpArr = new int* [10]; // do co toi da 10 chu so 0 - 9
    ++compare;
    for (int i = 0; i < 10; i++) {
        tmpArr[i] = new int[n];
        ++compare;
    }

    int tmpCount[10];

    ++compare;
    for (int i = 0; i < maxDigits; i++) {
        ++compare;
        int divide = pow(10, i);

        ++compare;
        for (int j = 0; j < 10; j++) { // reset lai mang luu so luong
            tmpCount[j] = 0;
            ++compare;
        }

        ++compare;
        for (int j = 0; j < n; j++) {
            int digit = (a[j] / divide) % 10;
            tmpArr[digit][tmpCount[digit]++] = a[j]; //Bo vao mang theo cac chu so 0 - 9
            ++compare;
        }

        int index = 0;
        ++compare;
        for (int j = 0; j < 10; j++) {
            compare += 2;
            for (int k = 0; k < tmpCount[j]; k++)
                a[index++] = tmpArr[j][k];
            ++compare;
        }
    }
}

void flashSortC(int a[], int n, long long& compare)
{
    int minVal = a[0];
    int max = 0;
    int m = int(0.45 * n);
    int* l = new int[m];

    ++compare;
    for (int i = 0; i < m; i++) {
        l[i] = 0;
        ++compare;
    }

    ++compare;
    for (int i = 1; i < n; i++)
    {
        ++compare;
        if (++compare && a[i] < minVal)
            minVal = a[i];
        if (++compare && a[i] > a[max])
            max = i;
    }
    if (++compare && a[max] == minVal)
        return;

    double c1 = (double)(m - 1) / (a[max] - minVal);

    ++compare;
    for (int i = 0; i < n; i++)
    {
        ++compare;
        int k = int(c1 * (a[i] - minVal));
        ++l[k];
    }

    ++compare;
    for (int i = 1; i < m; i++) {
        l[i] += l[i - 1];
        ++compare;
    }
    swap(a[max], a[0]);

    int nmove = 0;
    int j = 0;
    int k = m - 1;
    int t = 0;
    int flash;

    while (++compare && nmove < n - 1)
    {
        while (++compare && j > l[k] - 1)
        {
            j++;
            k = int(c1 * (a[j] - minVal));
        }
        flash = a[j];
        if (++compare && k < 0)
            break;
        while (++compare && j != l[k])
        {
            k = int(c1 * (flash - minVal));
            int hold = a[t = --l[k]];
            a[t] = flash;
            flash = hold;
            ++nmove;
        }
    }

    ++compare;
    for (int i = 1; i < n; i++) {
        ++compare;
        int j = i - 1;
        int key = a[i];
        while (++compare && j >= 0 && ++compare && a[j] > key) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }

    delete[] l;
}

void quickSortC(int a[], int left, int right, long long& compare) {
    int pivot = a[(left + right) / 2];
    int i = left, j = right;

    while (++compare && i < j) {
        while (++compare && a[i] < pivot)
            i++;
        while (++compare && a[j] > pivot)
            j--;

        if (++compare && i <= j) {
            swap(a[i], a[j]);
            i++; j--;
        }
    }

    if (++compare && left < j)
        quickSortC(a, left, j, compare);
    if (++compare && i < right)
        quickSortC(a, i, right, compare);

}

void shakerSortC(int arr[], int n, long long& compare) {
    int left = 1, right = n - 1, k = n - 1;
    do {
        ++compare;
        for (int j = right; j >= left; --j) {
            ++compare;
            if (++compare && arr[j - 1] > arr[j]) {
                swap(arr[j - 1], arr[j]);
                k = j;
            }
        }
        left = k + 1;
        ++compare;
        for (int j = left; j <= right; ++j) {
            ++compare;
            if (++compare && arr[j - 1] > arr[j]) {
                swap(arr[j - 1], arr[j]);
                k = j;
            }
        }
        right = k - 1;
    } while (++compare && left <= right);
}

void merge(int a[], int first, int mid, int last) {
    int first1 = first, last1 = mid, first2 = mid + 1, last2 = last; // chia lam 2 mang
    int index = first1;
    int* tmpArr = new int[last + first + 1]; // Tao mang phu de luu cac phan tu

    while (first1 <= last1 && first2 <= last2) { // Merge 2 mang lai
        if (a[first1] < a[first2])
            tmpArr[index++] = a[first1++];
        else
            tmpArr[index++] = a[first2++];
    }

    while (first1 <= last1) // Xet cac phan tu con du trong TH mang 2 da het
        tmpArr[index++] = a[first1++];
    while (first2 <= last2) // Xet cac phan tu con du trong TH mang 1 da het
        tmpArr[index++] = a[first2++];

    for (index = first; index <= last; index++)// Copy vao mang chinh
        a[index] = tmpArr[index];

    delete[]tmpArr;
}

void mergeSort(int a[], int first, int last) {
    if (first < last) {
        int mid = (first + last) / 2; // Chia doi mang
        mergeSort(a, first, mid); // Goi de quy tiep tuc chia doi mang cho den khi con 1 phan tu
        mergeSort(a, mid + 1, last);
        merge(a, first, mid, last);
    }
}

void heapRebuild(int a[], int n, int start) {
    int leftChild = 2 * start + 1; // Xet child dau tien trong cay

    if (leftChild >= n) // neu vuot qua kich thuoc mang ==> ngung lai
        return;
    int larger = leftChild;
    int rightChild = 2 * start + 2; // Child con lai

    if (rightChild < n)
        larger = a[leftChild] > a[rightChild] ? leftChild : rightChild; // Tim child lon hon de build max heap

    if (a[start] < a[larger]) {
        swap(a[start], a[larger]);
        heapRebuild(a, n, larger);
    }
}

void heapSort(int a[], int n) {
    for (int i = (n - 1) / 2; i >= 0; i--)
        heapRebuild(a, n, i);

    swap(a[0], a[n - 1]);
    int heapSize = n - 1;
    while (heapSize > 1) {
        heapRebuild(a, heapSize, 0);
        heapSize--;
        swap(a[heapSize], a[0]);
    }
}

void radixSort(int a[], int n, double &time) {
    clock_t start, end;
    start = clock();

    int maxVal = a[0];

    for (int i = 1; i < n; i++)
        if (a[i] > maxVal)
            maxVal = a[i]; // tim phan tu lon nhat

    int maxDigits = 0;
    do {
        maxDigits++;
        maxVal /= 10;
    } while (maxVal > 0); // tim so luong chu so cua phan tu lon nhat

    int** tmpArr = new int* [10]; // do co toi da 10 chu so 0 - 9
    for (int i = 0; i < 10; i++)
        tmpArr[i] = new int[n];

    int tmpCount[10];

    for (int i = 0; i < maxDigits; i++) {
        int divide = pow(10, i);

        for (int j = 0; j < 10; j++) // reset lai mang luu so luong
            tmpCount[j] = 0;


        for (int j = 0; j < n; j++) {
            int digit = (a[j] / divide) % 10;
            tmpArr[digit][tmpCount[digit]++] = a[j]; //Bo vao mang theo cac chu so 0 - 9
        }

        int index = 0;
        for (int j = 0; j < 10; j++)
            for (int k = 0; k < tmpCount[j]; k++)
                a[index++] = tmpArr[j][k];
    }

    end = clock();

    time = (double)(end - start) / CLOCKS_PER_SEC;
}

void flashSort(int a[], int n, double &time) {
    clock_t start, end;
    start = clock();

    int minVal = a[0];
    int max = 0;
    int m = int(0.45 * n);
    int* l = new int[m];

    for (int i = 0; i < m; i++)
        l[i] = 0;

    for (int i = 1; i < n; i++)
    {
        if (a[i] < minVal)
            minVal = a[i];
        if (a[i] > a[max])
            max = i;
    }
    if (a[max] == minVal)
        return;

    double c1 = (double)(m - 1) / (a[max] - minVal);

    for (int i = 0; i < n; i++)
    {
        int k = int(c1 * (a[i] - minVal));
        ++l[k];
    }


    for (int i = 1; i < m; i++)
        l[i] += l[i - 1];

    swap(a[max], a[0]);

    int nmove = 0;
    int j = 0;
    int k = m - 1;
    int t = 0;
    int flash;

    while (nmove < n - 1)
    {
        while (j > l[k] - 1)
        {
            j++;
            k = int(c1 * (a[j] - minVal));
        }
        flash = a[j];
        if (k < 0)
            break;
        while (j != l[k])
        {
            k = int(c1 * (flash - minVal));
            int hold = a[t = --l[k]];
            a[t] = flash;
            flash = hold;
            ++nmove;
        }
    }

    for (int i = 1; i < n; i++) {
        int j = i - 1;
        int key = a[i];
        while (j >= 0 && a[j] > key) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }

    delete[]l;
    end = clock();

    time = (double)(end - start) / CLOCKS_PER_SEC;
}

void shakerSort(int arr[], int n, double &time) {
    clock_t start, end;

    start = clock();

    int left = 1, right = n - 1, k = n - 1;
    do {
        for (int j = right; j >= left; --j) {
            if (arr[j - 1] > arr[j]) {
                swap(arr[j - 1], arr[j]);
                k = j;
            }
        }
        left = k + 1;
        for (int j = left; j <= right; ++j) {
            if (arr[j - 1] > arr[j]) {
                swap(arr[j - 1], arr[j]);
                k = j;
            }
        }
        right = k - 1;
    } while (left <= right);

    end = clock();

    time = (double)(end - start) / CLOCKS_PER_SEC;
}

void quickSort(int a[], int left, int right) {
    int pivot = a[(left + right) / 2];
    int i = left, j = right;

    while (i < j) {
        while (a[i] < pivot)
            i++;
        while (a[j] > pivot)
            j--;

        if (i <= j) {
            swap(a[i], a[j]);
            i++; j--;
        }
    }

    if (left < j)
        quickSort(a, left, j);
    if (i < right)
        quickSort(a, i, right);
}

void selectionSort(int a[], int n, double& time)
{
    clock_t start, end;
    start = clock();
    for (int i = 0; i < n - 1; ++i) {
        int minIdx = i;
        for (int j = i + 1; j < n; ++j)
        {
            if (a[j] < a[minIdx])
                minIdx = j;
        }
        swap(a[minIdx], a[i]);
    }
    end = clock();
    time = double(end - start) / double(CLOCKS_PER_SEC);
}

void insertionSort(int a[], int n, double& time)
{
    clock_t start, end;
    start = clock();
    for (int i = 1; i < n; ++i) {
        int key = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] > key) {

            a[j + 1] = a[j];
            j = j - 1;
        }
        a[j + 1] = key;
    }
    end = clock();
    time = double(end - start) / double(CLOCKS_PER_SEC);
}

void bubbleSort(int a[], int n, double& time)
{
    clock_t start, end;
    start = clock();
    for (int i = 1; i < n; i++)
        for (int j = 0; j < n - i; j++) {
            if (a[j] > a[j + 1])
                swap(a[j], a[j + 1]);
        }
    end = clock();
    time = double(end - start) / double(CLOCKS_PER_SEC);
}

void selectionSortC(int a[], int n, long long& comp)
{
    for (int i = 0; ++comp && i < n - 1; ++i) {
        int minIdx = i;
        for (int j = i + 1; ++comp && j < n; ++j)
        {
            if (++comp && a[j] < a[minIdx])
                minIdx = j;
        }
        swap(a[minIdx], a[i]);
    }
}

void insertionSortC(int a[], int n, long long& comp)
{
    for (int i = 1; ++comp && i < n; ++i) {
        int key = a[i];
        int j = i - 1;
        while (++comp && j >= 0 && ++comp && a[j] > key) {

            a[j + 1] = a[j];
            j = j - 1;
        }
        a[j + 1] = key;
    }
}

void bubbleSortC(int a[], int n, long long& comp)
{
    for (int i = 1; ++comp && i < n; i++)
        for (int j = 0; ++comp && j < n - i; j++) {
            if (++comp && a[j] > a[j + 1])
                swap(a[j], a[j + 1]);
        }
}

void shellSort(int a[], int n, double &time)
{
    clock_t start, end;
    start = clock();
    for (int interval = n / 2; interval > 0; interval /= 2)
    {
        for (int i = interval; i < n; i++)
        {
            int temp = a[i];
            int j = i;
            for (j = i; j >= interval && a[j - interval] > temp; j -= interval)
                a[j] = a[j - interval];
            a[j] = temp;
        }
    }
    end = clock();

    time = (double)(end - start) / CLOCKS_PER_SEC;
}

void countingSort(int a[], int n, double &time)
{
    clock_t start, end;
    start = clock();

    int max = a[0];
    for (int i = 1; i < n; i++)
        if (a[i] > max)
            max = a[i];

    int* count = new int[max + 1];
    for (int i = 0; i <= max; i++)
        count[i] = 0;

    for (int i = 0; i < n; i++)
        count[a[i]]++;

    for (int i = 1; i <= max; i++)
        count[i] += count[i - 1];

    int* temp = new int[n];
    for (int i = 0; i < n; i++)
    {
        temp[count[a[i]] - 1] = a[i];
        count[a[i]]--;
    }

    for (int i = 0; i < n; i++)
        a[i] = temp[i];
    delete[] count;
    delete[] temp;

    end = clock();

    time = (double)(end - start) / CLOCKS_PER_SEC;
}

void shellSortC(int a[], int n, long long &compare) {
    for (int interval = n / 2; ++compare && interval > 0; interval /= 2)
    {
        for (int i = interval;++compare && i < n; i++)
        {
            int temp = a[i];
            int j = i;
            for (j = i;++compare && j >= interval && ++compare && a[j - interval] > temp; j -= interval)
                a[j] = a[j - interval];
            a[j] = temp;
        }
    }
}

void countingSortC(int a[], int n, long long &compare)
{
    int max = a[0];
    for (int i = 1; ++compare && i < n; i++)
        if (++compare && a[i] > max)
            max = a[i];

    int* count = new int[max + 1];
    for (int i = 0; ++compare && i <= max; i++)
        count[i] = 0;

    for (int i = 0; ++compare && i < n; i++)
        count[a[i]]++;

    for (int i = 1; ++compare && i <= max; i++)
        count[i] += count[i - 1];

    int* temp = new int[n];
    for (int i = 0; ++compare && i < n; i++)
    {
        temp[count[a[i]] - 1] = a[i];
        count[a[i]]--;
    }

    for (int i = 0; ++compare && i < n; i++)
        a[i] = temp[i];
    delete[] count;
    delete[] temp;
}

