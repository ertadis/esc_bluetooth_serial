#ifndef ConnecterBlock_h
#define ConnecterBlock_h
#import <CoreBluetooth/CBPeripheral.h>

typedef enum : NSUInteger {
    NOT_FOUND_DEVICE,
    CONNECT_STATE_DISCONNECT,
    CONNECT_STATE_CONNECTING,
    CONNECT_STATE_CONNECTED,
    CONNECT_STATE_TIMEOUT,
    CONNECT_STATE_FAILT
}ConnectState;

/**Discover devices*/
typedef void(^DiscoverDevice)(CBPeripheral *_Nullable peripheral,NSDictionary<NSString *, id> * _Nullable advertisementData,NSNumber * _Nullable RSSI);
/**Bluetooth status update*/
typedef void(^UpdateState)(NSInteger state);
/**Connection Status*/
typedef void(^ConnectDeviceState)(ConnectState state);
/**Read data*/
typedef void(^ReadData)(NSData * _Nullable data);
/**Sending data progress ** Only for Bluetooth sending data*/
typedef void(^WriteProgress)(NSUInteger total,NSUInteger progress);
typedef void (^Error)(id _Nullable error);

#endif /* ConnecterBlock_h */
