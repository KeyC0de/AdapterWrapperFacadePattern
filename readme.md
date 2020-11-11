# Readme

A confused pattern.

It has many names.
Adapter, Facade, Wrapper.
But they're all the same..

Basically the Adapter (aka Facade aka Wrapper class) wraps a legacy class with a new interface into an updated class that respects the new interface.

For example:
The old class contains draw(), the interface also declares draw() then the Adapter/Facade/Wrapper class inherits from the legacy class and implements the interface. So it implements the interface's draw(). It sets up the draw as it is required and calls the legacy::draw() method with the proper parameters passed.


