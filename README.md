## Project Espresso
Espresso is a basic yet powerful interpreted language that is highly translatable (because it resembles pseudo-code) making it an excellent choice for anybody looking to rapidly prototype or learn something new.

### Language Details
Espresso is basically a mixture of JavaScript and Python with a hint of C#. It was created to be easy to learn and takes some of the best parts from these languages and mashes them together.

For the Espresso language specification please check the ```doc``` folder or the repository wiki.

### About Releases
Redistributable Windows, OSX, and Linux binaries will be released upon reaching milestones.

### How to Download
Downloads for Espresso can be found on the [releases page](https://github.com/WildAndrewLee/Espresso/releases). To build Espresso from its source and access bleeding-edge features see [Building Espresso](#building-espresso).

### Building Espresso
To build Espresso you must be running a UNIX operating system or [Cygwin](http://www.cygwin.com/) for Windows.

You can build Espresso by running the following:

```
git clone https://github.com/WildAndrewLee/Espresso.git
cd Espresso
make
```

#### Dependencies
- [GCC](http://gcc.gnu.org/)
- [GNU Make](http://www.gnu.org/software/make/)
- [Valgrind (Optional)](http://valgrind.org/)

The built binary will be located in the ```bin``` folder.

### Contributing
If you want to contribute to the project just fork the branch and submit a pull request when you're done.

### Project Contributors
- [Andrew Lee](https://github.com/WildAndrewLee)