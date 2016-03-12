# C11-threads

The C language didn't have multi-threading features until C11. Since C11, the language has a multi-threading support as part of its standard library.

The threading APIs are almost identical to POSIX threads except some minor improvements in error handling, APIs and with slightly different API names.

This repository contains a set of (minimal) examples for all C11 threading APIs. The aim is to provide a concise example of the "usage" of those APIs.
That means, the sample programs do not have solve any real problems but manufactured ones to demonstrate how to use a specific function.

I am using C11 standard as a reference to create these examples, which doesn't describe semantics well. So in the absense of any defined behaviour
or unambiguity in C11 APIs, I follow their POSIX counterpart's semantics.
