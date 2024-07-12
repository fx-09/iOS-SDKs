#if !__has_include(<PassKitCore/PKAddIdentityDocumentConfiguration.h>) || PK_USE_PUBLIC_PASSKIT
//
//  PKAddIdentityDocumentConfiguration.h
//    PassKit
//
//  Created by Ryan Cook on 11/8/23.
//  Copyright © 2023 Apple, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <PassKit/PKAddPushablePassConfiguration.h>
#import <PassKit/PKAddSecureElementPassConfiguration.h>


API_AVAILABLE(ios(18.0)) API_UNAVAILABLE(watchos, tvos)
@interface PKIdentityDocumentMetadata: PKPushablePassMetadata
@end


API_AVAILABLE(ios(18.0)) API_UNAVAILABLE(watchos, tvos)
@interface PKJapanIndividualNumberCardMetadata: PKIdentityDocumentMetadata

/// Initialize with parameters configured by issuer's server to indicate the specific product instance to provision.
/// - Properties:
///   - provisioningCredentialIdentifier: Identifies this user's instance for provisioning.
///   - sharingInstanceIdentifier: A short lived token to prevent replay-ability.
///   - cardTemplateIdentifier: An identifier for a legacy product on our Apple Pay servers.
///   - preview: Object containing information to represent the pass to provision in our UI.
- (nonnull instancetype)initWithProvisioningCredentialIdentifier:(NSString * _Nonnull)credentialIdentifier
                                       sharingInstanceIdentifier:(NSString * _Nonnull)sharingInstanceIdentifier
                                          cardTemplateIdentifier:(NSString * _Nonnull)templateIdentifier
                                                         preview:(PKAddPassMetadataPreview * _Nonnull)preview;

/// Initialize with parameters configured by issuer's server to indicate the specific product instance to provision.
/// - Properties:
///   - provisioningCredentialIdentifier: Identifies this user's instance for provisioning.
///   - sharingInstanceIdentifier: A short lived token to prevent replay-ability.
///   - cardConfigurationIdentifier: An identifier for a product on our Apple Pay servers.
///   - preview: Object containing information to represent the pass to provision in our UI.
- (nonnull instancetype)initWithProvisioningCredentialIdentifier:(NSString * _Nonnull)credentialIdentifier
                                       sharingInstanceIdentifier:(NSString * _Nonnull)sharingInstanceIdentifier
                                     cardConfigurationIdentifier:(NSString * _Nonnull)templateIdentifier
                                                         preview:(PKAddPassMetadataPreview * _Nonnull)preview;

// Configuration Properties

/// Raw authentication password used to protect authentication functionality.
/// If configured in the pass, this functionality allows users to present their identity credentials to external parties.
@property (nonatomic, copy, nullable) NSString *authenticationPassword;

/// Raw signing password used to protect signing functionality.
/// If configured in the pass, this functionality allows users to digitally sign with external parties or print officially signed documents.
@property (nonatomic, copy, nullable) NSString *signingPassword;

// Display Properties

/// preview: A preview object containing the necessary information to represent the pass during provisioning.
@property (nonatomic, strong, readwrite, nonnull) PKAddPassMetadataPreview *preview;

@end

API_AVAILABLE(ios(18.0)) API_UNAVAILABLE(watchos, tvos)
@interface PKAddIdentityDocumentConfiguration : PKAddPushablePassConfiguration

/// Initialize identity document configuration with corresponding identity document metadata.
/// - Parameters:
///   - metadata: Set of configured metadata defining the required information to add the corresponding pass to Wallet.
///   - completion: Returns the identity document configuration if successful, otherwise returns an error.
+ (void)configurationForMetadata:(PKIdentityDocumentMetadata * _Nonnull)metadata
                      completion:(void(^_Nonnull)(PKAddIdentityDocumentConfiguration * _Nullable credentialConfiguration, NSError * _Nullable error))completion
NS_SWIFT_NAME(forMetadata(_:completion:));

- (null_unspecified instancetype)init NS_UNAVAILABLE;
+ (null_unspecified instancetype)new NS_UNAVAILABLE;

/// metadata: Set of configured metadata defining the required information to add the corresponding pass to Wallet.
@property (nonatomic, strong, readonly, nonnull) PKIdentityDocumentMetadata *metadata;

@end


#else
#import <TargetConditionals.h>
#import <PassKitCore/PKAddIdentityDocumentConfiguration.h>
#endif