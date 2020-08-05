**CMSI 284** Computer System Organization/Systems Programming, Spring 2020

# Assignment 0130
This first set of encoding drills is all about integers and our most significant bases: 10, 2, 8, and 16.

## Background Reading
Pretty much all of the information you need can be found in Dr. Toal’s [Numeric Encoding page](http://cs.lmu.edu/~ray/notes/numenc/), as well as many other sites on the web—it isn’t like numeric encoding differs from person to person! As mentioned in class, the core information is pretty straightforward; the trick is doing it enough so that it feels intuitive and second-nature.

## For Submission: Encoding Exercises
You are meant to do all these problems _without_ the aid of a computer. The purpose of these exercises is for you to develop skills. If you spend the time to practice with pencil and paper (or a whiteboard) you will learn the material much better. You may use a calculator to help with arithmetic, but that’s it.

### Acquiring Your Exercises
In its initial state, your encoding assignment repository contains:
- A sample set of exercises
- A sample set of handwritten solutions to these exercises
- A sample _solution file_, formatted for automated (initial) scoring

These examples are meant to illustrate how your _actual_ set of exercises and final submissions should look, in terms of format and content.

Upon acquiring this repository, open a GitHub issue that mentions either Dondi (**@dondi**) or Alexia Filler (**@afiller1**) in order to request your personal, individualized set of exercises. Either one of them will deposit the exercises in your repository and resolve the issue once this is done. At that point, you can start working in earnest.

### Adhering to the Submission Format
To facilitate a level of automation in scoring, the exercise file is in a very specific tab-delimited (TSV) format. Copy the exercise file into a new one called _solutions.tsv_ then fill in the requested answers (indicated by the question marks). You may ignore blank tabs/columns that don’t have a question mark. Commit _solutions.tsv_ as often as you see fit.

When formatting your answers:
- Add leading zeroes up to the stated bit width of the number _for bases that are powers of 2 only_
- Do not use punctuation (commas)
- Use spaces _only in binary_ (i.e., four bits at a time)

_Do not veer from the format specified by the TSV file:_ Discrepancies in formatting may confuse the autoscoring script and will confuse, frustrate, or exasperate its human counterparts.

**Protip:** An effective way to work with your file is to import _solutions.tsv_ into a spreadsheet program such as Excel or Google Sheets. Work on the exercises by hand, fill in your answers, then export back to a TSV for submission.

### Providing Manual Work
It has been stated that you are to work on these exercises _without_ the aid of a computer. To provide evidence that you have done this, take pictures of your manual work (as shown in this repository’s example) and submit those as well. This manual work not only shows that you did these exercises by hand but also provides a basis for partial credit, if necessary.
- File formats for your manual work are now restricted to JPEG, PNG, or PDF only
- Name your files _manual-x_ where _x_ is a number indicating the correct sequence for your work (i.e., don’t mix things up—it makes things harder to find). So you should have files named _manual-1.jpg_, _manual-1.png_, _manual-2.pdf_, etc. only.

Diverging from any of these specifications will incur a general deduction on top of the overall score.

Here’s another way to think about your submission: _Your submitted files should be named almost exactly like the files in this repository, except without the prefix **sample-**._

## How to Turn it In
Commit your _solutions.tsv_ file and pictures of your manual work to this repository.

## Specific Point Allocations
This encoding assignment is scored according to outcomes _1a_ and _4d_ to _4f_ in the [syllabus](https://dondi.lmu.build/spring2020/cmsi284/cmsi284-spring2020-syllabus.pdf). For this particular assignment, graded categories are as follows:

| Category | Points | Outcomes |
| -------- | -----: | -------- |
| Encoding conversions | 3 points each, 60 points total | _1a_, _4d_ |
| Integer arithmetic | 5 points each, 40 points total | _1a_, _4d_ |
| Missing/incomplete manual work | deduction only | |
| Version Control | deduction only | _4e_ |
| Punctuality | deduction only | _4f_ |
| **Total** | **100** |

The 3 points in the encoding conversions will allow for partial credit. For integer arithmetic exercises, 1 point goes to the saturated sum, 2 points go to the modular sum, 1 point to carry, and 1 point to overflow.
