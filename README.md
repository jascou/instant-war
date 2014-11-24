##Introduction

Instant War is a Haxe and Openfl-based engine for running hex-based war games.  The engine relies on XML files to load game maps, counters, and various scenarios.  Maps are hexed, meaning that movement can proceed in six directions, as has been the standard in traditional war games for several decades.  I created IW initially to recreate many of the aspects of these old war games, though I am planning on expanding in a number of different directions.  The key here is simplicity: IW games are meant to play like board-based war games, not like the more complex computer games that emerged in the 1980s, or the real-time strategy games that emerged in the 1990s.  The engine is also built to accomodate new games and scenarios quite easily.  I want to build a war game library out of this.

Instant War is also unusual in that it employs a command-line interface.  All game options, from starting a new game to save and loading a game in play, to quitting IW entirely, are handed by typing commands into the console at the bottom of the window.  As with everything else about IW, the console is meant to keep things simple.  Rather than relying on a series of dialog and message boxes to handle various game commands, the console does it all.  This will also make it easier to add new commands in the future, if need be.

This repository will contain the Instant War engine, along with an indeterminate number of assets and scenarios.  The plan for now is this: specific Instant War releases, such as the first one, Tank Battles I, will be downloadable as binaries below, while all source code, and all assets, will be made available in a single pool in the repository.  I will try to keep this up as much as I can, but I will split off into new repositories if need be.

##Download & Run

###Instant War: Tank Battles I

This is the first Instant War release, and will, when completed, consist of 10 scenarios set in the fictional Third Colonies.  More information may be found in the documentation (see below).

* **alpha** (Nov. 23, 2014):

  * Windows: [msi](http://semioticblocks.com/downloads/InstantWarTankBattlesI.msi) (installer)
  * Mac OS X: [zip](http://semioticblocks.com/downloads/IW-TB1.app.zip) (app folder/file)

When you start TB1, it will look something like this:

![Imgur](http://i.imgur.com/dTRgPNv.png?1)

##Documentation

* **Instant War: Tank Battles I** rules: [pdf](http://semioticblocks.com/downloads/Instant War TB1 - Rules.pdf)

##License
Instant War and its source code are licensed under the MIT License.
