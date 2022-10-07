int main()
{

    int n;
    cout << "enter the size of the array: " << endl;
    cin >> n;
    int i;
    int arr[n];
    cout << "enter elements of the array: " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    selectionSort(arr, n);
}