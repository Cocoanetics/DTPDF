//
//  DTPDFScanner.h
//  DTPDF
//
//  Created by Oliver Drobnik on 27.11.12.
//  Copyright (c) 2012 Cocoanetics. All rights reserved.
//

@interface DTPDFScanner : NSObject

+ (id)scannerWithCGPDFContentStream:(CGPDFContentStreamRef)contentStream;

/**
 scans the content stream
 @returns `YES` if the scanning was successful
 */
- (BOOL)scanContentStream;

/**
 Returns the reconstructed text boxes sorted from top to bottom
 */
- (NSArray *)textBoxes;

@end
