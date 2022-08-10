/*
used in publisher / subscriber scenarios
 */

public class Channel {
	private string name;
	private list<Subscriber> subs = new ArrayList<>();
	private list<Video> videos;

	public void subscribe(Subscriber sub) {
		subs.add(sub);
	}

	public void unsubscribe(Subscriber sub) {
		subs.remove(sub);
	}

	public void notifySubscribers() {
		for (Subscriber sub : subs) {
			sub.update();
		}
	}

	public void uploadVideo(Video video) {
		videos.add(video);
		notifySubscribers();
	}
}

public class Subscriber {
	private string name;
	Channel channel;

	public void update() {
		System.out.println("Video uploaded..");
	}

	public void subscribeChannel(Channel channel) {
		this.channel = channel;
		this.channel.subscribe(this);
	}


}