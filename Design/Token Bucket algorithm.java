public class TokenBucket {
	private final int maxBucketSize;
	private final int refillRate; // no of requests per nano second

	private int currBucketSize;
	private int lastRefillTimestamp;

	// constructor
	public TokenBucket(int maxBucketSize, int refillRate) {
		this.maxBucketSize = maxBucketSize;
		this.refillRate = refillRate;

		this.currBucketSize = maxBucketSize;
		this.lastRefillTimestamp = System.currentTimeMillis();
	}

	// synchronized, as several threads may be calling this function concurrently
	// tokens represents the cost of the operation
	public synchronized boolean allowRequest(int tokens) {
		refill();

		if (currBucketSize > tokens) {
			currBucketSize -= tokens;
			return true;
		}

		return false;
	}

	private void refill() {
		int now = System.currentTimeMillis();
		int tokensToAdd = (now - this.lastRefillTimestamp) * this.refillRate;
		this.currBucketSize = Math.min(this.currBucketSize + tokensToAdd, this.maxBucketSize);
		this.lastRefillTimestamp = now;
	}
}