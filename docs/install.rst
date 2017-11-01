Installation
============

I invite you to use PdExtended rather than the vanilla version of Pure Data. 
For the compilation it won't have any impact (as it uses the same library
pdlib.h) but at least you'll have all the integrated other libraries on which
some abstractions are relying on.

Important note
--------------

At the moment the current makefile does not work properly and will be corrected
really soon.


Setup of the abstractions
-------------------------

At the moment, the abstractions doesn't come in a handy librairy. In order to
set up the system, you will need to give Pure Data the path to the abs folder
in `file/preferences/path`.

Compilation of the external
---------------------------

Linux
^^^^^

In order to compile and install this library you will need:

* gcc >= 4.7.1
* gnu-make >= 3.82
* Pure Data >= 0.45

To compile the library:

  make
  make install

All file will be added to you default Pure Data external folder ~/pdextended.

Windows
^^^^^^^

In order to compile under windows, you will need:

* Mingw 
* Pure Data >= 0.45

To compile the library:

  mingw32-make
  mingw32-make install

All files will be install for the current user in %%application_data%%

MacOs
^^^^^

The Makefile does'nt take into account MacOs compilation at the moment.

Installation of abstraction
License
-------

Please refer to the LICENSE file at the root of the project.

Contributing
------------

We’re really happy to accept contributions from the community, that’s the main
reason why we open-sourced it! There are many ways to contribute, even if
you’re not a technical person.

We’re using the infamous `simplified Github workflow`_ to accept modifications
(even internally), basically you’ll have to:

* create an issue related to the problem you want to fix (good for traceability
  and cross-reference)
* fork the repository
* create a branch (optionally with the reference to the issue in the name)
* hack hack hack
* commit incrementally with readable and detailed commit messages
* submit a pull-request against the master branch of this repository

We’ll take care of tagging your issue with the appropriated labels and answer
within a week (hopefully less!) to the problem you encounter.

If you’re not familiar with open-source workflows or our set of technologies,
do not hesitate to ask for help! We can mentor you or propose good first bugs
(as labeled in our issues). Also welcome to add your name to Credits section of
this document.

Submitting bugs
---------------

You can report issues the issue tracker of the `project`_, that would be a
really useful contribution given that we lack some user testing on the project.
Please document as much as possible the steps to reproduce your problem 
(even better with screenshots).


.. _simplified Github workflow: http://scottchacon.com/2011/08/31/github-flow.html
.. _project: https://github.com/mattberjon/mblib/issues
