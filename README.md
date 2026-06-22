# Deterministic_Math
Deterministic C++ math library 2D &amp; 3D

# AI Warning
The over-arching architecture is designed by me. This was written before I knew Linear Algebra, so a certain amount of this code was AI assisted. 
For your projects, you're writing your own code, so you'll own your game. Since this library is MIT Licensed, it doesn't matter that you can't copyright this because ONLY the AI generated components of this library are not copyrightable. 
TL;DR
You don't have to worry.*
*Not legal advice. Cross reference a lawyer. 

# Use Case
This is useful for deterministic playback & re-simulation. If you have a cross platform game, floating point numbers will be inconsistent accross platforms, architectures, OS, etc. This is integer based & uses standard Integer libraries. 

Use this library for your linear algebra needs in:
1. Playing back a game demo of events. 
2. Rollback multiplayer synchronization where inputs must be re-calculated for a deterministic output for PvP games where stakes matter. IE E-Sports
3. Vital technology testing. If you NEED to find out why something is going wrong, you don't want it to be inconsistent with floating point values. Get the same result every time so you can identify and fix the problem.

# How to use
`#include "DMath/DeterministicMath.h` to get the basic structures. Using 3D as an example, you would normally use floating vectors for rendering in Open GL, etc. We have `DVector3Df` for this accomodation. 
All of your physics calculations can be done with say `DVector3Di16` for a 300~ metre area of operation. The library is in Centimetres for distance & Minutes for rotations, however degrees are available. 

You can spend your time simply working in Euler space using degrees & centimetres. 

This is a header-like library. I do have .cpp files, but as long as you plop it in your project, you should have zero issues. I have used it thusfar with Visual Studio C++, and either Clang or G++, I don't know what I am using on Linux. 

# Pull Requests
If you want to contribute to the library, I will incorporate changes. If you PR is complicated, please explain what algorithms you're using in your PR, or other complicated things. 
I'm not a Linear Algebra expert. 

Everything MUST be cross platform compatible, so please limit yourself to std libraries. You're more than welcome to use the lastest C++ features. My personal projects are in C++ 20 or higher. There's no downside to using the latest C++ features if you're not doing it to intellectually pleasuring yourself. Keep it easy to read, so my small mind can comprehend. 

# Problems
Yes, some of the naming schemes are a bit inconsistent. I wrote the initial library for Godot using the Godot naming schemes, but have since adapted the library for generic C++ custom technology. Some Godot technology still exists & I have some more things for Godot. I may at some point add a Godot branch for use with Godot. 
