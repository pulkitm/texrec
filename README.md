# Texrec
A program that performs text recognition from image.

### Features 
* Extract text from image and display it on screen.
* Write the recognized text to a file.
* Make a text recognizable pdf from image.

### Tech details
* Language - C++
* Library - Tesseract (An OCR engine by Google)

### Setup
* You need to install tesseract to run this program. For installation instruction refer [this.](https://tesseract-ocr.github.io/tessdoc/Home.html)
* Clone repository 
* Compile texrec.cpp with following flags : `g++ -o texrec texrec.cpp -ltesseract -llept`

* Run texrec
