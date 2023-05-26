// Subject interface
interface Image {
  display(): void;
}

// RealSubject class
class RealImage implements Image {
  private filename: string;

  constructor(filename: string) {
    this.filename = filename;
    this.loadFromDisk();
  }

  private loadFromDisk(): void {
    console.log(`Loading image: ${this.filename}`);
  }

  display(): void {
    console.log(`Displaying image: ${this.filename}`);
  }
}

// Proxy class
class ImageProxy implements Image {
  private realImage: RealImage | null = null;
  private filename: string;

  constructor(filename: string) {
    this.filename = filename;
  }

  display(): void {
    if (!this.realImage) {
      this.realImage = new RealImage(this.filename);
    }
    this.realImage.display();
  }
}

// Client code
const image: Image = new ImageProxy('image.jpg');

// The real image is loaded and displayed only when the display method is called
image.display();

// Subsequent calls to display do not reload the image, and it is directly displayed
image.display();

/*
In this example, we have an Image interface that defines the common operations for both the real subject (RealImage) and the proxy (ImageProxy). The RealImage class represents the actual image that is expensive to load, while the ImageProxy class acts as a placeholder for the real image.

The RealImage class loads the image from disk when it is instantiated and provides the display() method to show the image.

The ImageProxy class holds a reference to the real image (RealImage) and creates it lazily only when the display() method is called. On subsequent calls to display(), the proxy simply delegates the call to the real image.

In the client code, we create an instance of ImageProxy and call its display() method. The first call triggers the creation of the real image, loads it from disk, and displays it. Subsequent calls directly display the already loaded image without reloading it.

The proxy pattern allows for deferred loading and controlling access to the real object, providing additional functionality or optimizations when interacting with the subject.
*/