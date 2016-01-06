# MbLib

This project has been developed within the Action and Perception group of the school of
Psychology at Cardiff University. A new audiovisual lab has been created and needed a bit
of code in order to be able to use properly the equipments. [Pure Data][1] has been chosen for
several reasons:

* able to drive an old Flock of Bird head tracker out of the box
* Real time capacities
* Run on Windows, GNU/Linux and MacOsX
* Open source software

You'll find several abstractions to manipulate and acquire data from the head tracker, basic
filtering, spatialisation, a staircase method and so on. All the objects are supposed to be
as generic as possible and should be usable outside of its main purpose in the lab.

Please, download it, study it, improve it and share it!

## Installation

### Important note

At the moment the current makefile does not work properly and will be corrected
reallt soon.

### Linux

In order to compile and install this library you will need:

* gcc >= 4.7.1
* gnu-make >= 3.82
* Pure Data >= 0.45

To compile the library:

~~~.{bash}
make
make install
~~~

All file will be added to you default Pure Data external folder ~/pdextended.

### Windows

In order to compile under windows, you will need:

* Mingw 
* Pure Data >= 0.45

To compile the library:

~~~.{bash}
mingw32-make
mingw32-make install
~~~

All files will be install for the current user in %%application_data%%


### MacOs

The Makefile does'nt take into account MacOs compilation at the moment.


## License

Please refer to the LICENSE file at the root of the project.

## Contributing

We’re really happy to accept contributions from the community, that’s the main reason why 
we open-sourced it! There are many ways to contribute, even if you’re not a technical person.

We’re using the infamous [simplified Github workflow][2] to accept modifications (even internally), 
basically you’ll have to:

* create an issue related to the problem you want to fix (good for traceability and cross-reference)
* fork the repository
* create a branch (optionally with the reference to the issue in the name)
* hack hack hack
* commit incrementally with readable and detailed commit messages
* submit a pull-request against the master branch of this repository

We’ll take care of tagging your issue with the appropriated labels and answer within a week 
(hopefully less!) to the problem you encounter.

If you’re not familiar with open-source workflows or our set of technologies, do not hesitate to ask 
for help! We can mentor you or propose good first bugs (as labeled in our issues). Also welcome to 
add your name to Credits section of this document.


### Submitting bugs

You can report issues the issue tracker of the [project][4], that would be a really useful contribution given that we lack 
some user testing on the project. Please document as much as possible the steps to reproduce your problem 
(even better with screenshots).


## Credits

* [Matthieu Berjon][1]
* All the contributors of Pure Data



[1]: https://puredata.info/
[2]: http://scottchacon.com/2011/08/31/github-flow.html
[3]: https://berjon.net/matt
[4]: https://berjon.net/projects/mblib