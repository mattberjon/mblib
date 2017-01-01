Pd-motion
=========

This project (formely mblib) has been developed within the Action and
Perception group of the school of Psychology at Cardiff University. A new
audiovisual lab has been created and needed a bit of code in order to be able
to use properly the equipments. `Pure Data`_ has been chosen for several
reasons:

* able to drive an old Flock of Bird head tracker out of the box
* Real time capacities
* Run on Windows, GNU/Linux and MacOsX
* Open source software

You'll find several abstractions to manipulate and acquire data from the head
tracker, basic filtering, spatialisation, a staircase method and so on. All the
objects are supposed to be as generic as possible and should be usable outside
of its main purpose in the lab.

Please, download it, study it, improve it and share it!

Installation
------------

Important note
^^^^^^^^^^^^^^

At the moment the current makefile does not work properly and will be corrected
really soon.

Linux
^^^^^

In order to compile and install this library you will need:

- gcc >= 4.7.1
- gnu-make >= 3.82
- Pure Data >= 0.45

To compile the library:

  make
  make install

All file will be added to you default Pure Data external folder ~/pdextended.

Windows
^^^^^^^

In order to compile under windows, you will need:

- Mingw 
- Pure Data >= 0.45

To compile the library:

  mingw32-make
  mingw32-make install

All files will be install for the current user in `%%application_data%%`.


MacOs
^^^^^

The Makefile does'nt take into account MacOs compilation at the moment.


License
-------

Please refer to the `LICENSE` file at the root of the project.

Contributing
------------

I'm happy to welcome any contributions as long as they fit some requirements
that you can read on the `CONTRIBUTING.md`.

Credits
-------

* `Matthieu Berjon`_
* All the contributors of Pure Data



.. _Pure Data: https://puredata.info/
.. _Matthieu Berjon: https://berjon.net
