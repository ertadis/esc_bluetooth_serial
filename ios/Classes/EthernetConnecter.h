#import "Connecter.h"

@interface EthernetConnecter :Connecter

@property(nonatomic,strong)NSString *ip;

@property(nonatomic,assign)int port;

-(void)connectIP:(NSString *)ip port:(int)port connectState:(void (^)(ConnectState state))connectState callback:(void(^)(NSData *data))callback;

-(void)connectIP:(NSString *)ip port:(int)port connectState:(void (^)(ConnectState))connectState;

@end
