.. MbLib documentation master file, created by
   sphinx-quickstart on Sat Dec 31 17:26:57 2016.
   You can adapt this file completely to your liking, but it should at least
   contain the root `toctree` directive.

Welcome to MbLib
================

MbLib is a set of abstractions for `Pure Data`_ that helps to manipulate the
spatialisation of audio streams and handle head tracking data coming from a
Flock of Bird.

This project has been developed within the Action and Perception group of the
school of Psychology at Cardiff University. A new audiovisual lab has been
created and needed a bit of code in order to be able to use properly the
equipments. Pure Data has been chosen for several reasons:

* able to drive an old Flock of Bird head tracker out of the box
* Real time capacities
* Run on Windows, GNU/Linux and MacOsX
* Open source software

You'll find several abstractions to manipulate and acquire data from the head
tracker, basic filtering, spatialisation, a staircase method and so on. All the
objects are supposed to be as generic as possible and should be usable outside
of its main purpose in the lab.

Please, download it, study it, improve it and share it!

.. toctree::
   :maxdepth: 2

   install
   abs

.. _Pure Data: http://puredata.info
