##Introduction

Instant War is a Haxe and Openfl-based engine for running hex-based war games.  The engine relies on XML files to load game maps, counters, and various scenarios.  Maps are hexed, meaning that movement can proceed in six directions, as has been the standard in traditional war games for several decades.  I created IW initially to recreate many of the aspects of these old war games, though I am planning on expanding in a number of different directions.  The key here is simplicity: IW games are meant to play like board-based war games, not like the more complex computer games that emerged in the 1980s, or the real-time strategy games that emerged in the 1990s.  The engine is also built to accomodate new games and scenarios quite easily.  I want to build a war game library out of this.

Instant War is also unusual in that it employs a command-line interface.  All game options, from starting a new game to save and loading a game in play, to quitting IW entirely, are handed by typing commands into the console at the bottom of the window.  As with everything else about IW, the console is meant to keep things simple.  Rather than relying on a series of dialog and message boxes to handle various game commands, the console does it all.  This will also make it easier to add new commands in the future, if need be.

This repository will contain the Instant War engine, along with an indeterminate number of assets and scenarios.  The plan for now is this: specific Instant War releases, such as the first one, Tank Battles I, will be downloadable as binaries below, while all source code, and all assets, will be made available in a single pool in the repository.  I will try to keep this up as much as I can, but I will split off into new repositories if need be.

##Download & Run

This repository does not contain the node-webkit files necessary to run Hail Workshop.  Please click on the following links to download usable versions of the program that contain all necessary files for the given OS.  Note that source files can be executed without compilation.  See below for instructions.

* **v0.2.2** (Sept. 30, 2014):

  * Windows: [zip](http://semioticblocks.com/downloads/hail-workshop.zip) (source files) / [msi](http://semioticblocks.com/downloads/HailWorkshop.msi) (installer)
  * Linux: [tar.gz](http://semioticblocks.com/downloads/hail-workshop.tar.gz) (source files)
  * Mac OS X: [zip](http://semioticblocks.com/downloads/Hail-Workshop.app.zip) (app folder/file)

To run from zip file on Windows, unzip hail-workshop.zip.  Contents will be copied into _hail-workshop_ folder.  Inside folder, click _Hail-Workshop_ link.

To run from tar.gz file on Linux, extract files from archive.  Contents will be copied into _hail-workshop_ folder.  From the _parent_ folder, type `./gohail`

When you start your first session of Hail Workshop, it will look something like this:

![http://i.imgur.com/hdD1FWi.png?1](http://i.imgur.com/hdD1FWi.png?1)

##Documentation
Visit Hail Workshop's [wiki](https://github.com/Adaax/hail-workshop/wiki) to learn about the Hail language and Workshop environment.

##License
Hail Workshop and its source code are licensed under the MIT License.
