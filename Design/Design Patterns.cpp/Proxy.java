/*It's a structural pattern
When we want to create a proxy of an object with the same functionalities but want to do some 
extra stuff before or after the actual function call
*/
public interface Internet {
    void connectTo(String website);
}

public class RealInternet implements Internet {
    @override
    public void connectTo(String website) {

    }
}

public class ProxyInternet implements Internet {
    private Internet realInternet;

    public ProxyInternet(Internet realInternet) {
        this.realInternet = realInternet;
    }
    @override
    public void connectTo(String website) {
        if (bannedWebsites.indexOf(website) == -1) {
            throw new IllegalStateException("Cannot connect to the website " + website);
        }
        this.realInternet.connectTo(website);
    }
}