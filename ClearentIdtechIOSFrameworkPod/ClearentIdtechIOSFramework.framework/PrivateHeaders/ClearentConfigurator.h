//
//  ClearentConfigurator.h
//  ClearentIdtechIOSFramework
//
//  Created by David Higginbotham on 6/25/18.
//  Copyright © 2018 Clearent, L.L.C. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <IDTech/IDT_VP3300.h>
typedef enum{
    CLOCK_CONFIGURATION_SUCCESS,
    CLOCK_FAILED,
}CLOCK_CONFIGURATION_ERROR_CODE;

@interface ClearentConfigurator : NSObject

    @property(nonatomic) NSString *baseUrl;
    @property(nonatomic) NSString *publicKey;
    @property(nonatomic) SEL selector;
    @property(nonatomic) id callbackObject;
    @property (assign, getter=isConfigured) BOOL configured;

    - (id) init : (NSString*)clearentBaseUrl
        publicKey:(NSString*)publicKey
        callbackObject:(id)callbackObject
        withSelector:(SEL)selector
        sharedController:(IDT_VP3300*) sharedController;
    - (void) configure: (NSString*)kernelVersion deviceSerialNumber:(NSString*) deviceSerialNumber;
    - (void) configure: (NSDictionary*) jsonConfiguration;
    - (void) notify:(NSString*)message;
    - (NSData*) getClockDateAsYYYYMMDD;
    - (NSData*) getClockTimeAsHHMM;
@end
