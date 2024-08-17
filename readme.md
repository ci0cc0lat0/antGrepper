# antgrep
`antgrep` is a tool meant to recursivly search through a directory and subdirectories for a given file extension. These files are meant to be ran and installed as a binary to run correctly.

## Install
From github, once cloned, unzipped or however you install the source files, in the root directory linux run these commands:

`sudo apt-get update && sudo apt-get install build-essential` - Optional as this was needed for me on a fresh linux install

`mkdir build`

`cd build`

`cmake ..`

`make`

`sudo make install`


## Use
The last command will install `antgrep` as a binary to be used like so:

`antgrep -h`                    - for help

`antgrep <path> <extension>`    - for general use

`antgrep -p <path> <extension>` - to print the output into an out file

`antgrep -w <path> <extension>` - to print just the files
