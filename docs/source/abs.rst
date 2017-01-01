Abstraction and externals documentation
=======================================

Abstractions
------------

Audio
^^^^^

**audio-stim**
  Generate audio stimulus properties.

**bandpass~**
  Band-pass filter with a bypass option.

**bandpass24~**
  24 channels band-pass filter with a bypass option. (Requires bandpass~).

**fadeio~**
  Fade in/out manager.

**gaussian-gain**
  Compute the gain to apply to a speaker depending of the source size.

**gaussian-spat24**
  Compute the gains to apply to a 24 channels sound system according to the 
  position of the speakers and the source width. (Requires gaussian-gain).

**master24~**
  24 channels master with a fade in/out manager. (Requires fadeio).

**motion24~**
  Spatialize an incoherent stimulus (noise for example) over 24 channels.
  (Requires gaussian-spat24).

**mute24~**
  24 audio channels mute.

**noise24~**
  24 audio channels of white noise. Each channel generate independent noise (useful
  to simulate source motion).

**partconv-im~**
  1 channel filtering object using partitionned convolution method. This object
  can be bypass. (Requires partconv~).

**playfile~**
  Play any wave file in argument using a table method.

**spectral-corr24~**
  24 audio channels applying spectral filtering on input signals. This object 
  can be bypass if necessary. (Requires partconv-im~).

**stimulus-position**
  Generate the azimuth position stream according to several parameters.

**vumeter~**
  GUI object displaying the level in dBfs (full scale) of an audio signal.

Head tracking (Flock of Bird)
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

**bird-conv-ang**
  Conversion of an angular Flock of Bird raw data flow in azimuth, elevation and
  roll in degrees.

**bird-conv-pos**
  Conversion of a position Flock of Bird raw data flow in x, y and z in inches
  or centimeters.

**bird-ctl**
  Flock of Bird acquisition control features.

**bird-raw-pos-ang**
  Flock of Bird raw flow extraction. Output two separate raw flows, one for
  position, one for angles.

Miscellaneous
^^^^^^^^^^^^^

**cmp-gate**
  Comparative gate using 2 boundaries.

**get-button**
  Send a unique bang when the right key is hit.

**get-displacement**
  Get the displacement according to the duration and speed of an object.

**in2cm**
  Convert inches in centimeters.

**percentage**
  Compute a given percentage of a value.

**pr-bit**
  Generate a pseudo random bit (0 or 1) and then alternate the value.

**rand**
  A superior layer of random object. You just to specify a range of value from
  0 and shift of this range.

**serial-ctl**
  Superior layer to comport in order to open/close, specify a baud rate for the
  serial port.

Externals
---------

**staircase**
  Staircase method.
