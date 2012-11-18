/*
 Copyright 2011 Twitter, Inc.
 
 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this work except in compliance with the License.
 You may obtain a copy of the License in the LICENSE file, or at:
 
 http://www.apache.org/licenses/LICENSE-2.0
 
 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
 */

#import "TUIGeometry.h"
#import "NSShadow+TUIExtensions.h"

@interface NSBezierPath (TUIExtensions)

+ (NSBezierPath *)tui_bezierPathWithCGPath:(CGPathRef)pathRef;
- (CGPathRef)tui_CGPath CF_RETURNS_RETAINED;

- (void)fillWithInnerShadow:(NSShadow *)shadow;
- (void)drawBlurWithColor:(NSColor *)color radius:(CGFloat)radius;

+ (NSBezierPath *)bezierPathWithRoundedRect:(CGRect)rect
                          byRoundingCorners:(TUIRectCorner)corners
                                cornerRadii:(CGSize)cornerRadii;

- (void)strokeInside;
- (void)strokeInsideWithinRect:(NSRect)clipRect;

@end