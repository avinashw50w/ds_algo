/*
it's like composition
 */
// Component interface
interface Component {
  operation(): void;
}

// Leaf class
class Leaf implements Component {
  private name: string;

  constructor(name: string) {
    this.name = name;
  }

  operation(): void {
    console.log(`Leaf ${this.name} operation.`);
  }
}

// Composite class
class Composite implements Component {
  private children: Component[] = [];

  add(component: Component): void {
    this.children.push(component);
  }

  remove(component: Component): void {
    const index = this.children.indexOf(component);
    if (index !== -1) {
      this.children.splice(index, 1);
    }
  }

  operation(): void {
    console.log("Composite operation:");
    for (const child of this.children) {
      child.operation();
    }
  }
}

// Client code
const leaf1: Component = new Leaf("Leaf 1");
const leaf2: Component = new Leaf("Leaf 2");
const leaf3: Component = new Leaf("Leaf 3");

const composite1: Component = new Composite();
composite1.add(leaf1);
composite1.add(leaf2);

const composite2: Component = new Composite();
composite2.add(composite1);
composite2.add(leaf3);

// Calling operation on the composite, which recursively calls operation on its children
composite2.operation();

////////////////////////////////////////////////////////////////

/*In this example, we have a Component interface that defines the common interface for both the leaf and composite classes. The Leaf class represents the individual elements or leaves of the composite structure. The Composite class represents a group of components and can contain other components, including other composites.

The Composite class maintains a list of child components and provides methods to add and remove components. The operation() method of the composite iterates over its children and calls their respective operation() methods.

In the client code, we create instances of Leaf and Composite classes and add them to each other to form a composite structure. We call the operation() method on the top-level composite, which recursively invokes the operation() method on all the children, regardless of whether they are leaf or composite objects.

The composite pattern allows treating individual objects and compositions of objects uniformly. It enables the creation of complex structures that can be treated as a single entity, simplifying the usage and interaction with hierarchical structures.
*/
