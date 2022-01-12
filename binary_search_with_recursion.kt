/**
 * @file binary_search_with_recursion.kt
 * @author Ahmed Shehatah  (ahmed2002.eg@gmail.com)
 * @brief  This code is an implementation for binary
 * search using kotlin and recursion
 *
 * time complexity O(nLog(n))
 *
 * @version 0.1
 * @date 2022-1-12
 *
 * @copyright Copyright (c) 2022
 *
 */
fun main() {
    println("Enter Size of the array")
    val size = readLine()!!.toInt()
    val arr = IntArray(size)
    println("Enter Elements of array")
    for (i in arr.indices) arr[i] = readLine()!!.toInt()
    arr.sort()
    println("Enter target")
    val target = readLine()!!.toInt()
    val position = search(arr, 0, size - 1, target)
    if (position == -1) println("NOT FOUND")
    else println("Position of element = $position")

}

fun search(arr: IntArray, low: Int, high: Int, target: Int): Int {

    if (low <= high) {
        val mid = (low + high) / 2
        return if (arr[mid] == target) mid
        else if (arr[mid] > target) search(arr, low, mid - 1, target)
        else search(arr, mid + 1, high, target)
    }
    return -1
}
