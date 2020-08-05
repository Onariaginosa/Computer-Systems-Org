**CMSI 284** Computer System Organization/Systems Programming, Spring 2020

# Assignment 0225
Our last set of encoding drills focuses on characters and simple computer instructions, in addition to some reinforcement of the integer material.

## Background Reading
Pretty much all of the information you need can be found in Dr. Toal’s [Character Encoding](http://cs.lmu.edu/~ray/notes/charenc) and [Simple Computer](http://cs.lmu.edu/~ray/notes/simplecomputer) pages, as well as many other sites on the web (for character encoding). The simple computer is Dr. Toal’s own (but also strongly resembles Tom Scott’s example computer in [The Fetch-Execute Cycle: What’s Your Computer Actually Doing?](https://youtu.be/Z5JC9Ve1sfI)).

## For Submission: Encoding Exercises
You are meant to do all these problems _without_ the aid of a computer. The purpose of these exercises is for you to develop skills. If you spend the time to practice with pencil and paper (or a whiteboard) you will learn the material much better. For these exercises, you won’t even need a calculator (well, except possibly for the review portion).

### Acquiring Your Exercises
In its initial state, your encoding assignment repository contains:
- A sample set of exercises
- A sample set of handwritten solutions to these exercises
- A sample _solution file_, formatted for automated (initial) scoring

These examples are meant to illustrate how your _actual_ set of exercises and final submissions should look, in terms of format and content.

Upon acquiring this repository, open a GitHub issue that mentions either Dondi (**@dondi**) or Alexia Filler (**@afiller1**) in order to request your personal, individualized set of exercises. Either one of them will deposit the exercises in your repository and resolve the issue once this is done. At that point, you can start working in earnest.

### Adhering to the Submission Format
To facilitate a level of automation in scoring, the exercise file is in a very specific tab-delimited (TSV) format. Copy the exercise file into a new one called _solutions.tsv_ then fill in the requested answers (indicated by the question marks). You may ignore blank tabs/columns that don’t have a question mark. Commit _solutions.tsv_ as often as you see fit.

When formatting your IEEE 754 answers:
- Separate 32- and 64-bit hexadecimal into bytes
- Add leading zeroes to 32- and 64-bit hexadecimal values _only_
- Do not use spaces in the binary portion of the “binary scientific notation” format
- Write the multiplication operator `x` and the power of 2 exactly as shown
- Preserve all parts of the “binary scientific notation” expression, even if its value is 1.0 (and write it that way if so!)
- For decimal answers that are integers, include one trailing zero after the decimal point (e.g., 42.0)
- For decimal answers with magnitude < 1, include one leading zero before the decimal point (e.g., -0.25)

When formatting your character answers:
- Adhere to the byte count specified by the relevant encoding scheme
- For glyphs, type in the character itself (or copy/paste from an appropriate web page)
- Write codepoints as `U+????` if the codepoint is less than or equal to `FFFF` and `U+?????` otherwise
- Write encodings as shown in the sample: no spaces for UTF-32, spaces between 16 bits for UTF-16, spaces between 8 bits for UTF-8
- Use big-endian for UTF-32 and UTF-16

When formatting your simple computer answers:
- Write machine instructions as contiguous 32 bits without spaces
- Write assembly language instructions with one space between the mnemonic and the operand

_Do not veer from the format specified by the TSV file:_ Discrepancies in formatting may confuse the autoscoring script and will confuse, frustrate, or exasperate its human counterparts.

**Protip:** An effective way to work with your file is to import _solutions.tsv_ into a spreadsheet program such as Excel or Google Sheets. Work on the exercises by hand, fill in your answers, then export back to a TSV for submission. Do make sure that the spreadsheet applications do not interfere with your intended answers, especially leading zeroes. You are responsible for making sure that your submission corrects for “spreadsheet interference.”

**Pro-protip:** Because these files use characters that span the entire Unicode character set, remember to import them as UTF-8 when given the option.

### Providing Manual Work
It has been stated that you are to work on these exercises _without_ the aid of a computer. To provide evidence that you have done this, take pictures of your manual work (as shown in this repository’s example) and submit those as well. This manual work not only shows that you did these exercises by hand but also provides a basis for partial credit, if necessary.
- File formats for your manual work are now restricted to JPEG, PNG, or PDF only
- Name your files _manual-x_ where _x_ is a number indicating the correct sequence for your work (i.e., don’t mix things up—it makes things harder to find). So you should have files named _manual-1.jpg_, _manual-1.png_, _manual-2.pdf_, etc. only. A single multipage _manual.pdf_ is permitted as long as the pages are in the proper order.

Diverging from any of these specifications will incur a general deduction on top of the overall score.

Here’s another way to think about your submission: _Your submitted files should be named almost exactly like the files in this repository, except without the prefix **sample-**._

## How to Turn it In
Commit your _solutions.tsv_ file and pictures of your manual work to this repository.

## Specific Point Allocations
This encoding assignment is scored according to outcomes _1a_ to _1c_ and _4d_ to _4f_ in the [syllabus](https://dondi.lmu.build/spring2020/cmsi284/cmsi284-spring2020-syllabus.pdf). For this particular assignment, graded categories are as follows:

| Category | Points | Outcomes |
| -------- | -----: | -------- |
| IEEE 754 conversions | 5 points each, 15 points total | _1a_, _4d_ |
| Character conversions | 3 points each, 60 points total | _1b_, _4d_ |
| Simple computer conversions | 5 points each, 25 points total | _1c_, _4d_ |
| Missing/incomplete/off-spec manual work | deduction only | |
| Version Control | deduction only | _4e_ |
| Punctuality | deduction only | _4f_ |
| **Total** | **100** |

The 3- and 5-point values in the respective conversions allow for partial credit.
