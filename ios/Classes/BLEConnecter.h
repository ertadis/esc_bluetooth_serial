#import "Connecter.h"
#import <CoreBluetooth/CoreBluetooth.h>

@interface BLEConnecter :Connecter

@property(nonatomic,strong)CBCharacteristic * _Nullable airPatchChar;
@property(nonatomic,strong)CBCharacteristic * _Nullable transparentDataWriteChar;
@property(nonatomic,strong)CBCharacteristic * _Nullable transparentDataReadOrNotifyChar;
@property(nonatomic,strong)CBCharacteristic * _Nullable connectionParameterChar;

@property(nonatomic,strong)CBUUID * _Nullable transServiceUUID;
@property(nonatomic,strong)CBUUID * _Nullable transTxUUID;
@property(nonatomic,strong)CBUUID * _Nullable transRxUUID;
@property(nonatomic,strong)CBUUID * _Nullable disUUID1;
@property(nonatomic,strong)CBUUID * _Nullable disUUID2;
@property(nonatomic,strong)NSArray * _Nullable serviceUUID;

@property(nonatomic,copy)DiscoverDevice _Nullable discover;
@property(nonatomic,copy)UpdateState _Nullable updateState;
@property(nonatomic,copy)WriteProgress _Nullable writeProgress;


@property(nonatomic,assign)NSUInteger datagramSize;

@property(nonatomic,strong)CBPeripheral * _Nullable connPeripheral;

- (void)configureTransparentServiceUUID: (NSString *_Nullable)serviceUUID txUUID:(NSString *_Nullable)txUUID rxUUID:(NSString *_Nullable)rxUUID;

-(void)scanForPeripheralsWithServices:(nullable NSArray<CBUUID *> *)serviceUUIDs options:(nullable NSDictionary<NSString *, id> *)options discover:(void(^_Nullable)(CBPeripheral *_Nullable peripheral,NSDictionary<NSString *, id> *_Nullable advertisementData,NSNumber *_Nullable RSSI))discover;

-(void)stopScan;

-(void)didUpdateState:(void(^_Nullable)(NSInteger state))state;

-(void)connectPeripheral:(CBPeripheral *_Nullable)peripheral options:(nullable NSDictionary<NSString *,id> *)options timeout:(NSUInteger)timeout connectBlack:(void(^_Nullable)(ConnectState state)) connectState;

-(void)connectPeripheral:(CBPeripheral * _Nullable)peripheral options:(nullable NSDictionary<NSString *,id> *)options;

-(void)closePeripheral:(nonnull CBPeripheral *)peripheral;

-(void)write:(NSData *_Nullable)data progress:(void(^_Nullable)(NSUInteger total,NSUInteger progress))progress receCallBack:(void (^_Nullable)(NSData *_Nullable))callBack;

-(void)writeValue:(NSData *_Nullable)data forCharacteristic:(nonnull CBCharacteristic *)characteristic type:(CBCharacteristicWriteType)type;
@end
