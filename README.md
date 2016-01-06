# MbLib

## Vision

These project was built in order to manage audio spatialisation in the audiovisual lab of the School of
Psychology at Cardiff University. Pure Data was chosen because it was open-source but above all able to
manipulate flow data of an old Flock of Bird head tracker off the shelf and has real time capabilities.

What you will find here is far from perfect but is quite generic and can be used outside the purpose of
this specific lab. Please, use it, study it, improve it, share it.

## Language

The development language is English. All comments and documentation should be written in English, so 
that we don't end up with “franglais” methods, and so we can share our learnings with developers around 
the world.


This is the README file for mblib, a library for Pd, a free real-time computer
music software package resembling Max.

Installation instructions can be found in the INSTALL file.
Documentation about the library is provided in the present archive.

ACKNOWLEDGEMENTS. Thanks to all the contributors of Pd.

## Installation

It is necessary to compile a file if you want the staircase method. Otherwise, you can copy the 
folder abs/ into your pdextended/ folder.

### Important note

At the moment the current makefile does not work properly and will be corrected
in the future.

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

## Contributing

We’re really happy to accept contributions from the community, that’s the main reason why we 
open-sourced it! There are many ways to contribute, even if you’re not a technical person.

We’re using the infamous [simplified Github workflow](http://scottchacon.com/2011/08/31/github-flow.html) 
to accept modifications (even internally), basically you’ll have to:

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

You can report issues directly on the gitlab of the project, that would be a really useful 
contribution given that we lack some user testing on the project. Please document as much as possible 
the steps to reproduce your problem (even better with screenshots).

## License

Please report to the LICENSE file included in the project.

## Credits

* Matthieu Berjon
