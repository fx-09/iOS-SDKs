# iOS-SDKs
A collection of iOS SDKs. Please target ```iphone:clang:16.x:15.0``` (you can choose x for yourself, 16.4 is recommended) for your tweak Makefile, thus avoiding compiling errors.

Required [theos](https://github.com/theos/theos).

While [theos-jailed](https://github.com/qnblackcat/theos-jailed) is not required, I highly suggest acquiring it.


## Setup 
The guide assumes you already setup ```theos``` and perhaps, ```brew```.
1. Download this as a .zip file.
2. Navigate to ```$THEOS/sdks```.
3. Unzip all the SDKs into above folder.
Make sure to edit your project's ```Makefile``` properly to avoid compilling errors.