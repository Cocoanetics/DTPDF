About DTPDF
===========

On Mac you have two built-in methods of working with PDFs, CGPDF on the CoreFoundation level or PDFDocument which is basically a wrapper around CGPDF. The second adds a few features for Mac like getting the text on certain pages as well as some editing functionality.

DTPDF enhances CGPDF (which also exists on iOS) with a Objective-C wrapper that is aimed to provide some convenience methods similar to PDFDocument.

The plan for this is to gain functionality similar to PDFDocument in DTPDFDocument. And also to be able to retrieve the text positions on PDF pages to allow for reconstructing "text boxes" or even allow for selection.

The current version is able to extract text and roughly sort it by its position on the page. But it falls short with fonts that have a lookup table as opposed to normal UTF8 characters. If you'd like to collaborate on this feel free to contact me.

Follow @cocoanetics on Twitter or app.net.

License
------- 
 
It is open source and covered by a standard BSD license. That means you have to mention *Cocoanetics* as the original author of this code. You can purchase a Non-Attribution-License from us.

Setup
-----

The best way to use DTPDF is to add it in Xcode as a subproject of your project with the following steps.

1. Make DTPDF a git submodule of your project

   `git submodule add https://github.com/Cocoanetics/DTPDF.git Externals/DTPDF`
	
2. DTPDF for Mac classes from DTFoundation which is set up as a git submodule in Externals/DTFoundation, so you need to get these files as well

   `git submodule update --init --recursive`

3. Open the destination project and create an "Externals" group.

4. Add files… or drag `DTPDF.xcodeproj` to the Externals group

5. If you build for Mac add files… or drag `DTFoundation.xcodeproj` from DTPDF's Externals to your Externals group

6. In your application target's Build Phases: Target Dependencies add the `Static Lib (iOS)` from the DTPDF sub project

7. If you build for Mac also add the `Static Library (Mac)` from the DTFoundation sub project

8. In your application's target Build Settings:
	- Add `$(PROJECT_DIR)` to `User Header Search Paths`, set to `recursive`
	- Set `Always Search User Paths` to `Yes`.
	- Add the `-ObjC` and `-all_load` flag to your app target's `Other Linker Flags`
   - If your app does not use ARC yet (but DTPDF and DTFoundation do) then you also need the `-fobjc-arc` linker flag.