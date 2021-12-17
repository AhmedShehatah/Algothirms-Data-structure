/**
 * This code is an implementation for binary search using kotlin and iteration
 * Created by Ahmed Shehatah
 * all copyrights are received
 * ahmed2002.eg@gmail.com
 */

fun main() {
    // read size of the array
    println("Enter the size of the array")
    val size = readLine()!!.toInt()
    // init the array
    val arr = IntArray(size)

    // read array elements
    println("Enter array elements")
    for (i in arr.indices)
        arr[i] = readLine()!!.toInt()
    // sort the array
    arr.sort()

    //read the item you want to search about
    println("Enter the number you search about: ")
    val key = readLine()!!.toInt()
    // search about the item
    val result = binarySearch(arr, size, key)
    // print the result
    if (result == -1)
        println("Not Found")
    else
        println("Found in index $result")

}

/**
 * this search about an item in an array
 * and return its position of it's found and -1 if not
 */
fun binarySearch(arr: IntArray, sz: Int, key: Int): Int {
    var low = 0 //
    var high = sz - 1
    while (low <= high) {
        val middle = (low + high) / 2
        if (arr[middle] == key)
            return middle
        else if (arr[middle] > arr[low])
            low = middle + 1
        else
            high = middle - 1
    }
    return -1
}