#if (defined(USE_UIKIT_PUBLIC_HEADERS) && USE_UIKIT_PUBLIC_HEADERS) || !__has_include(<UIKitCore/UNNotificationResponse+UIKitAdditions.h>)
//
//  UNNotificationResponse+UIKitAdditions.h
//  UIKit
//
//  Copyright © 2019 Apple Inc. All rights reserved.
//

#import <UIKit/UIKitDefines.h>
#import <UserNotifications/UNNotificationResponse.h>

@class UIScene;

NS_HEADER_AUDIT_BEGIN(nullability, sendability)

API_AVAILABLE(macos(10.14), ios(10.0)) API_UNAVAILABLE(tvos, watchos)
UIKIT_EXTERN @interface UNNotificationResponse (UIKitAdditions)
// used to identify which UIScene UI to reflect the user's response to a notification on
@property (nullable, nonatomic, readonly) UIScene *targetScene NS_AVAILABLE_IOS(13_0); //  default nil
@end

NS_HEADER_AUDIT_END(nullability, sendability)

#else
#import <UIKitCore/UNNotificationResponse+UIKitAdditions.h>
#endif
