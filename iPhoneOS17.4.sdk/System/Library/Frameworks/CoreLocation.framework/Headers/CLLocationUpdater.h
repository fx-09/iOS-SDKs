//
//  CLLocationUpdater.h
//  CoreLocation
//
//  Created by Cindy Clarissa on 11/29/22.
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CLAvailability.h>

NS_ASSUME_NONNULL_BEGIN
@class CLLocation;
struct CLLocationCoordinate2D;

/*
 *  CLLiveUpdateConfiguration
 *
 *  Discussion:
 *	    Specifies the types of locations being generated by
 *	    -[CLLocationUpdater liveUpdaterWithConfiguration:queue:handler:] or
 *	    -[CLLocationUpdater liveUpdaterWithQueue:handler:]
 */
API_AVAILABLE(ios(17.0), macos(14.0), watchos(10.0), tvos(17.0))
typedef NS_ENUM(NSInteger, CLLiveUpdateConfiguration) {
	CLLiveUpdateConfigurationDefault = 0,             // Default configuration
	CLLiveUpdateConfigurationAutomotiveNavigation,    // Configuration tuned for automotive navigation use cases
	CLLiveUpdateConfigurationOtherNavigation,         // Configuration tuned for other navigation use cases
	CLLiveUpdateConfigurationFitness,                 // Configuration tuned for fitness use cases
	CLLiveUpdateConfigurationAirborne,                // Configuration tuned for airborne use cases
} NS_REFINED_FOR_SWIFT;

/*
 *  CLUpdate
 *
 *  Discussion:
 *		Contains a possible location and related metadata. Delivered by
 *		CLLocationUpdater to its handler block.
 */
CL_EXTERN
API_AVAILABLE(ios(17.0), macos(14.0), watchos(10.0), tvos(17.0)) NS_REFINED_FOR_SWIFT
@interface CLUpdate : NSObject

/*
 *	isStationary
 *
 *  Discussion:
 *      Updates may stop flowing temporarily for many reasons such as
 *      the app is no longer authorized for locations or if its
 *      location becomes unknown.  If CoreLocation stops
 *      delivering updates because the device is stationary, then
 *      isStationary will be set to YES.  Otherwise it will be NO.
 *
 *      If isStationary is YES, then updates may be suspended until
 *      the user next moves, or their location becomes unknown.
 *
 */
#if defined(TARGET_OS_VISION) && TARGET_OS_VISION
@property (readonly) BOOL isStationary API_AVAILABLE(ios(17.0), macos(14.0), watchos(10.0), tvos(17.0), visionos(1.0));
#else
@property (readonly) BOOL isStationary API_AVAILABLE(ios(17.0), macos(14.0), watchos(10.0), tvos(17.0));
#endif

/*
 *	location
 *
 *  Discussion:
 *		Return the user's location if available, otherwise returns nil.
 *
 */
#if defined(TARGET_OS_VISION) && TARGET_OS_VISION
@property (nonatomic, readonly) CLLocation * _Nullable location API_AVAILABLE(ios(17.0), macos(14.0), watchos(10.0), tvos(17.0), visionos(1.0));
#else
@property (nonatomic, readonly) CLLocation * _Nullable location API_AVAILABLE(ios(17.0), macos(14.0), watchos(10.0), tvos(17.0));
#endif

@end


CL_EXTERN
API_AVAILABLE(ios(17.0), macos(14.0), watchos(10.0), tvos(17.0)) NS_REFINED_FOR_SWIFT
@interface CLLocationUpdater : NSObject
- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;

/*
 *  liveUpdaterWithQueue:handler:
 *
 *  Discussion:
 *      Returns a new CLLocationUpdater with the given queue and handler,
 *      using the default live update configuration.
 *
 *      queue: Specifies the queue to which the handler is submitted with each
 *          available update.
 *      handler: Specifies the block that will be invoked with each update.
 *
 *      CoreLocation will ensure the app has a few seconds of runtime to process
 *      each location update it is authorized to receive. If the app crashes,
 *      or exits for any reason while updates are flowing,
 *      it will be launched for the next update, which it may receive by
 *      calling this method again to express resumed interest.
 *      If this method is not called again, or the resulting updater
 *      is not resumed again, then CoreLocation will automatically stop the flow
 *      of updates.
 *
 */
+ (nullable instancetype)liveUpdaterWithQueue:(dispatch_queue_t)queue
									  handler:(void(^)(CLUpdate *_Nullable update))handler API_AVAILABLE(ios(17.0), macos(14.0), watchos(10.0), tvos(17.0)
#if defined(TARGET_OS_VISION) && TARGET_OS_VISION
, visionos(1.0)
#endif
) NS_REFINED_FOR_SWIFT;

/*
 *  liveUpdaterWithConfiguration:queue:handler:
 *
 *  Discussion:
 *      Returns a new CLLocationUpdater with the given a CLLiveUpdateConfiguration,
 *      queue and handler.
 *
 *      configuration: Specifies the live update configuration which should
 *          be used.
 *      queue: Specifies the queue to which the handler is submitted with each
 *          available update.
 *      handler: Specifies the block that will be invoked with each update.
 *
 *      CoreLocation will ensure the app has a few seconds of runtime to process
 *      each location update it is authorized to receive. If the app crashes,
 *      crashes, or exits for any reason while updates are flowing,
 *      it will be launched for the next update, which it may receive by
 *      calling this method again to express resumed interest.
 *      If this method is not called again, or the resulting updater
 *      is not resumed again, then CoreLocation will automatically stop the flow
 *      of updates.
 *
 */
+ (nullable instancetype)liveUpdaterWithConfiguration:(CLLiveUpdateConfiguration)configuration
												queue:(dispatch_queue_t)queue
											  handler:(void(^)(CLUpdate * _Nullable update))handler API_AVAILABLE(ios(17.0), macos(14.0), watchos(10.0), tvos(17.0)
#if defined(TARGET_OS_VISION) && TARGET_OS_VISION
, visionos(1.0)
#endif
) NS_REFINED_FOR_SWIFT;
																									
/*
*  resume
*
*  Discussion:
*    	Start delivery of Updates to the handler, or resume from where -pause
*	  	was called. -resume must be called to start the flow of updates when
*		a CLLocationUpdater is first obtained.
*/
#if defined(TARGET_OS_VISION) && TARGET_OS_VISION
- (void)resume API_AVAILABLE(ios(17.0), macos(14.0), watchos(10.0), tvos(17.0), tvos(17.0), visionos(1.0));
#else
- (void)resume API_AVAILABLE(ios(17.0), macos(14.0), watchos(10.0), tvos(17.0));
#endif

/*
*  pause
*
*  Discussion:
*      	Pause delivery of Updates to the handler, if they are started. If
*      	invoked from the configured queue, guarantees no further Update until
*      	-resume is called again. -resume can be used to restart location
*		updates where they were left off.
*
*/
#if defined(TARGET_OS_VISION) && TARGET_OS_VISION
- (void)pause API_AVAILABLE(ios(17.0), macos(14.0), watchos(10.0), tvos(17.0), visionos(1.0));
#else
- (void)pause API_AVAILABLE(ios(17.0), macos(14.0), watchos(10.0), tvos(17.0));
#endif

/*
*  invalidate
*
*  Discussion:
*      	Invalidate CLLocationUpdater instance. Any further message to CLLocationUpdater
*      	instance after invalidation results in no-op.
*
*/
#if defined(TARGET_OS_VISION) && TARGET_OS_VISION
- (void)invalidate API_AVAILABLE(ios(17.0), macos(14.0), watchos(10.0), visionos(1.0));
#else
- (void)invalidate API_AVAILABLE(ios(17.0), macos(14.0), watchos(10.0), tvos(17.0));
#endif

@end
NS_ASSUME_NONNULL_END