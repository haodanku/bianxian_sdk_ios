#ifdef __OBJC__
#import <UIKit/UIKit.h>
#else
#ifndef FOUNDATION_EXPORT
#if defined(__cplusplus)
#define FOUNDATION_EXPORT extern "C"
#else
#define FOUNDATION_EXPORT extern
#endif
#endif
#endif

#import "Hdk.h"
#import "HDKError.h"

FOUNDATION_EXPORT double HdkVersionNumber;
FOUNDATION_EXPORT const unsigned char HdkVersionString[];

