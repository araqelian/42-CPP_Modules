# 🗣 Description &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;modules

<br>

<p>
  The goal of these modules is to introduce you to Object-Oriented Programming. This will be the starting point of your C++ journey. 
  Many languages are recommended to learn OOP. We decided to choose C++ since it’s derived from your old friend C. 
  Because this is a complex language, and in order to keep things simple, your code will comply with the C++98 standard.
  We are aware modern C++ is way different in a lot of aspects.
</p>

<br>

## General rules

<b>Compiling</b>

<ul>
  <li>Compile your code with <b>c++</b> and the flags <b>-Wall -Wextra -Werror</b></li>
  <li>Your code should still compile if you add the flag <b>-std=c++98</b></li>
</ul>

<b>Formatting and naming conventions</b>

<ul>
  <li>The exercise directories will be named this way: ex00, ex01, ...</li>
  <li>Name your files, classes, functions, member functions and attributes as required in the guidelines</li>
  <li>Write class names in <b>UpperCamelCase</b> format. Files containing class code will
      always be named according to the class name. For instance:
      <b>ClassName.hpp/ClassName.h</b>, <b>ClassName.cpp</b>, or <b>ClassName.tpp</b>. Then, if you
      have a header file containing the definition of a class "<b>BrickWall</b>" standing for a
      brick wall, its name will be <b>BrickWall.hpp</b></li>
  <li>Unless specified otherwise, every output messages must be ended by a new-line character and displayed to the standard outpu</li>
</ul>

<b>Allowed/Forbidden</b>

<ul>
  <li>You are allowed to use almost everything from the standard library. Thus, instead
      of sticking to what you already know, it would be smart to use as much as possible
      the C++-ish versions of the C functions you are used to</li>
  <li>However, you can’t use any other external library. It means <b>C++11</b> (and derived
      forms) and <b>Boost</b> libraries are forbidden. The following functions are forbidden
      too: <b>*printf()</b>, <b>*alloc()</b> and <b>free()</b></li>
  <li>Note that unless explicitly stated otherwise, the <b>using namespace "ns_name"</b> and <b>friend</b> keywords are forbidden</li>
  <li>You are allowed to use the <b>STL</b> in the <b>Module 08</b> and <b>Module 09</b> only. That means:
      no <b>Containers (vector/list/map/and so forth)</b> and no <b>Algorithms (anything that
      requires to include the "algorithm" header)</b> until then</li>
</ul>

<b>A few design requirements</b>

<ul>
  <li>Memory leakage occurs in C++ too. When you allocate memory (by using the <b>new</b> keyword), you must avoid <b>memory leaks</b></li>
  <li>From Module 02 to Module 09, your classes must be designed in the <b>Orthodox Canonical Form, except when explicitely stated otherwise</b></li>
</ul>

<br><br><br>

## Module 00

<p>
  <b>Description</b> <br><br>
  This first module of C++ is designed to help you understand the specifities of the language when compared to C. Time to dive into Object Oriented Programming! <br>
</p>
<ul>
  <li>Namespace</li>
  <li>Classes</li>
  <li>Member functions</li>
  <li>Stdio streams</li>
  <li>Initialization lists</li>
  <li>Static</li>
  <li>Const</li>
</ul>

<br>

## Module 01

<p>
  <b>Description</b> <br><br>
  This module is designed to help you understand the memory allocation, reference, pointers to members and the usage of the switch in CPP. <br>
</p>

<ul>
  <li>Memory allocation</li>
  <li>Pointers to members</li>
  <li>References</li>
  <li>Switch statement</li>
</ul>

<br>

## Module 02

<p>
  <b>Description</b> <br><br>
  This module is designed to help you understand Ad-hoc polymorphism, overloads and orthodox canonical classes in CPP. <br>
</p>

<ul>
  <li>Ad-hoc polymorphism</li>
  <li>Operator overloading and Orthodox Canonical class form</li>
</ul>

<br>

## Module 03

<p>
  <b>Description</b> <br><br>
  This module is designed to help you understand Inheritance in CPP. <br>
</p>

<ul>
  <li>Inheritance</li>
</ul>

<br>

## Module 04

<p>
  <b>Description</b> <br><br>
  This module is designed to help you understand Subtype polymorphism, abstract classes and interfaces in CPP. <br>
</p>

<ul>
  <li>Subtype polymorphism</li>
  <li>Abstract classes</li>
  <li>Interfaces</li>
</ul>

<br>

## Module 05

<p>
  <b>Description</b> <br><br>
  This module is designed to help you understand Try/Catch and Exceptions in CPP. <br>
</p>

<ul>
  <li>Repetition and Exceptions</li>
</ul>

<br>

## Module 06

<p>
  <b>Description</b> <br><br>
  This module is designed to help you understand the different casts in CPP. <br>
</p>

<ul>
  <li>C++ casts</li>
</ul>

<br>

## Module 07

<p>
  <b>Description</b> <br><br>
  This module is designed to help you understand Templates in CPP. <br>
</p>

<ul>
  <li>C++ templates</li>
</ul>

<br>

## Module 08

<p>
  <b>Description</b> <br><br>
  This module is designed to help you understand templated containers, iterators and algorithms in CPP. <br>
</p>

<ul>
  <li>Templated containers</li>
  <li>Iterators</li>
  <li>Algorithms</li>
</ul>

<br>

## Module 09

<p>
  <b>Description</b> <br><br>
  This module is designed to help you understand the containers in CPP. <br>
</p>

<ul>
  <li>STL</li>
</ul>
