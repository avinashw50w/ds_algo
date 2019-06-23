import java.io.*;
import java.util.*;

public class Solution {
	public static void addNumber(int number, PriorityQueue<Integer> lowers, PriorityQueue<Integer> highers) {
		if (lowers.size() == 0 || number < lowers.peek()) 
			lowers.add(number);
		else
			highers.add(number);
	}

	public static void rebalance(PriorityQueue<Integer> lowers, PriorityQueue<Integer> highers) {
		PriorityQueue<Integer> biggerHeap = lowers.size() > highers.size() ? lowers : highers;
		PriorityQueue<Integer> smallerHeap = lowers.size() < highers.size() ? lowers : highers;

		if (biggerHeap - smallerHeap >= 2) {
			smallerHeap.add(biggerHeap.poll());
		}
	}

	public static double getMedian(PriorityQueue<Integer> lowers, PriorityQueue<Integer> highers) {
		PriorityQueue<Integer> biggerHeap = lowers.size() > highers.size() ? lowers : highers;
		PriorityQueue<Integer> smallerHeap = lowers.size() < highers.size() ? lowers : highers;

		if (biggerHeap.size() == smallerHeap.size()) 
			return ((double)biggerHeap.peek() + smallerHeap.peek()) / 2;
		else 
			return biggerHeap.peek();
	}

	public static double[] getMedians(int[] arr) {
		// max heap
		PriorityQueue<Integer> lowers = new PriorityQueue<Integer> (new Comparator<Integer> () {
			public int compare(Integer a, Integer b) {
				return -1 * a.compareTo(b);
			}
		});
		// min heap
		PriorityQueue<Integer> highers = new PriorityQueue<Integer> ();

		double[] medians = new double[arr.length];

		for (int i = 0; i < arr.length; ++i) {
			int number = arr[i];
			addNumber(number, lowers, highers);
			rebalance(lowers, highers);
			medians[i] = getMedian(lowers, highers);
		}

		return medians;
	}
}
