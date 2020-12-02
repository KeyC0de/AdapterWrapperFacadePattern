<h1 align="center">
	<a href="https://github.com/KeyC0de/ArchaicBrowser">Adapter - Wrapper - Facade Pattern</a>
</h1>
<hr>

Here we will disambiguate the Adapter Wrapper Facade Software Design patterns.

A confused pattern, yes.</br>
It has many names.</br>
Adapter, Facade, Wrapper.</br>
But they're all pretty much the same..</br>

Basically the Adapter (aka Facade aka Wrapper class) wraps a legacy class with a new interface into an updated class that respects the new interface. It is often used to make existing classes work with others without modifying their source code. Windows functions are an example of this.

**Design**

- an interface (perhaps legacy) is not compatible with the current systems needs
- an abstract base class is created that specifies the desired interface
- an adapter class is defined that publicly inherits the interface of the abstract class, and privately inherits the implementation of the legacy class
- this adapter class "(impedance) matches" the new interface to the old implementation.

Subtle differences:
These patterns are basically all the same thing, but there can be subtle differences on context (and personally confusion in the programming community causes them). They differ mostly on where they often tend to be used:

- `Facade`s are typically a wrapper for a subsystem of one or more classes. Making changes to that set of objects is confusing, because you don't always know which object has the method you need to call. That's the time to write a `Facade` that provides high-level methods for all the complex operations you can do to the collection of objects.
- Adapter is exactly what is said above.
- A Wrapper can be anything of those 3

In our example the old class contains draw(), the interface also declares draw() then the Adapter/Facade/Wrapper class inherits from the legacy class and implements the interface. So it implements the interface's draw(). It sets up the draw as it is required and calls the legacy::draw() method with the proper parameters passed.

I used Windows 8.1 x86_64, Visual Studio 2017, C++17 to build the project.


# Contribute

Please submit any bugs you find through GitHub repository 'Issues' page with details describing how to replicate the problem. If you liked it or you learned something new give it a star, clone it, contribute to it whatever. Enjoy.


# License

Distributed under the GNU GPL V3 License. See "GNU GPL license.txt" for more information.


# Contact

email: *nik.lazkey@gmail.com*</br>
website: *www.keyc0de.net*
