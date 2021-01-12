学习笔记
```
    void bubbleSort(vector<int>& array) {
        
        for (int i=0; i<array.size(); i++) {
            for (int j=i; j < array.size(); j++) {
                if (array[i] > array[j]) {
                    int temp = array[i];
                    array[i] = array[j];
                    array[j] = temp;
                }
            }
        }
    }

    void selectionSort(vector<int>& array) {
        for (int i=0; i<array.size(); i++) {
            
            int minIndex = i;
            for (int j=i+1; j<array.size(); j++) {
                if (array[j] < array[minIndex]) {
                    minIndex = j;
                }
            }
            swap(array[i], array[minIndex]);
        }
    }
    
    void insertSort(vector<int>& array) {
        
        //2,5,1
        for (int i=1; i<array.size(); i++) {
            
            int current = array[i];
            int preIndex = i-1;
            
            while (preIndex>=0 && array[preIndex] > current) {
                array[preIndex+1] = array[preIndex];
                preIndex--;
            }
            array[preIndex+1] = current;
        }

    }

    int partition(vector<int>& array, int begin, int end){
        int pivot = end;
        int counter = begin;
        
        // pivot: 标杆位置，counter: 小于pivot的元素的个数
        for (int i=begin; i<end; i++) {
            if (array[i] < array[pivot]) {
                swap(array[i], array[counter]);
                counter++;
            }
        }
        swap(array[pivot], array[counter]);
        return counter;
    }
    
    void quickSort(vector<int>& array, int begin, int end) {
        
        if (end<=begin) {
            return;
        }
        
        int pivot = partition(array, begin, end);
        
        quickSort(array, begin, pivot-1);
        quickSort(array, pivot+1, end);
    }
    
    void merge(vector<int> array, int left, int mid, int right) {
        
        vector<int> tmp(right-left+1);
        
        int i = left;
        int j = mid+1;
        int k = 0;
        
        
        while (i <= mid && j <= right) {
            tmp[k++] = array[i]<array[j] ? array[i++] : array[j++];
        }
        
        while (i <= mid) {
            tmp[k++] = array[i++];
        }
        while (j <= right) {
            tmp[k++] = array[j++];
        }
        
        for (i= left,k=0; i<=right;) {
            array[i++] = tmp[k++];
        }
    }
    
    void mergeSort(vector<int>& array, int left, int right){
        
        if (right >= left) {
            return;
        }
        
        int mid = (left+right) >> 1;
        
        mergeSort(array, left, mid);
        mergeSort(array, mid+1, right);
        merge(array, left, mid, right);
    }

```