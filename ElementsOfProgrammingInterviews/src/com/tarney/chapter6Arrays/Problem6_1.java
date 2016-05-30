/*
 * Solution to problem 6.1 on page 59 of Elements of Programming Interviews
 * <p>
 * <em>Problem:</em> Write a program that takes an array A and an index i into A, and rearranges the elements such that all elements less than A[i] (the "pivot") appear first,
 * followed by elements equal to the pivot, followed by elements greater than the pivot.
 * </p>
 * 
 * <p>
 * <em>Hint: Think about the partition step in quicksort</em>
 * </p>
 * 
 * <p>
 * <em>Solution: Modify quicksort to iterate twice over the list: once to move values less than pivot to base of array
 * and another time to iterate through values not less than pivot and move those greater to the top of the array (leaving equal values in the middle)</em> 
 * 
 * @author Brandon Tarney
 * @version 1.0
 */

package com.tarney.chapter6Arrays;

public class Problem6_1 {
	
	/*
	 * Rearrange an array into values less than, equal to, and greater than a pivot
	 * 
	 * @param	inputArray	the input array to be sorted/rearranged
	 * @param	pivotIndex	the index which will be rearranged around (0 indexed)
	 * @return	int[]		modified inputArray
	 */
	public static int[] triPartition(int[] inputArray, int pivotIndex) {
		int lessThanIndex = 0;
		int pivotValue = inputArray[pivotIndex];
		for (int index = 0; index < inputArray.length; index++) {
			if (inputArray[index] < pivotValue) {
				inputArray = swap(inputArray, lessThanIndex, index);
				lessThanIndex++;
			}
		}
		int greaterThanIndex = inputArray.length - 1;
		for (int index = inputArray.length -1 ; index >= lessThanIndex; index--) {
			if (inputArray[index] > pivotValue) {
				inputArray = swap(inputArray, greaterThanIndex, index);
				greaterThanIndex--;
			}
		}
		return inputArray;
	}
	
	/*
	 * Swap 2 array values
	 */
	public static int[] swap(int[] inputArray, int firstIndex, int secondIndex) {
		int temp = inputArray[secondIndex];
		inputArray[secondIndex] = inputArray[firstIndex];
		inputArray[firstIndex] = temp;
		return inputArray;
	}
	
	/*
	 * Print the values of an array in-line
	 */
	public static void printArray(int[] inputArray) {
		for (int i = 0; i < inputArray.length; i++ ) {
			System.out.print( inputArray[i] + " ");
		}
		System.out.println();
	}
	
	public static void main(String[] args) {
		int[] testArray = {1, 10, 6, -1, 4, 6, 3, 4 };
		printArray(testArray);
		testArray = triPartition(testArray, 4);
		printArray(testArray);

	}

}
