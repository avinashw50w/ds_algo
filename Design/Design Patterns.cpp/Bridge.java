/**
 * Bridge pattern is used to decouple abstraction from implementation
 */
/**
 * Notification service: send text or QRcode as message via SMS, Email or whatsapp
 * if we create class of each one of them, then we will need (N x M) classes, where
 * N = types of message (text, QRcode)
 * M = medium of sending message (SMS, Email, ...)
 * But by using Bridge pattern, we will need to implement only N+M classes
 */

public interface NotificationSender {
    void sendNotification(String message);
}

public class SMS implements NotificationSender {
    @Override
    public void sendNotification(String message) {
        System.out.println("Notification sent by SMS");
    }
}

public class Email implements NotificationSender {
    @Override
    public void sendNotification(String message) {
        System.out.println("Notification sent by Email");
    }
}

public abstract class Notification {
    protected NotificationSender notificationSender;

    public Notification(NotificationSender notificationSender) {
        this.notificationSender = notificationSender;
    }

    public abstract void sendMessage(String message);
}

public class TextMessage extends Notification {
    public TextMessage(NotificationSender notificationSender) {
        super(notificationSender);
    }

    @Override
    void sendMessage(String message) {
        notificationSender.sendNotification(message);
    }
}

public class QRMessage extends Notification {
    public QRMessage(NotificationSender notificationSender) {
        super(notificationSender);
    }

    @Override
    void sendMessage(String message) {
        String qrCodeUrl = getQRCodeURL(message);
        notificationSender.sendNotification(qrCodeUrl);
    }
}

public static void Main(String[] args) {
    TextMessage textMessage = new TextMessage(new Email());
    textMessage.sendMessage("Hello world");

    QRMessage qrMessage = new QRMessage(new SMS());
    qrMessage.sendMessage("Hello world");
}

