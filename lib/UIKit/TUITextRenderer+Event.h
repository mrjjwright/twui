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

#import "TUITextRenderer.h"

@interface TUITextRenderer (Event)

- (CFIndex)stringIndexForPoint:(CGPoint)p;
- (CFIndex)stringIndexForEvent:(NSEvent *)event;
- (void)resetSelection;
- (CGRect)rectForCurrentSelection;

- (void)copy:(id)sender;

// Overridable methods used by subclasses to prepare
// for responder changes. It is advised to always call
// the super method after preparations are complete
// in the subclass- there might be heavy duty plumbing
// in the superclass. If you are directly subclassing
// TUITextRenderer, no super method calls are required.
- (void)prepareToBecomeFirstResponder;
- (void)prepareToResignFirstResponder;

@property (nonatomic, assign) id<TUITextRendererDelegate> delegate;

@end

@protocol TUITextRendererDelegate <NSObject>

@optional
- (NSArray *)activeRangesForTextRenderer:(TUITextRenderer *)t;

- (void)textRendererWillBecomeFirstResponder:(TUITextRenderer *)textRenderer;
- (void)textRendererDidBecomeFirstResponder:(TUITextRenderer *)textRenderer;
- (void)textRendererWillResignFirstResponder:(TUITextRenderer *)textRenderer;
- (void)textRendererDidResignFirstResponder:(TUITextRenderer *)textRenderer;

@end
